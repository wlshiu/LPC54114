/*
 * The Clear BSD License
 * Copyright (c) 2017, NXP Semiconductors, Inc.
 * All rights reserved.
 *
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted (subject to the limitations in the disclaimer below) provided
 * that the following conditions are met:
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

#include "fsl_debug_console.h"
#include "fsl_device_registers.h"
#include "fsl_spi.h"
#include "fsl_spi_dma.h"
#include "fsl_dma.h"
#include "board.h"
#include "pin_mux.h"
#include <stdbool.h>
/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define EXAMPLE_SPI_MASTER SPI3
#define EXAMPLE_SPI_MASTER_IRQ FLEXCOMM3_IRQn
#define EXAMPLE_SPI_MASTER_CLK_SRC kCLOCK_Flexcomm3
#define EXAMPLE_SPI_MASTER_CLK_FREQ CLOCK_GetFreq(kCLOCK_Flexcomm3)
#define EXAMPLE_SPI_SSEL 2
#define EXAMPLE_DMA DMA0
#define EXAMPLE_SPI_MASTER_RX_CHANNEL 6
#define EXAMPLE_SPI_MASTER_TX_CHANNEL 7
#define EXAMPLE_MASTER_SPI_SPOL kSPI_SpolActiveAllLow

#define TRANSFER_SIZE 64U /*! Transfer dataSize */

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
static void SPI_MasterUserCallback(SPI_Type *base, spi_dma_handle_t *handle, status_t status, void *userData);
static void EXAMPLE_MasterInit(void);
static void EXAMPLE_MasterDMASetup(void);
static void EXAMPLE_MasterStartDMATransfer(void);
static void EXAMPLE_TransferDataCheck(void);

/*******************************************************************************
 * Variables
 ******************************************************************************/
uint8_t masterRxData[TRANSFER_SIZE] = {0};
uint8_t masterTxData[TRANSFER_SIZE] = {0};

dma_handle_t masterTxHandle;
dma_handle_t masterRxHandle;

spi_dma_handle_t masterHandle;

volatile bool isTransferCompleted = false;

/*******************************************************************************
 * Code
 ******************************************************************************/
static void SPI_MasterUserCallback(SPI_Type *base, spi_dma_handle_t *handle, status_t status, void *userData)
{
    if (status == kStatus_Success)
    {
        isTransferCompleted = true;
    }
}

/*!
 * @brief Main function
 */
int main(void)
{
    /* Initialize board setting. */
    /* attach 12 MHz clock to FLEXCOMM0 (debug console) */
    CLOCK_AttachClk(kFRO12M_to_FLEXCOMM0);

    /* attach 12 MHz clock to SPI3 */
    CLOCK_AttachClk(kFRO12M_to_FLEXCOMM3);

    /* reset FLEXCOMM for SPI */
    RESET_PeripheralReset(kFC3_RST_SHIFT_RSTn);

    BOARD_InitPins();
    BOARD_BootClockFROHF48M();
    BOARD_InitDebugConsole();

    /* Print project information. */
    PRINTF("This is SPI DMA tranfer master example.\r\n");
    PRINTF("This example will communicate with another slave SPI on the other board.\r\n");
    PRINTF("Please start the slave board first!\r\n");

    /* Initialize SPI master with configuration. */
    EXAMPLE_MasterInit();

    /* Set up DMA for SPI master TX and RX channel. */
    EXAMPLE_MasterDMASetup();

    /* Prepare DMA and start SPI master transfer in DMA way. */
    EXAMPLE_MasterStartDMATransfer();

    /* Waiting for transmission complete and check if all data matched. */
    EXAMPLE_TransferDataCheck();

    /* De-initialzie the DMA instance. */
    DMA_Deinit(EXAMPLE_DMA);

    /* De-initialize the SPI instance. */
    SPI_Deinit(EXAMPLE_SPI_MASTER);

    while (1)
    {
    }
}

