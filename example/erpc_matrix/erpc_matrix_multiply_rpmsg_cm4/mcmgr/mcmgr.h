/*
 * The Clear BSD License
 * Copyright (c) 2014-2016, Freescale Semiconductor, Inc.
 * Copyright 2016 NXP
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

#ifndef MCMGR_H
#define MCMGR_H

#include <stdbool.h>
#include <stdint.h>

/*!
 * @addtogroup mcmgr
 * @{
 */

/*! @brief Enumeration that defines MCMGR function return status codes. */
typedef enum _mcmgr_status
{
    /*! @brief Operation was successful. */
    kStatus_MCMGR_Success,
    /*! @brief Operation was not successful. */
    kStatus_MCMGR_Error,
    /*! @brief Function is not implemented. */
    kStatus_MCMGR_NotImplemented,
    /*! @brief Operation result not ready. */
    kStatus_MCMGR_NotReady

} mcmgr_status_t;

/*! @brief Enumeration that defines property of core. */
typedef enum _mcmgr_core_property
{
    /*! @brief Status of core read from hardware core status flag. */
    kMCMGR_CoreStatus,
    /*! @brief Type of Core. */
    kMCMGR_CoreType,
    /*! @brief Power Mode of Core - implementation is hardware-specific. */
    kMCMGR_CorePowerMode
} mcmgr_core_property_t;

/*! @brief Enumeration that defines property value of core type. */
typedef enum _mcmgr_core_type
{
    /*! @brief Cortex M0 */
    kMCMGR_CoreTypeCortexM0,
    /*! @brief Cortex M0+ */
    kMCMGR_CoreTypeCortexM0Plus,
    /*! @brief Cortex M4 */
    kMCMGR_CoreTypeCortexM4,
    /*! @brief Cortex M33 */
    kMCMGR_CoreTypeCortexM33
} mcmgr_core_type_t;

/*! @brief Enumeration that defines core. */
typedef enum _mcmgr_core
{
    /*! @brief Enum value for Core 0. */
    kMCMGR_Core0,
    /*! @brief Enum value for Core 1. */
    kMCMGR_Core1
} mcmgr_core_t;

/*! @brief Enumeration that defines start type. */
typedef enum _mcmgr_start_mode
{
    /*! @brief Enum value for starting synchronously. */
    kMCMGR_Start_Synchronous,
    /*! @brief Enum value for starting asynchronously. */
    kMCMGR_Start_Asynchronous

} mcmgr_start_mode_t;

/*! @brief Type definition of event types. */
typedef enum _mcmgr_event_type_t
{
    kMCMGR_RemoteCoreUpEvent = 1,
    kMCMGR_RemoteCoreDownEvent,
    kMCMGR_RemoteExceptionEvent,
    kMCMGR_StartupDataEvent,
    kMCMGR_FeedStartupDataEvent,
    kMCMGR_RemoteRPMsgEvent,
    kMCMGR_RemoteApplicationEvent,
    kMCMGR_EventTableLength
} mcmgr_event_type_t;

/*! @brief Type definition of event callback function pointer. */
typedef void (*mcmgr_event_callback_t)(uint16_t data, void *context);

/*! @brief Set to 1 to enable exception handling. */
#ifndef MCMGR_HANDLE_EXCEPTIONS
#define MCMGR_HANDLE_EXCEPTIONS (0)
#endif
/*!
 * @brief Version of MCMGR
 *
 * Version 1.0.0, for version 1.2.3 it will be 0x00010203
 */
enum mcmgr_version_enum
{
    kMCMGR_Version = 0x00040001
};

