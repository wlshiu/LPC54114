INCLUDE(CMakeForceCompiler)

# CROSS COMPILER SETTING
SET(CMAKE_SYSTEM_NAME Generic)
CMAKE_MINIMUM_REQUIRED (VERSION 2.6)

# THE VERSION NUMBER
SET (Tutorial_VERSION_MAJOR 1)
SET (Tutorial_VERSION_MINOR 0)

# ENABLE ASM
ENABLE_LANGUAGE(ASM)

SET(CMAKE_STATIC_LIBRARY_PREFIX)
SET(CMAKE_STATIC_LIBRARY_SUFFIX)

SET(CMAKE_EXECUTABLE_LIBRARY_PREFIX)
SET(CMAKE_EXECUTABLE_LIBRARY_SUFFIX)

 
# CURRENT DIRECTORY
SET(ProjDirPath ${CMAKE_CURRENT_SOURCE_DIR})


SET(CMAKE_ASM_FLAGS_DEBUG "${CMAKE_ASM_FLAGS_DEBUG} -DDEBUG")

SET(CMAKE_ASM_FLAGS_DEBUG "${CMAKE_ASM_FLAGS_DEBUG} -D__STARTUP_CLEAR_BSS")

SET(CMAKE_ASM_FLAGS_DEBUG "${CMAKE_ASM_FLAGS_DEBUG} -g")

SET(CMAKE_ASM_FLAGS_DEBUG "${CMAKE_ASM_FLAGS_DEBUG} -Wall")

SET(CMAKE_ASM_FLAGS_DEBUG "${CMAKE_ASM_FLAGS_DEBUG} -fno-common")

SET(CMAKE_ASM_FLAGS_DEBUG "${CMAKE_ASM_FLAGS_DEBUG} -ffunction-sections")

SET(CMAKE_ASM_FLAGS_DEBUG "${CMAKE_ASM_FLAGS_DEBUG} -fdata-sections")

SET(CMAKE_ASM_FLAGS_DEBUG "${CMAKE_ASM_FLAGS_DEBUG} -ffreestanding")

SET(CMAKE_ASM_FLAGS_DEBUG "${CMAKE_ASM_FLAGS_DEBUG} -fno-builtin")

SET(CMAKE_ASM_FLAGS_DEBUG "${CMAKE_ASM_FLAGS_DEBUG} -mthumb")

SET(CMAKE_ASM_FLAGS_DEBUG "${CMAKE_ASM_FLAGS_DEBUG} -mapcs")

SET(CMAKE_ASM_FLAGS_DEBUG "${CMAKE_ASM_FLAGS_DEBUG} -std=gnu99")

SET(CMAKE_ASM_FLAGS_DEBUG "${CMAKE_ASM_FLAGS_DEBUG} -mcpu=cortex-m4")

SET(CMAKE_ASM_FLAGS_DEBUG "${CMAKE_ASM_FLAGS_DEBUG} -mfloat-abi=hard")

SET(CMAKE_ASM_FLAGS_DEBUG "${CMAKE_ASM_FLAGS_DEBUG} -mfpu=fpv4-sp-d16")

SET(CMAKE_ASM_FLAGS_RELEASE "${CMAKE_ASM_FLAGS_RELEASE} -DNDEBUG")

SET(CMAKE_ASM_FLAGS_RELEASE "${CMAKE_ASM_FLAGS_RELEASE} -D__STARTUP_CLEAR_BSS")

SET(CMAKE_ASM_FLAGS_RELEASE "${CMAKE_ASM_FLAGS_RELEASE} -Wall")

SET(CMAKE_ASM_FLAGS_RELEASE "${CMAKE_ASM_FLAGS_RELEASE} -fno-common")

SET(CMAKE_ASM_FLAGS_RELEASE "${CMAKE_ASM_FLAGS_RELEASE} -ffunction-sections")

SET(CMAKE_ASM_FLAGS_RELEASE "${CMAKE_ASM_FLAGS_RELEASE} -fdata-sections")

SET(CMAKE_ASM_FLAGS_RELEASE "${CMAKE_ASM_FLAGS_RELEASE} -ffreestanding")

SET(CMAKE_ASM_FLAGS_RELEASE "${CMAKE_ASM_FLAGS_RELEASE} -fno-builtin")

SET(CMAKE_ASM_FLAGS_RELEASE "${CMAKE_ASM_FLAGS_RELEASE} -mthumb")