static void EXAMPLE_MasterInit(void)
{
    /* SPI init */
    uint32_t srcClock_Hz = 0U;
    spi_master_config_t masterConfig;
    srcClock_Hz = EXAMPLE_SPI_MASTER_CLK_FREQ;

    SPI_MasterGetDefaultConfig(&masterConfig);
    masterConfig.sselNum = (spi_ssel_t)EXAMPLE_SPI_SSEL;
    masterConfig.sselPol = (spi_spol_t)EXAMPLE_MASTER_SPI_SPOL;
    SPI_MasterInit(EXAMPLE_SPI_MASTER, &masterConfig, srcClock_Hz);
}

static void EXAMPLE_MasterDMASetup(void)
{
    /* DMA init */
    DMA_Init(EXAMPLE_DMA);
    /* Configure the DMA channel,priority and handle. */
    DMA_EnableChannel(EXAMPLE_DMA, EXAMPLE_SPI_MASTER_TX_CHANNEL);
    DMA_EnableChannel(EXAMPLE_DMA, EXAMPLE_SPI_MASTER_RX_CHANNEL);
    DMA_SetChannelPriority(EXAMPLE_DMA, EXAMPLE_SPI_MASTER_TX_CHANNEL, kDMA_ChannelPriority3);
    DMA_SetChannelPriority(EXAMPLE_DMA, EXAMPLE_SPI_MASTER_RX_CHANNEL, kDMA_ChannelPriority2);
    DMA_CreateHandle(&masterTxHandle, EXAMPLE_DMA, EXAMPLE_SPI_MASTER_TX_CHANNEL);
    DMA_CreateHandle(&masterRxHandle, EXAMPLE_DMA, EXAMPLE_SPI_MASTER_RX_CHANNEL);
}

static void EXAMPLE_MasterStartDMATransfer(void)
{
    spi_transfer_t masterXfer;
    uint32_t i = 0U;

    /* Set up the transfer data */
    for (i = 0U; i < TRANSFER_SIZE; i++)
    {
        /* SPI is configured for 8 bits transfer - set only lower 8 bits of buffers */
        masterTxData[i] = i % 256U;
        masterRxData[i] = 0U;
    }

    /* Set up handle for spi master */
    SPI_MasterTransferCreateHandleDMA(EXAMPLE_SPI_MASTER, &masterHandle, SPI_MasterUserCallback, NULL, &masterTxHandle,
                                      &masterRxHandle);

    /* Start master transfer */
    masterXfer.txData = (uint8_t *)&masterTxData;
    masterXfer.rxData = (uint8_t *)&masterRxData;
    masterXfer.dataSize = TRANSFER_SIZE * sizeof(masterTxData[0]);
    masterXfer.configFlags = kSPI_FrameAssert;

    if (kStatus_Success != SPI_MasterTransferDMA(EXAMPLE_SPI_MASTER, &masterHandle, &masterXfer))
    {
        PRINTF("There is an error when start SPI_MasterTransferDMA \r\n ");
    }
}

static void EXAMPLE_TransferDataCheck(void)
{
    uint32_t i = 0U, errorCount = 0U;

    /* Wait until transfer completed */
    while (!isTransferCompleted)
    {
    }

    PRINTF("\r\nThe received data are:");
    /*Check if the data is right*/
    for (i = 0; i < TRANSFER_SIZE; i++)
    {
        /* Print 16 numbers in a line */
        if ((i & 0x0FU) == 0U)
        {
            PRINTF("\r\n  ");
        }
        PRINTF("  0x%02X", masterRxData[i]);
        /* Check if data matched. */
        if (masterTxData[i] != masterRxData[i])
        {
            errorCount++;
        }
    }
    if (errorCount == 0)
    {
        PRINTF("\r\nSPI transfer all data matched! \r\n");
    }
    else
    {
        PRINTF("\r\nError occured in SPI transfer ! \r\n");
    }
}