#if defined(__cplusplus)
extern "C" {
#endif // __cplusplus

/*!
 * @brief Initialize the multicore manager, early init.
 *
 * After calling this function, MCMGR_TriggerEvent() and/or MCMGR_Init() can be called.
 *
 * @return kStatus_MCMGR_Success on success or kStatus_MCMGR_Error on failure.
 */
mcmgr_status_t MCMGR_EarlyInit(void);

/*!
 * @brief Initialize the multicore manager
 *
 * After calling this function, all API can be used.
 *
 * @return kStatus_MCMGR_Success on success or kStatus_MCMGR_Error on failure.
 */
mcmgr_status_t MCMGR_Init(void);

/*!
 * @brief Start a selected core
 *
 * This function causes a selected core to initialize and start the code execution.
 * If the secondary core application boots from RAM, then there is a need to call the function,
 * which copies this app. Image to RAM prior this function.
 *
 * @param[in] coreNum Enum of the core to be started.
 * @param[in] bootAddress Boot address of the core to be started application.
 * @param[in] startupData Data which can be get by the other core on startup.
 * @param[in] mode Start mode, use kMCMGR_Start_Synchronous for synchronous mode (wait until the
 *            core is started), kMCMGR_Start_Asynchronous for asynchronous mode (do not wait).
 *
 * @return kStatus_MCMGR_Success on success or kStatus_MCMGR_Error on failure.
 */
mcmgr_status_t MCMGR_StartCore(mcmgr_core_t coreNum, void *bootAddress, uint32_t startupData, mcmgr_start_mode_t mode);

/*!
 * @brief Get startup data for the slave core.
 *
 * This function read startup data provided by the master core.
 * Use only on the slave core during the startup.
 *
 * @param[out] startupData Data to read by this function.
 *
 * @return kStatus_MCMGR_Success on success or kStatus_MCMGR_Error on failure.
 */
mcmgr_status_t MCMGR_GetStartupData(uint32_t *startupData);

/*!
 * @brief Stop a selected core
 *
 * This function causes a selected core to halt code execution.
 *
 * @param[in] coreNum Enum of core to be stopped.
 *
 * @return kStatus_MCMGR_Success on success or kStatus_MCMGR_Error on failure.
 */
mcmgr_status_t MCMGR_StopCore(mcmgr_core_t coreNum);

/*!
 * @brief Get version of MCMGR
 *
 * This function returns a number of MCMGR version.
 *
 * @return a number of MCMGR version.
 */
int32_t MCMGR_GetVersion(void);

/*!
 * @brief Get property of the CPU core
 *
 * This function provides the property of the CPU core.
 *
 * @param[in] coreNum Enum of core.
 * @param[in] property Requested property type.
 * @param[in,out] value Parameter for value of property.
 * @param[in,out] length Parameter for size of property value in bytes.
 *
 * @return kStatus_MCMGR_Success on success or kStatus_MCMGR_Error on failure.
 */
mcmgr_status_t MCMGR_GetCoreProperty(mcmgr_core_t coreNum,
                                     mcmgr_core_property_t property,
                                     void *value,
                                     uint32_t *length);

/*!
 * @brief Return the count of cores in a multicore system
 *
 * This function returns the count of cores in a multicore system.
 *
 * @return the count of cores in a system.
 */
uint32_t MCMGR_GetCoreCount(void);

/*!
 * @brief Get current CPU core
 *
 * This function returns enum of current core.
 *
 * @return Enum of current core.
 */
mcmgr_core_t MCMGR_GetCurrentCore(void);

/*!
 * @brief Register event handler
 *
 * This function registers an event handler.
 * for remote processor events handling.
 *
 * @param[in] type Type of the event.
 * @param[in] callback User callback.
 * @param[in] callbackData Data/context for user callback.
 *
 * @return kStatus_MCMGR_Success on success or kStatus_MCMGR_Error on failure.
 */
mcmgr_status_t MCMGR_RegisterEvent(mcmgr_event_type_t type, mcmgr_event_callback_t callback, void *callbackData);

/*!
 * @brief Trigger event handler
 *
 * This function triggers an event handler
 * on the remote core.
 *
 * @param[in] type Type of the event.
 * @param[in] eventData Data to send to remote core.
 *
 * @return kStatus_MCMGR_Success on success or kStatus_MCMGR_Error on failure.
 */
mcmgr_status_t MCMGR_TriggerEvent(mcmgr_event_type_t type, uint16_t eventData);

/*!
 * @brief Trigger event handler, force version
 *
 * This function triggers an event handler
 * on the remote core, force version that does not check the consumption of previously sent data.
 *
 * @param[in] type Type of the event.
 * @param[in] eventData Data to send to remote core.
 *
 * @return kStatus_MCMGR_Success on success or kStatus_MCMGR_Error on failure.
 */
mcmgr_status_t MCMGR_TriggerEventForce(mcmgr_event_type_t type, uint16_t eventData);

#if defined(__cplusplus)
}
#endif // __cplusplus

/*! @} */

#endif