SET(CMAKE_ASM_FLAGS_RELEASE "${CMAKE_ASM_FLAGS_RELEASE} -mapcs")

SET(CMAKE_ASM_FLAGS_RELEASE "${CMAKE_ASM_FLAGS_RELEASE} -std=gnu99")

SET(CMAKE_ASM_FLAGS_RELEASE "${CMAKE_ASM_FLAGS_RELEASE} -mcpu=cortex-m4")

SET(CMAKE_ASM_FLAGS_RELEASE "${CMAKE_ASM_FLAGS_RELEASE} -mfloat-abi=hard")

SET(CMAKE_ASM_FLAGS_RELEASE "${CMAKE_ASM_FLAGS_RELEASE} -mfpu=fpv4-sp-d16")

SET(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -DDEBUG")

SET(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -DCORE1_IMAGE_COPY_TO_RAM")

SET(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -DCPU_LPC54114J256BD64_cm4")

SET(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -DMULTICORE_APP=1")

SET(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -g")

SET(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -O0")

SET(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -Wall")

SET(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -fno-common")

SET(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -ffunction-sections")

SET(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -fdata-sections")

SET(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -ffreestanding")

SET(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -fno-builtin")

SET(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -mthumb")

SET(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -mapcs")

SET(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -std=gnu99")

SET(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -mcpu=cortex-m4")

SET(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -mfloat-abi=hard")

SET(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -mfpu=fpv4-sp-d16")

SET(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -MMD")

SET(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -MP")

SET(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -DNDEBUG")

SET(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -DCORE1_IMAGE_COPY_TO_RAM")

SET(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -DCPU_LPC54114J256BD64_cm4")

SET(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -DMULTICORE_APP=1")

SET(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -Os")

SET(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -Wall")

SET(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -fno-common")

SET(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -ffunction-sections")

SET(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -fdata-sections")

SET(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -ffreestanding")

SET(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -fno-builtin")

SET(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -mthumb")

SET(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -mapcs")

SET(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -std=gnu99")

SET(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -mcpu=cortex-m4")

SET(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -mfloat-abi=hard")

SET(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -mfpu=fpv4-sp-d16")

SET(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -MMD")

SET(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -MP")

SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DDEBUG")

SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DCPU_LPC54114J256BD64_cm4")

SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")

SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0")

SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall")

SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fno-common")

SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -ffunction-sections")

SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fdata-sections")

SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -ffreestanding")

SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fno-builtin")

SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -mthumb")

SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -mapcs")

SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fno-rtti")

SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fno-exceptions")

SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -mcpu=cortex-m4")

SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -mfloat-abi=hard")

SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -mfpu=fpv4-sp-d16")

SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -MMD")

SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -MP")

SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -DNDEBUG")

SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -DCPU_LPC54114J256BD64_cm4")

SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Os")

SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall")

SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -fno-common")

SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -ffunction-sections")

SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -fdata-sections")

SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -ffreestanding")

SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -fno-builtin")

SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -mthumb")

SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -mapcs")

SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -fno-rtti")

SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -fno-exceptions")

SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -mcpu=cortex-m4")

SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -mfloat-abi=hard")

SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -mfpu=fpv4-sp-d16")

SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -MMD")

SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -MP")

SET(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} -g")

SET(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} --specs=nano.specs")

SET(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} --specs=nosys.specs")

SET(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} -Wall")

SET(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} -fno-common")

SET(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} -ffunction-sections")

SET(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} -fdata-sections")

SET(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} -ffreestanding")

SET(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} -fno-builtin")

SET(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} -mthumb")

SET(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} -mapcs")

SET(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} -Xlinker")

SET(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} --gc-sections")

SET(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} -Xlinker")

SET(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} -static")

SET(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} -Xlinker")

SET(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} -z")

SET(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} -Xlinker")

SET(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} muldefs")

SET(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} -mcpu=cortex-m4")

SET(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} -mfloat-abi=hard")

SET(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} -mfpu=fpv4-sp-d16")

SET(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} -Xlinker")

SET(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} --defsym=__use_shmem__=1")

SET(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} --specs=nano.specs")

SET(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} --specs=nosys.specs")

SET(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} -Wall")

SET(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} -fno-common")

SET(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} -ffunction-sections")

SET(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} -fdata-sections")

SET(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} -ffreestanding")

SET(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} -fno-builtin")

SET(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} -mthumb")

SET(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} -mapcs")

SET(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} -Xlinker")

SET(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} --gc-sections")

SET(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} -Xlinker")

SET(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} -static")

SET(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} -Xlinker")

SET(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} -z")

SET(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} -Xlinker")

SET(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} muldefs")

SET(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} -mcpu=cortex-m4")

SET(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} -mfloat-abi=hard")

SET(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} -mfpu=fpv4-sp-d16")

SET(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} -Xlinker")

SET(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} --defsym=__use_shmem__=1")

#include_directories(${ProjDirPath}/../../cm0plus/armgcc/debug)
include_directories(${ProjDirPath}/erpc)
include_directories(${ProjDirPath}/service)
include_directories(${ProjDirPath}/source)
include_directories(${ProjDirPath}/../erpc_matrix_multiply_rpmsg_cm0plus/debug)
include_directories(${ProjDirPath}/erpc/setup)
include_directories(${ProjDirPath}/startup)
include_directories(${ProjDirPath}/rpmsg_lite/env/bm)
include_directories(${ProjDirPath}/utilities)
include_directories(${ProjDirPath}/board)
include_directories(${ProjDirPath}/rpmsg_lite/porting)
include_directories(${ProjDirPath}/../erpc_matrix_multiply_rpmsg_cm0plus/release)
include_directories(${ProjDirPath}/erpc/infra)
include_directories(${ProjDirPath}/mcmgr)
include_directories(${ProjDirPath}/erpc/transports)
include_directories(${ProjDirPath}/rpmsg_lite)
include_directories(${ProjDirPath}/board/src)
include_directories(${ProjDirPath}/CMSIS)
include_directories(${ProjDirPath}/drivers)
include_directories(${ProjDirPath}/erpc/port)

#include_directories(${ProjDirPath}/../../cm0plus/armgcc/release)

#include_directories(${ProjDirPath}/../../../../../../CMSIS/Include)

#include_directories(${ProjDirPath}/../../../../../../devices)

#include_directories(${ProjDirPath}/../../../../../../devices/LPC54114)

#include_directories(${ProjDirPath}/../../../..)

#include_directories(${ProjDirPath}/..)

#include_directories(${ProjDirPath}/../..)

#include_directories(${ProjDirPath}/../../service)

#include_directories(${ProjDirPath}/../../../erpc_common)

#include_directories(${ProjDirPath}/../../../../../../middleware/multicore/mcmgr/src)

#include_directories(${ProjDirPath}/../../../../../../devices/LPC54114/drivers)

#include_directories(${ProjDirPath}/../../../../../../middleware/multicore/rpmsg_lite/lib/include/platform/lpc5411x)

#include_directories(${ProjDirPath}/../../../../../../middleware/multicore/rpmsg_lite/lib/include)

#include_directories(${ProjDirPath}/../../../../../../devices/LPC54114/utilities/io)

#include_directories(${ProjDirPath}/../../../../../../devices/LPC54114/utilities/str)

#include_directories(${ProjDirPath}/../../../../../../devices/LPC54114/utilities/log)

#include_directories(${ProjDirPath}/../../../../../../devices/LPC54114/utilities)

#include_directories(${ProjDirPath}/../../../../../../middleware/multicore/erpc/erpc_c/infra)

#include_directories(${ProjDirPath}/../../../../../../middleware/multicore/erpc/erpc_c/port)

#include_directories(${ProjDirPath}/../../../../../../middleware/multicore/erpc/erpc_c/setup)

#include_directories(${ProjDirPath}/../../../../../../middleware/multicore/erpc/erpc_c/transports)

#include_directories(${ProjDirPath}/../../../../../../middleware/multicore/erpc/erpc_c)

add_executable(erpc_matrix_multiply_rpmsg_cm4.elf 
"${ProjDirPath}/board/pin_mux.c"
"${ProjDirPath}/board/pin_mux.h"
"${ProjDirPath}/board/src/board.c"
"${ProjDirPath}/board/src/board.h"
"${ProjDirPath}/board/src/clock_config.c"
"${ProjDirPath}/board/src/clock_config.h"
"${ProjDirPath}/CMSIS/arm_common_tables.h"
"${ProjDirPath}/CMSIS/arm_const_structs.h"
"${ProjDirPath}/CMSIS/arm_math.h"
"${ProjDirPath}/CMSIS/cmsis_armcc.h"
"${ProjDirPath}/CMSIS/cmsis_armclang.h"
"${ProjDirPath}/CMSIS/cmsis_compiler.h"
"${ProjDirPath}/CMSIS/cmsis_gcc.h"
"${ProjDirPath}/CMSIS/cmsis_iccarm.h"
"${ProjDirPath}/CMSIS/cmsis_version.h"
"${ProjDirPath}/CMSIS/core_armv8mbl.h"
"${ProjDirPath}/CMSIS/core_armv8mml.h"
"${ProjDirPath}/CMSIS/core_cm0plus.h"
"${ProjDirPath}/CMSIS/core_cm4.h"
"${ProjDirPath}/CMSIS/fsl_device_registers.h"
"${ProjDirPath}/CMSIS/LPC54114_cm4.h"
"${ProjDirPath}/CMSIS/LPC54114_cm4_features.h"
"${ProjDirPath}/CMSIS/mpu_armv7.h"
"${ProjDirPath}/CMSIS/mpu_armv8.h"
"${ProjDirPath}/CMSIS/system_LPC54114_cm4.c"
"${ProjDirPath}/CMSIS/system_LPC54114_cm4.h"
"${ProjDirPath}/drivers/fsl_clock.c"
"${ProjDirPath}/drivers/fsl_clock.h"
"${ProjDirPath}/drivers/fsl_common.c"
"${ProjDirPath}/drivers/fsl_common.h"
"${ProjDirPath}/drivers/fsl_flexcomm.c"
"${ProjDirPath}/drivers/fsl_flexcomm.h"
"${ProjDirPath}/drivers/fsl_gpio.c"
"${ProjDirPath}/drivers/fsl_gpio.h"
"${ProjDirPath}/drivers/fsl_iocon.h"
"${ProjDirPath}/drivers/fsl_mailbox.h"
"${ProjDirPath}/drivers/fsl_power.c"
"${ProjDirPath}/drivers/fsl_power.h"
"${ProjDirPath}/drivers/fsl_reset.c"
"${ProjDirPath}/drivers/fsl_reset.h"
"${ProjDirPath}/drivers/fsl_usart.c"
"${ProjDirPath}/drivers/fsl_usart.h"
"${ProjDirPath}/erpc/erpc_error_handler.cpp"
"${ProjDirPath}/erpc/erpc_error_handler.h"
"${ProjDirPath}/erpc/infra/erpc_basic_codec.cpp"
"${ProjDirPath}/erpc/infra/erpc_basic_codec.h"
"${ProjDirPath}/erpc/infra/erpc_client_manager.cpp"
"${ProjDirPath}/erpc/infra/erpc_client_manager.h"
"${ProjDirPath}/erpc/infra/erpc_codec.h"
"${ProjDirPath}/erpc/infra/erpc_common.h"
"${ProjDirPath}/erpc/infra/erpc_crc16.cpp"
"${ProjDirPath}/erpc/infra/erpc_crc16.h"
"${ProjDirPath}/erpc/infra/erpc_manually_constructed.h"
"${ProjDirPath}/erpc/infra/erpc_message_buffer.cpp"
"${ProjDirPath}/erpc/infra/erpc_message_buffer.h"
"${ProjDirPath}/erpc/infra/erpc_message_loggers.cpp"
"${ProjDirPath}/erpc/infra/erpc_message_loggers.h"
"${ProjDirPath}/erpc/infra/erpc_static_queue.h"
"${ProjDirPath}/erpc/infra/erpc_transport.h"
"${ProjDirPath}/erpc/infra/erpc_version.h"
"${ProjDirPath}/erpc/port/erpc_config_internal.h"
"${ProjDirPath}/erpc/port/erpc_port.h"
"${ProjDirPath}/erpc/port/erpc_port_stdlib.cpp"
"${ProjDirPath}/erpc/setup/erpc_client_setup.cpp"
"${ProjDirPath}/erpc/setup/erpc_client_setup.h"
"${ProjDirPath}/erpc/setup/erpc_mbf_setup.h"
"${ProjDirPath}/erpc/setup/erpc_setup_mbf_rpmsg.cpp"
"${ProjDirPath}/erpc/setup/erpc_setup_rpmsg_lite_master.cpp"
"${ProjDirPath}/erpc/setup/erpc_transport_setup.h"
"${ProjDirPath}/erpc/transports/erpc_rpmsg_lite_base_transport.h"
"${ProjDirPath}/erpc/transports/erpc_rpmsg_lite_transport.cpp"
"${ProjDirPath}/erpc/transports/erpc_rpmsg_lite_transport.h"
"${ProjDirPath}/libs/libpower_cm4_hardabi.a"
"${ProjDirPath}/mcmgr/mcmgr.c"
"${ProjDirPath}/mcmgr/mcmgr.h"
"${ProjDirPath}/mcmgr/mcmgr_internal_core_api.h"
"${ProjDirPath}/mcmgr/mcmgr_internal_core_api_lpc54114.c"
"${ProjDirPath}/rpmsg_lite/env/bm/rpmsg_env.h"
"${ProjDirPath}/rpmsg_lite/env/bm/rpmsg_env_bm.c"
"${ProjDirPath}/rpmsg_lite/llist.c"
"${ProjDirPath}/rpmsg_lite/llist.h"
"${ProjDirPath}/rpmsg_lite/porting/rpmsg_platform.c"
"${ProjDirPath}/rpmsg_lite/porting/rpmsg_platform.h"
"${ProjDirPath}/rpmsg_lite/rpmsg_compiler.h"
"${ProjDirPath}/rpmsg_lite/rpmsg_default_config.h"
"${ProjDirPath}/rpmsg_lite/rpmsg_lite.c"
"${ProjDirPath}/rpmsg_lite/rpmsg_lite.h"
"${ProjDirPath}/rpmsg_lite/rpmsg_ns.c"
"${ProjDirPath}/rpmsg_lite/rpmsg_ns.h"
"${ProjDirPath}/rpmsg_lite/virtio_ring.h"
"${ProjDirPath}/rpmsg_lite/virtqueue.c"
"${ProjDirPath}/rpmsg_lite/virtqueue.h"
"${ProjDirPath}/service/erpc_matrix_multiply.erpc"
"${ProjDirPath}/service/erpc_matrix_multiply.h"
"${ProjDirPath}/service/erpc_matrix_multiply_client.cpp"
"${ProjDirPath}/source/erpc_config.h"
"${ProjDirPath}/source/incbin.S"
"${ProjDirPath}/source/main_core0.c"
"${ProjDirPath}/source/rpmsg_config.h"
"${ProjDirPath}/startup/startup_LPC54114_cm4.S"
"${ProjDirPath}/utilities/fsl_assert.c"
"${ProjDirPath}/utilities/fsl_debug_console.c"
"${ProjDirPath}/utilities/fsl_debug_console.h"
"${ProjDirPath}/utilities/fsl_debug_console_conf.h"
"${ProjDirPath}/utilities/fsl_io.c"
"${ProjDirPath}/utilities/fsl_io.h"
"${ProjDirPath}/utilities/fsl_log.c"
"${ProjDirPath}/utilities/fsl_log.h"
"${ProjDirPath}/utilities/fsl_str.c"
"${ProjDirPath}/utilities/fsl_str.h"
)


set(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} -T${ProjDirPath}/LPC54114J256_cm4_flash.ld -static")

set(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} -T${ProjDirPath}/LPC54114J256_cm4_flash.ld -static")

TARGET_LINK_LIBRARIES(erpc_matrix_multiply_rpmsg_cm4.elf -Wl,--start-group)
target_link_libraries(erpc_matrix_multiply_rpmsg_cm4.elf debug ${ProjDirPath}/libs/libpower_cm4_hardabi.a)

target_link_libraries(erpc_matrix_multiply_rpmsg_cm4.elf debug m)

target_link_libraries(erpc_matrix_multiply_rpmsg_cm4.elf debug c)

target_link_libraries(erpc_matrix_multiply_rpmsg_cm4.elf debug gcc)

target_link_libraries(erpc_matrix_multiply_rpmsg_cm4.elf debug nosys)

target_link_libraries(erpc_matrix_multiply_rpmsg_cm4.elf optimized ${ProjDirPath}/libs/libpower_cm4_hardabi.a)

target_link_libraries(erpc_matrix_multiply_rpmsg_cm4.elf optimized m)

target_link_libraries(erpc_matrix_multiply_rpmsg_cm4.elf optimized c)

target_link_libraries(erpc_matrix_multiply_rpmsg_cm4.elf optimized gcc)

target_link_libraries(erpc_matrix_multiply_rpmsg_cm4.elf optimized nosys)

#link_directories(${ProjDirPath}/../../../../../../devices/LPC54114/gcc)

link_directories(${ProjDirPath}/libs)


#link_directories(${ProjDirPath}/../../../../../../devices/LPC54114/gcc)


TARGET_LINK_LIBRARIES(erpc_matrix_multiply_rpmsg_cm4.elf -Wl,--end-group)

