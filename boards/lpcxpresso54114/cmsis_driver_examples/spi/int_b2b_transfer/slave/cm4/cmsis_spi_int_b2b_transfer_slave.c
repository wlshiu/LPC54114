/*
 * The Clear BSD License
 * Copyright 2017 NXP
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

#include "fsl_device_registers.h"
#include "fsl_debug_console.h"
#include "fsl_spi_cmsis.h"
#include "board.h"

#include "pin_mux.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define DRIVER_SLAVE_SPI Driver_SPI3

#define TRANSFER_SIZE 64U /* Transfer dataSize */

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/* SPI user SlaveSignalEvent */
void SPI_SlaveSignalEvent_t(uint32_t event);

/*******************************************************************************
 * Variables
 ******************************************************************************/
uint8_t slaveRxData[TRANSFER_SIZE] = {0};
uint8_t slaveTxData[TRANSFER_SIZE] = {0};

volatile bool isTransferCompleted = false;
/*******************************************************************************
 * Code
 ******************************************************************************/

uint32_t SPI3_GetFreq(void)
{
    return CLOCK_GetFreq(kCLOCK_Flexcomm3);
}
void SPI_SlaveSignalEvent_t(uint32_t event)
{
    /* user code */
    isTransferCompleted = true;
}

/*!
 * @brief Main function
 */
int main(void)
{
    /* attach 12 MHz clock to FLEXCOMM0 (debug console) */
    CLOCK_AttachClk(BOARD_DEBUG_UART_CLK_ATTACH);

    /* attach 12 MHz clock to FLEXCOMM3 (SPI3 master) */
    CLOCK_AttachClk(kFRO12M_to_FLEXCOMM3);

    /* reset FLEXCOMM for SPI */
    RESET_PeripheralReset(kFC3_RST_SHIFT_RSTn);

    BOARD_InitPins();
    BOARD_BootClockFROHF48M();
    BOARD_InitDebugConsole();

    PRINTF("SPI CMSIS driver board to board interrupt example.\r\n");

    uint32_t i = 0U;
    uint32_t errorCount = 0U;

    /*SPI slave init*/
    DRIVER_SLAVE_SPI.Initialize(SPI_SlaveSignalEvent_t);
    DRIVER_SLAVE_SPI.PowerControl(ARM_POWER_FULL);
    DRIVER_SLAVE_SPI.Control(ARM_SPI_MODE_SLAVE, false);

    PRINTF("\r\n Slave example is running...\r\n");

    /* Reset the send and receive buffer */
    for (i = 0U; i < TRANSFER_SIZE; i++)
    {
        slaveRxData[i] = 0U;
        slaveTxData[i] = i % 256;
    }

    isTransferCompleted = false;
    /* Set slave transfer to receive and send data */
    DRIVER_SLAVE_SPI.Transfer(slaveTxData, slaveRxData, TRANSFER_SIZE);
    /* Wait until transfer completed */
    while (!isTransferCompleted)
    {
    }

    for (i = 0; i < TRANSFER_SIZE; i++)
    {
        if (slaveRxData[i] != i)
        {
            PRINTF("\n\rThe %d number is wrong! It is %dn\r", i, slaveRxData[i]);
            errorCount++;
        }
    }

    PRINTF("\r\n");
    if (errorCount == 0)
    {
        PRINTF("\r\n Slave receive:");
        for (i = 0; i < TRANSFER_SIZE; i++)
        {
            /* Print 16 numbers in a line */
            if ((i & 0x0FU) == 0U)
            {
                PRINTF("\r\n    ");
            }
            PRINTF(" %02X", slaveRxData[i]);
        }
        PRINTF("\r\n");
        PRINTF("Succeed!\n\r");
    }
    else
    {
        PRINTF("Error occurd in SPI transfer!\n\r");
    }
    while (1)
    {
    }
}
