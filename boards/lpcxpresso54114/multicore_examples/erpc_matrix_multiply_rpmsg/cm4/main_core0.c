/*
 * The Clear BSD License
 * Copyright (c) 2015, 2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted (subject to the limitations in the disclaimer below) provided
 *  that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of the copyright holder nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * NO EXPRESS OR IMPLIED LICENSES TO ANY PARTY'S PATENT RIGHTS ARE GRANTED BY THIS LICENSE.
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "board.h"
#include "rpmsg_lite.h"
#include "erpc_client_setup.h"
#include "erpc_error_handler.h"
#include "erpc_matrix_multiply.h"
#include "fsl_debug_console.h"
#include <stdlib.h>
#include "mcmgr.h"

#include "fsl_common.h"
#include "pin_mux.h"
#include "fsl_gpio.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define ERPC_TRANSPORT_RPMSG_LITE_LINK_ID (RL_PLATFORM_LPC5411x_M4_M0_LINK_ID)

#define BUTTON_INIT() GPIO_PinInit(GPIO, BOARD_SW2_GPIO_PORT, BOARD_SW2_GPIO_PIN, &button_config)
#define IS_BUTTON_PRESSED() !GPIO_PinRead(GPIO, BOARD_SW2_GPIO_PORT, BOARD_SW2_GPIO_PIN)

/* Address of RAM, where the image for core1 should be copied */
#define CORE1_BOOT_ADDRESS (void *)0x20010000

#if defined(__CC_ARM)
extern uint32_t Image$$CORE1_REGION$$Base;
extern uint32_t Image$$CORE1_REGION$$Length;
#define CORE1_IMAGE_START &Image$$CORE1_REGION$$Base
#elif defined(__ICCARM__)
extern unsigned char core1_image_start[];
#define CORE1_IMAGE_START core1_image_start
#elif defined(__GNUC__)
extern const char m0_image_start[];
extern const char *m0_image_end;
extern int m0_image_size;
#define CORE1_IMAGE_START ((void *)m0_image_start)
#define CORE1_IMAGE_SIZE ((void *)m0_image_size)
#endif

extern char rpmsg_lite_base[];

#define MATRIX_ITEM_MAX_VALUE 50
#define APP_ERPC_READY_EVENT_DATA (1)

/*******************************************************************************
 * Variables
 ******************************************************************************/

extern bool g_erpc_error_occurred;
volatile uint16_t eRPCReadyEventData = 0;

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

#ifdef CORE1_IMAGE_COPY_TO_RAM
uint32_t get_core1_image_size(void);
#endif

/*******************************************************************************
 * Code
 ******************************************************************************/

#ifdef CORE1_IMAGE_COPY_TO_RAM
uint32_t get_core1_image_size()
{
    uint32_t core1_image_size;
#if defined(__CC_ARM)
    core1_image_size = (uint32_t)&Image$$CORE1_REGION$$Length;
#elif defined(__ICCARM__)
#pragma section = "__sec_core"
    core1_image_size = (uint32_t)__section_end("__sec_core") - (uint32_t)&core1_image_start;
#elif defined(__GNUC__)
    core1_image_size = (uint32_t)m0_image_size;
#endif
    return core1_image_size;
}
#endif

/*!
 * @brief Fill matrices by random values
 */
static void fill_matrices(Matrix matrix1_ptr, Matrix matrix2_ptr)
{
    int32_t a, b;

    /* Fill both matrices by random values */
    for (a = 0; a < matrix_size; ++a)
    {
        for (b = 0; b < matrix_size; ++b)
        {
            matrix1_ptr[a][b] = rand() % MATRIX_ITEM_MAX_VALUE;
            matrix2_ptr[a][b] = rand() % MATRIX_ITEM_MAX_VALUE;
        }
    }
}

/*!
 * @brief Printing a matrix to the console
 */
static void print_matrix(Matrix matrix_ptr)
{
    int32_t a, b;

    for (a = 0; a < matrix_size; ++a)
    {
        for (b = 0; b < matrix_size; ++b)
        {
            PRINTF("%4i ", (int)(matrix_ptr[a][b]));
        }
        PRINTF("\r\n");
    }
}

/*!
 * @brief eRPC server side ready event handler
 */
static void eRPCReadyEventHandler(uint16_t eventData, void *context)
{
    eRPCReadyEventData = eventData;
}

/*!
 * @brief Application-specific implementation of the SystemInitHook() weak function.
 */
void SystemInitHook(void)
{
    /* Initialize MCMGR - low level multicore management library. Call this
       function as close to the reset entry as possible to allow CoreUp event
       triggering. The SystemInitHook() weak function overloading is used in this
       application. */
    MCMGR_EarlyInit();
}

/*!
 * @brief Main function
 */
int main()
{
    Matrix matrix1 = {0}, matrix2 = {0}, result_matrix = {0};

    /* attach 12 MHz clock to FLEXCOMM0 (debug console) */
    CLOCK_AttachClk(kFRO12M_to_FLEXCOMM0);

    /* enable clock for GPIO*/
    CLOCK_EnableClock(kCLOCK_Gpio0);
    CLOCK_EnableClock(kCLOCK_Gpio1);

    BOARD_InitPins_Core0();
    BOARD_BootClockFROHF48M();
    BOARD_InitDebugConsole();

    /* Define the init structure for the input switch pin */
    gpio_pin_config_t button_config = {
        kGPIO_DigitalInput, 0,
    };

    /* Configure BUTTON */
    BUTTON_INIT();

    PRINTF("\r\nPrimary core started\r\n");

#ifdef CORE1_IMAGE_COPY_TO_RAM
    /* Calculate size of the image */
    uint32_t core1_image_size;
    core1_image_size = get_core1_image_size();
    PRINTF("Copy CORE1 image to address: 0x%x, size: %d\n", CORE1_BOOT_ADDRESS, core1_image_size);

    /* Copy application from FLASH to RAM */
    memcpy(CORE1_BOOT_ADDRESS, (void *)CORE1_IMAGE_START, core1_image_size);
#endif

    /* Initialize MCMGR before calling its API */
    MCMGR_Init();

    /* Register the application event before starting the secondary core */
    MCMGR_RegisterEvent(kMCMGR_RemoteApplicationEvent, eRPCReadyEventHandler, NULL);

    /* Boot source for Core 1 */
    MCMGR_StartCore(kMCMGR_Core1, CORE1_BOOT_ADDRESS, (uint32_t)rpmsg_lite_base, kMCMGR_Start_Synchronous);

    /* Wait until the secondary core application signals the rpmsg remote has been initialized and is ready to
     * communicate. */
    while (APP_ERPC_READY_EVENT_DATA != eRPCReadyEventData)
    {
    };

    /* RPMsg-Lite transport layer initialization */
    erpc_transport_t transport;

    transport = erpc_transport_rpmsg_lite_master_init(100, 101, ERPC_TRANSPORT_RPMSG_LITE_LINK_ID);

    /* MessageBufferFactory initialization */
    erpc_mbf_t message_buffer_factory;
    message_buffer_factory = erpc_mbf_rpmsg_init(transport);

    /* eRPC client side initialization */
    erpc_client_init(transport, message_buffer_factory);

    /* Set default error handler */
    erpc_client_set_error_handler(erpc_error_handler);

    /* Fill both matrices by random values */
    fill_matrices(matrix1, matrix2);

    /* Print both matrices on the console */
    PRINTF("\r\nMatrix #1");
    PRINTF("\r\n=========\r\n");
    print_matrix(matrix1);

    PRINTF("\r\nMatrix #2");
    PRINTF("\r\n=========\r\n");
    print_matrix(matrix2);

    while (1)
    {
        PRINTF("\r\neRPC request is sent to the server\r\n");

        erpcMatrixMultiply(matrix1, matrix2, result_matrix);

        /* Check if some error occured in eRPC */
        if (g_erpc_error_occurred)
        {
            /* Exit program loop */
            break;
        }

        PRINTF("\r\nResult matrix");
        PRINTF("\r\n=============\r\n");
        print_matrix(result_matrix);

        PRINTF("\r\nPress the SW2 button to initiate the next matrix multiplication\r\n");
        /* Check for SW2 button push. Pin is grounded when button is pushed. */
        while (1 != IS_BUTTON_PRESSED())
        {
        }

        /* Wait for 200ms to eliminate the button glitch */
        env_sleep_msec(200);

        /* Fill both matrices by random values */
        fill_matrices(matrix1, matrix2);

        /* Print both matrices on the console */
        PRINTF("\r\nMatrix #1");
        PRINTF("\r\n=========\r\n");
        print_matrix(matrix1);

        PRINTF("\r\nMatrix #2");
        PRINTF("\r\n=========\r\n");
        print_matrix(matrix2);
    }
    while (1)
    {
    }
}
