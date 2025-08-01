# CROSS COMPILER SETTING
set(CMAKE_SYSTEM_NAME Generic)
cmake_minimum_required(VERSION 3.10.0)

if (NOT DEFINED SdkRootDirPath)
    SET(SdkRootDirPath ${CMAKE_CURRENT_LIST_DIR})
endif()

include(${CMAKE_CURRENT_LIST_DIR}/config.cmake)
include(${SdkRootDirPath}/cmake/toolchain/toolchain.cmake)

# THE VERSION NUMBER
SET (MCUXPRESSO_CMAKE_FORMAT_MAJOR_VERSION 2)
SET (MCUXPRESSO_CMAKE_FORMAT_MINOR_VERSION 0)

include(ide_overrides.cmake OPTIONAL)

if(CMAKE_SCRIPT_MODE_FILE)
  message("${MCUXPRESSO_CMAKE_FORMAT_MAJOR_VERSION}")
  return()
endif()


set(CMAKE_EXECUTABLE_LIBRARY_PREFIX)
set(CMAKE_EXECUTABLE_LIBRARY_SUFFIX)

# CURRENT DIRECTORY
set(ProjDirPath ${CMAKE_CURRENT_SOURCE_DIR})

set(EXECUTABLE_OUTPUT_PATH ${ProjDirPath}/${CMAKE_BUILD_TYPE})
set(LIBRARY_OUTPUT_PATH ${ProjDirPath}/${CMAKE_BUILD_TYPE})


project(wireless_uart_freertos)

enable_language(ASM)

set(MCUX_BUILD_TYPES debug)

set(MCUX_SDK_PROJECT_NAME wireless_uart_freertos.elf)

include(${ProjDirPath}/flags.cmake)

add_executable(${MCUX_SDK_PROJECT_NAME} 
"${SdkRootDirPath}/devices/MCX/MCXW/MCXW236/system_MCXW236.c"
"${SdkRootDirPath}/devices/MCX/MCXW/MCXW236/gcc/startup_MCXW236.S"
"${SdkRootDirPath}/devices/MCX/MCXW/MCXW236/drivers/fsl_clock.c"
"${SdkRootDirPath}/devices/MCX/MCXW/MCXW236/drivers/fsl_reset.c"
"${SdkRootDirPath}/devices/MCX/MCXW/MCXW236/drivers/fsl_rom_api.c"
"${SdkRootDirPath}/devices/MCX/MCXW/MCXW236/drivers/timer_manager_mcxw23/fsl_component_timer_manager.c"
"${SdkRootDirPath}/examples/_boards/frdmmcxw23/board.c"
"${SdkRootDirPath}/examples/_common/project_segments/wireless/mcxw23/components/board_comp.c"
"${SdkRootDirPath}/examples/_common/project_segments/wireless/mcxw23/app_common/hardware_init.c"
"${SdkRootDirPath}/examples/_common/project_segments/wireless/wireless_mcu/app_common/app_services_init.c"
"${SdkRootDirPath}/examples/_common/project_segments/wireless/mcxw23/app_common/app_ble_init.c"
"${SdkRootDirPath}/examples/_boards/frdmmcxw23/clock_config.c"
"${SdkRootDirPath}/examples/_boards/frdmmcxw23/wireless_examples/pin_mux.c"
"${SdkRootDirPath}/drivers/common/fsl_common.c"
"${SdkRootDirPath}/drivers/common/fsl_common_arm.c"
"${SdkRootDirPath}/drivers/ctimer/fsl_ctimer.c"
"${SdkRootDirPath}/drivers/flexcomm/fsl_flexcomm.c"
"${SdkRootDirPath}/drivers/inputmux/fsl_inputmux.c"
"${SdkRootDirPath}/drivers/lpc_gpio/fsl_gpio.c"
"${SdkRootDirPath}/drivers/pint/fsl_pint.c"
"${SdkRootDirPath}/drivers/trng/fsl_trng.c"
"${SdkRootDirPath}/drivers/flexcomm/i2c/fsl_i2c.c"
"${SdkRootDirPath}/drivers/flexcomm/spi/fsl_spi.c"
"${SdkRootDirPath}/drivers/flexcomm/usart/fsl_usart.c"
"${SdkRootDirPath}/drivers/dma/fsl_dma.c"
"${SdkRootDirPath}/drivers/cmsis/fsl_i2c_cmsis.c"
"${SdkRootDirPath}/drivers/cmsis/fsl_spi_cmsis.c"
"${SdkRootDirPath}/drivers/cmsis/fsl_usart_cmsis.c"
"${SdkRootDirPath}/components/button/fsl_component_button.c"
"${SdkRootDirPath}/components/debug_console_lite/fsl_debug_console.c"
"${SdkRootDirPath}/components/gpio/fsl_adapter_lpc_gpio.c"
"${SdkRootDirPath}/components/internal_flash/fsl_adapter_mcxw_flash.c"
"${SdkRootDirPath}/components/led/fsl_component_led.c"
"${SdkRootDirPath}/components/lists/fsl_component_generic_list.c"
"${SdkRootDirPath}/components/log/fsl_component_log.c"
"${SdkRootDirPath}/components/mem_manager/fsl_component_mem_manager_light.c"
"${SdkRootDirPath}/components/messaging/fsl_component_messaging.c"
"${SdkRootDirPath}/components/misc_utilities/fsl_syscall_stub.c"
"${SdkRootDirPath}/components/misc_utilities/fsl_sbrk.c"
"${SdkRootDirPath}/components/misc_utilities/fsl_memcpy.S"
"${SdkRootDirPath}/components/osa/fsl_os_abstraction_free_rtos.c"
"${SdkRootDirPath}/components/panic/fsl_component_panic.c"
"${SdkRootDirPath}/components/reset/fsl_adapter_reset.c"
"${SdkRootDirPath}/components/serial_manager/fsl_component_serial_manager.c"
"${SdkRootDirPath}/components/serial_manager/fsl_component_serial_port_uart.c"
"${SdkRootDirPath}/components/str/fsl_str.c"
"${SdkRootDirPath}/components/timer/fsl_adapter_ctimer.c"
"${SdkRootDirPath}/components/uart/fsl_adapter_usart.c"
"${SdkRootDirPath}/components/format/fsl_format.c"
"${SdkRootDirPath}/rtos/freertos/freertos-kernel/croutine.c"
"${SdkRootDirPath}/rtos/freertos/freertos-kernel/event_groups.c"
"${SdkRootDirPath}/rtos/freertos/freertos-kernel/list.c"
"${SdkRootDirPath}/rtos/freertos/freertos-kernel/queue.c"
"${SdkRootDirPath}/rtos/freertos/freertos-kernel/stream_buffer.c"
"${SdkRootDirPath}/rtos/freertos/freertos-kernel/tasks.c"
"${SdkRootDirPath}/rtos/freertos/freertos-kernel/timers.c"
"${SdkRootDirPath}/rtos/freertos/freertos-kernel/portable/GCC/ARM_CM33_NTZ/non_secure/mpu_wrappers_v2_asm.c"
"${SdkRootDirPath}/rtos/freertos/freertos-kernel/portable/GCC/ARM_CM33_NTZ/non_secure/port.c"
"${SdkRootDirPath}/rtos/freertos/freertos-kernel/portable/GCC/ARM_CM33_NTZ/non_secure/portasm.c"
"${SdkRootDirPath}/sensors/nmh1000_drv.c"
"${SdkRootDirPath}/interfaces/register_io_i2c.c"
"${SdkRootDirPath}/interfaces/register_io_spi.c"
"${SdkRootDirPath}/interfaces/sensor_io_i2c.c"
"${SdkRootDirPath}/interfaces/sensor_io_spi.c"
"${SdkRootDirPath}/middleware/wireless/framework/Common/rtos/freertos/fwk_freertos_utils.c"
"${SdkRootDirPath}/middleware/wireless/framework/Common/rtos/freertos/heap_mem_manager.c"
"${SdkRootDirPath}/middleware/wireless/framework/services/FunctionLib/FunctionLib.c"
"${SdkRootDirPath}/middleware/wireless/framework/services/ModuleInfo/ModuleInfo.c"
"${SdkRootDirPath}/middleware/wireless/framework/services/NVM/Source/NV_Flash.c"
"${SdkRootDirPath}/middleware/wireless/framework/platform/mcxw23/fwk_platform.c"
"${SdkRootDirPath}/middleware/wireless/framework/platform/mcxw23/fwk_platform_sensors.c"
"${SdkRootDirPath}/middleware/wireless/framework/services/SecLib_RNG/SecLib_aes_mmo.c"
"${SdkRootDirPath}/middleware/wireless/framework/services/SecLib_RNG/SecLib.c"
"${SdkRootDirPath}/middleware/wireless/framework/services/SecLib_RNG/RNG.c"
"${SdkRootDirPath}/middleware/wireless/framework/services/Sensors/sensors.c"
"${SdkRootDirPath}/middleware/wireless/bluetooth/port/fwk_generic_list.c"
"${SdkRootDirPath}/middleware/wireless/bluetooth/port/fwk_messaging.c"
"${SdkRootDirPath}/middleware/wireless/bluetooth/port/fwk_os_abs.c"
"${SdkRootDirPath}/middleware/wireless/bluetooth/port/fwk_timer_manager.c"
"${SdkRootDirPath}/middleware/wireless/bluetooth/host/config/ble_globals.c"
"${SdkRootDirPath}/middleware/wireless/bluetooth/application/common/ble_host_tasks.c"
"${SdkRootDirPath}/middleware/wireless/bluetooth/application/common/ble_conn_manager.c"
"${SdkRootDirPath}/middleware/wireless/bluetooth/application/common/ble_service_discovery.c"
"${SdkRootDirPath}/middleware/wireless/bluetooth/application/common/gatt_db/gatt_database.c"
"${SdkRootDirPath}/middleware/wireless/bluetooth/profiles/battery/battery_service.c"
"${SdkRootDirPath}/middleware/wireless/bluetooth/profiles/wireless_uart/wireless_uart_service.c"
"${SdkRootDirPath}/middleware/wireless/ble_controller/src/snps/sdk_integration/ble_controller.c"
"${SdkRootDirPath}/middleware/wireless/ble_controller/src/snps/sdk_integration/ble_controller_debug.c"
"${SdkRootDirPath}/middleware/wireless/ble_controller/src/snps/sdk_integration/os_interface.c"
"${SdkRootDirPath}/middleware/wireless/ble_controller/src/snps/sdk_integration/nxp_hoststack_adapter/nxp_hoststack_adapter.c"
"${SdkRootDirPath}/middleware/wireless/ble_controller/src/snps/sdk_integration/controller_api/controller_api.c"
"${SdkRootDirPath}/middleware/wireless/bluetooth/application/common/freertos/main.c"
"${SdkRootDirPath}/middleware/wireless/bluetooth/application/common/app_conn.c"
"${SdkRootDirPath}/middleware/wireless/bluetooth/application/common/ble_init.c"
"${SdkRootDirPath}/middleware/wireless/bluetooth/application/common/app_advertiser.c"
"${SdkRootDirPath}/middleware/wireless/bluetooth/application/common/app_connection.c"
"${SdkRootDirPath}/middleware/wireless/bluetooth/application/common/app_scanner.c"
"${SdkRootDirPath}/middleware/wireless/bluetooth/application/common/app_nvm.c"
"${SdkRootDirPath}/middleware/wireless/bluetooth/application/common/app_low_power.c"
"${SdkRootDirPath}/middleware/wireless/bluetooth/examples/w_uart/app_config.c"
"${SdkRootDirPath}/middleware/wireless/bluetooth/examples/w_uart/wireless_uart.c"
"${SdkRootDirPath}/utils/systick_utils.c"
"${SdkRootDirPath}/FreeRTOSConfig_Gen.h"
"${SdkRootDirPath}/mcux_config.h"
"${SdkRootDirPath}/devices/MCX/MCXW/MCXW236/fsl_device_registers.h"
"${SdkRootDirPath}/devices/MCX/MCXW/MCXW236/MCXW236.h"
"${SdkRootDirPath}/devices/MCX/MCXW/MCXW236/MCXW236_features.h"
"${SdkRootDirPath}/devices/MCX/MCXW/MCXW236/MCXW236_COMMON.h"
"${SdkRootDirPath}/devices/MCX/MCXW/periph4/PERI_AHB_SECURE_CTRL.h"
"${SdkRootDirPath}/devices/MCX/MCXW/periph4/PERI_ANACTRL.h"
"${SdkRootDirPath}/devices/MCX/MCXW/periph4/PERI_CASPER.h"
"${SdkRootDirPath}/devices/MCX/MCXW/periph4/PERI_CDOG.h"
"${SdkRootDirPath}/devices/MCX/MCXW/periph4/PERI_CRC.h"
"${SdkRootDirPath}/devices/MCX/MCXW/periph4/PERI_CTIMER.h"
"${SdkRootDirPath}/devices/MCX/MCXW/periph4/PERI_DBGMAILBOX.h"
"${SdkRootDirPath}/devices/MCX/MCXW/periph4/PERI_DMA.h"
"${SdkRootDirPath}/devices/MCX/MCXW/periph4/PERI_FLASH_CFPA.h"
"${SdkRootDirPath}/devices/MCX/MCXW/periph4/PERI_FLASH_CMPA.h"
"${SdkRootDirPath}/devices/MCX/MCXW/periph4/PERI_FLASH_KEY_STORE.h"
"${SdkRootDirPath}/devices/MCX/MCXW/periph4/PERI_FLASH_NMPA.h"
"${SdkRootDirPath}/devices/MCX/MCXW/periph4/PERI_FLASH_ROMPATCH.h"
"${SdkRootDirPath}/devices/MCX/MCXW/periph4/PERI_FLEXCOMM.h"
"${SdkRootDirPath}/devices/MCX/MCXW/periph4/PERI_FMU.h"
"${SdkRootDirPath}/devices/MCX/MCXW/periph4/PERI_GINT.h"
"${SdkRootDirPath}/devices/MCX/MCXW/periph4/PERI_GPIO.h"
"${SdkRootDirPath}/devices/MCX/MCXW/periph4/PERI_HASHCRYPT.h"
"${SdkRootDirPath}/devices/MCX/MCXW/periph4/PERI_I2C.h"
"${SdkRootDirPath}/devices/MCX/MCXW/periph4/PERI_INPUTMUX.h"
"${SdkRootDirPath}/devices/MCX/MCXW/periph4/PERI_IOCON.h"
"${SdkRootDirPath}/devices/MCX/MCXW/periph4/PERI_MRT.h"
"${SdkRootDirPath}/devices/MCX/MCXW/periph4/PERI_NPX.h"
"${SdkRootDirPath}/devices/MCX/MCXW/periph4/PERI_OSTIMER.h"
"${SdkRootDirPath}/devices/MCX/MCXW/periph4/PERI_PINT.h"
"${SdkRootDirPath}/devices/MCX/MCXW/periph4/PERI_PLU.h"
"${SdkRootDirPath}/devices/MCX/MCXW/periph4/PERI_PMC.h"
"${SdkRootDirPath}/devices/MCX/MCXW/periph4/PERI_PUF.h"
"${SdkRootDirPath}/devices/MCX/MCXW/periph4/PERI_PUF_SRAM_CTRL.h"
"${SdkRootDirPath}/devices/MCX/MCXW/periph4/PERI_RADIO.h"
"${SdkRootDirPath}/devices/MCX/MCXW/periph4/PERI_ROMCP.h"
"${SdkRootDirPath}/devices/MCX/MCXW/periph4/PERI_RTC.h"
"${SdkRootDirPath}/devices/MCX/MCXW/periph4/PERI_SCT.h"
"${SdkRootDirPath}/devices/MCX/MCXW/periph4/PERI_SPI.h"
"${SdkRootDirPath}/devices/MCX/MCXW/periph4/PERI_SPIFI.h"
"${SdkRootDirPath}/devices/MCX/MCXW/periph4/PERI_SYSCON.h"
"${SdkRootDirPath}/devices/MCX/MCXW/periph4/PERI_SYSCTL.h"
"${SdkRootDirPath}/devices/MCX/MCXW/periph4/PERI_TRNG.h"
"${SdkRootDirPath}/devices/MCX/MCXW/periph4/PERI_USART.h"
"${SdkRootDirPath}/devices/MCX/MCXW/periph4/PERI_UTICK.h"
"${SdkRootDirPath}/devices/MCX/MCXW/periph4/PERI_WWDT.h"
"${SdkRootDirPath}/devices/MCX/MCXW/MCXW236/system_MCXW236.h"
"${SdkRootDirPath}/devices/MCX/MCXW/MCXW236/drivers/fsl_clock.h"
"${SdkRootDirPath}/devices/MCX/MCXW/MCXW236/drivers/fsl_inputmux_connections.h"
"${SdkRootDirPath}/devices/MCX/MCXW/MCXW236/drivers/fsl_power.h"
"${SdkRootDirPath}/devices/MCX/MCXW/MCXW236/drivers/fsl_system.h"
"${SdkRootDirPath}/devices/MCX/MCXW/MCXW236/drivers/fsl_reset.h"
"${SdkRootDirPath}/devices/MCX/MCXW/MCXW236/drivers/fsl_rom_api.h"
"${SdkRootDirPath}/devices/MCX/MCXW/MCXW236/drivers/fsl_iap.h"
"${SdkRootDirPath}/devices/MCX/MCXW/MCXW236/drivers/fsl_iap_ffr.h"
"${SdkRootDirPath}/devices/MCX/MCXW/MCXW236/drivers/fsl_iap_kbp.h"
"${SdkRootDirPath}/devices/MCX/MCXW/MCXW236/drivers/timer_manager_mcxw23/fsl_component_timer_manager.h"
"${SdkRootDirPath}/arch/arm/CMSIS/Core/Include/cmsis_compiler.h"
"${SdkRootDirPath}/arch/arm/CMSIS/Core/Include/cmsis_version.h"
"${SdkRootDirPath}/arch/arm/CMSIS/Core/Include/cmsis_gcc.h"
"${SdkRootDirPath}/arch/arm/CMSIS/Core/Include/m-profile/cmsis_gcc_m.h"
"${SdkRootDirPath}/arch/arm/CMSIS/Core/Include/core_cm33.h"
"${SdkRootDirPath}/arch/arm/CMSIS/Core/Include/m-profile/armv8m_mpu.h"
"${SdkRootDirPath}/arch/arm/CMSIS/Core/Include/tz_context.h"
"${SdkRootDirPath}/examples/_boards/frdmmcxw23/wireless_examples/board_platform.h"
"${SdkRootDirPath}/examples/_boards/frdmmcxw23/wireless_examples/pin_mux.h"
"${SdkRootDirPath}/examples/_boards/frdmmcxw23/board.h"
"${SdkRootDirPath}/examples/_common/project_segments/wireless/mcxw23/components/board_comp.h"
"${SdkRootDirPath}/examples/_common/project_segments/wireless/wireless_mcu/app_common/app.h"
"${SdkRootDirPath}/examples/_boards/frdmmcxw23/clock_config.h"
"${SdkRootDirPath}/examples/_boards/frdmmcxw23/issdk_hal.h"
"${SdkRootDirPath}/examples/_boards/frdmmcxw23/nmh1000_board.h"
"${SdkRootDirPath}/examples/_boards/frdmmcxw23/frdmmcxw23x.h"
"${SdkRootDirPath}/examples/_boards/frdmmcxw23/RTE_Device.h"
"${SdkRootDirPath}/CMSIS/cmsis_compiler.h"
"${SdkRootDirPath}/CMSIS/cmsis_gcc.h"
"${SdkRootDirPath}/CMSIS/cmsis_version.h"
"${SdkRootDirPath}/CMSIS/core_cm33.h"
"${SdkRootDirPath}/CMSIS/tz_context.h"
"${SdkRootDirPath}/CMSIS/m-profile/armv8m_mpu.h"
"${SdkRootDirPath}/CMSIS/m-profile/cmsis_gcc_m.h"
"${SdkRootDirPath}/CMSIS_driver/Include/Driver_Common.h"
"${SdkRootDirPath}/CMSIS_driver/Include/Driver_I2C.h"
"${SdkRootDirPath}/CMSIS_driver/Include/Driver_SPI.h"
"${SdkRootDirPath}/CMSIS_driver/Include/Driver_USART.h"
"${SdkRootDirPath}/drivers/common/fsl_common.h"
"${SdkRootDirPath}/drivers/common/fsl_common_arm.h"
"${SdkRootDirPath}/drivers/ctimer/fsl_ctimer.h"
"${SdkRootDirPath}/drivers/flexcomm/fsl_flexcomm.h"
"${SdkRootDirPath}/drivers/inputmux/fsl_inputmux.h"
"${SdkRootDirPath}/drivers/lpc_gpio/fsl_gpio.h"
"${SdkRootDirPath}/drivers/lpc_iocon/fsl_iocon.h"
"${SdkRootDirPath}/drivers/pint/fsl_pint.h"
"${SdkRootDirPath}/drivers/trng/fsl_trng.h"
"${SdkRootDirPath}/drivers/flexcomm/i2c/fsl_i2c.h"
"${SdkRootDirPath}/drivers/flexcomm/spi/fsl_spi.h"
"${SdkRootDirPath}/drivers/flexcomm/usart/fsl_usart.h"
"${SdkRootDirPath}/drivers/dma/fsl_dma.h"
"${SdkRootDirPath}/drivers/cmsis/fsl_i2c_cmsis.h"
"${SdkRootDirPath}/drivers/cmsis/fsl_spi_cmsis.h"
"${SdkRootDirPath}/drivers/cmsis/fsl_usart_cmsis.h"
"${SdkRootDirPath}/components/button/fsl_component_button.h"
"${SdkRootDirPath}/components/debug_console_lite/fsl_debug_console.h"
"${SdkRootDirPath}/components/gpio/fsl_adapter_gpio.h"
"${SdkRootDirPath}/components/internal_flash/fsl_adapter_flash.h"
"${SdkRootDirPath}/components/led/fsl_component_led.h"
"${SdkRootDirPath}/components/lists/fsl_component_generic_list.h"
"${SdkRootDirPath}/components/log/fsl_component_log.h"
"${SdkRootDirPath}/components/log/fsl_component_log_config.h"
"${SdkRootDirPath}/components/mem_manager/fsl_component_mem_manager.h"
"${SdkRootDirPath}/components/messaging/fsl_component_messaging.h"
"${SdkRootDirPath}/components/osa/config/fsl_os_abstraction_config.h"
"${SdkRootDirPath}/components/osa/fsl_os_abstraction_free_rtos.h"
"${SdkRootDirPath}/components/osa/fsl_os_abstraction.h"
"${SdkRootDirPath}/components/panic/fsl_component_panic.h"
"${SdkRootDirPath}/components/reset/fsl_adapter_reset.h"
"${SdkRootDirPath}/components/serial_manager/fsl_component_serial_manager.h"
"${SdkRootDirPath}/components/serial_manager/fsl_component_serial_port_internal.h"
"${SdkRootDirPath}/components/serial_manager/fsl_component_serial_port_uart.h"
"${SdkRootDirPath}/components/str/fsl_str.h"
"${SdkRootDirPath}/components/timer/fsl_adapter_timer.h"
"${SdkRootDirPath}/components/timer_manager/fsl_component_timer_manager.h"
"${SdkRootDirPath}/components/uart/fsl_adapter_uart.h"
"${SdkRootDirPath}/components/format/fsl_format.h"
"${SdkRootDirPath}/rtos/freertos/freertos-kernel/include/atomic.h"
"${SdkRootDirPath}/rtos/freertos/freertos-kernel/include/croutine.h"
"${SdkRootDirPath}/rtos/freertos/freertos-kernel/include/deprecated_definitions.h"
"${SdkRootDirPath}/rtos/freertos/freertos-kernel/include/event_groups.h"
"${SdkRootDirPath}/rtos/freertos/freertos-kernel/include/FreeRTOS.h"
"${SdkRootDirPath}/rtos/freertos/freertos-kernel/include/list.h"
"${SdkRootDirPath}/rtos/freertos/freertos-kernel/include/message_buffer.h"
"${SdkRootDirPath}/rtos/freertos/freertos-kernel/include/mpu_prototypes.h"
"${SdkRootDirPath}/rtos/freertos/freertos-kernel/include/mpu_syscall_numbers.h"
"${SdkRootDirPath}/rtos/freertos/freertos-kernel/include/mpu_wrappers.h"
"${SdkRootDirPath}/rtos/freertos/freertos-kernel/include/portable.h"
"${SdkRootDirPath}/rtos/freertos/freertos-kernel/include/projdefs.h"
"${SdkRootDirPath}/rtos/freertos/freertos-kernel/include/queue.h"
"${SdkRootDirPath}/rtos/freertos/freertos-kernel/include/semphr.h"
"${SdkRootDirPath}/rtos/freertos/freertos-kernel/include/stack_macros.h"
"${SdkRootDirPath}/rtos/freertos/freertos-kernel/include/StackMacros.h"
"${SdkRootDirPath}/rtos/freertos/freertos-kernel/include/stream_buffer.h"
"${SdkRootDirPath}/rtos/freertos/freertos-kernel/include/task.h"
"${SdkRootDirPath}/rtos/freertos/freertos-kernel/include/timers.h"
"${SdkRootDirPath}/rtos/freertos/freertos-kernel/portable/GCC/ARM_CM33_NTZ/non_secure/portasm.h"
"${SdkRootDirPath}/rtos/freertos/freertos-kernel/portable/GCC/ARM_CM33_NTZ/non_secure/portmacro.h"
"${SdkRootDirPath}/rtos/freertos/freertos-kernel/portable/GCC/ARM_CM33_NTZ/non_secure/portmacrocommon.h"
"${SdkRootDirPath}/rtos/freertos/freertos-kernel/include/freertos_tasks_c_additions.h"
"${SdkRootDirPath}/sensors/nmh1000_drv.h"
"${SdkRootDirPath}/sensors/nmh1000.h"
"${SdkRootDirPath}/sensors/nmh1000_mag_wakeup.h"
"${SdkRootDirPath}/interfaces/register_io_i2c.h"
"${SdkRootDirPath}/interfaces/register_io_spi.h"
"${SdkRootDirPath}/interfaces/sensor_io_i2c.h"
"${SdkRootDirPath}/interfaces/sensor_io_spi.h"
"${SdkRootDirPath}/interfaces/sensor_drv.h"
"${SdkRootDirPath}/middleware/wireless/framework/Common/EmbeddedTypes.h"
"${SdkRootDirPath}/middleware/wireless/framework/Common/fwk_hal_macros.h"
"${SdkRootDirPath}/middleware/wireless/framework/Common/fwk_errno.h"
"${SdkRootDirPath}/middleware/wireless/framework/services/DBG/fwk_debug.h"
"${SdkRootDirPath}/middleware/wireless/framework/Common/rtos/freertos/fwk_freertos_utils.h"
"${SdkRootDirPath}/middleware/wireless/framework/services/FunctionLib/FunctionLib.h"
"${SdkRootDirPath}/middleware/wireless/framework/services/ModuleInfo/ModuleInfo.h"
"${SdkRootDirPath}/middleware/wireless/framework/services/NVM/Interface/NVM_Interface.h"
"${SdkRootDirPath}/middleware/wireless/framework/services/NVM/Source/NV_Flash.h"
"${SdkRootDirPath}/middleware/wireless/framework/platform/mcxw23/configs/fwk_config.h"
"${SdkRootDirPath}/middleware/wireless/framework/platform/mcxw23/fwk_platform_definitions.h"
"${SdkRootDirPath}/middleware/wireless/framework/platform/include/fwk_platform_rng.h"
"${SdkRootDirPath}/middleware/wireless/framework/platform/wireless_mcu/fwk_platform.h"
"${SdkRootDirPath}/middleware/wireless/framework/platform/wireless_mcu/fwk_platform_ics.h"
"${SdkRootDirPath}/middleware/wireless/framework/platform/wireless_mcu/fwk_platform_ble.h"
"${SdkRootDirPath}/middleware/wireless/framework/platform/wireless_mcu/fwk_platform_sensors.h"
"${SdkRootDirPath}/middleware/wireless/framework/services/SecLib_RNG/SecLib.h"
"${SdkRootDirPath}/middleware/wireless/framework/services/SecLib_RNG/SecLib_ecp256.h"
"${SdkRootDirPath}/middleware/wireless/framework/services/SecLib_RNG/CryptoLibSW.h"
"${SdkRootDirPath}/middleware/wireless/framework/services/SecLib_RNG/RNG_Interface.h"
"${SdkRootDirPath}/middleware/wireless/framework/services/Sensors/sensors.h"
"${SdkRootDirPath}/middleware/wireless/bluetooth/host/interface/att_callbacks.h"
"${SdkRootDirPath}/middleware/wireless/bluetooth/host/interface/att_errors.h"
"${SdkRootDirPath}/middleware/wireless/bluetooth/host/interface/att_params.h"
"${SdkRootDirPath}/middleware/wireless/bluetooth/host/interface/att_types.h"
"${SdkRootDirPath}/middleware/wireless/bluetooth/host/interface/ble_constants.h"
"${SdkRootDirPath}/middleware/wireless/bluetooth/host/interface/ble_general.h"
"${SdkRootDirPath}/middleware/wireless/bluetooth/host/interface/ble_host_tasks.h"
"${SdkRootDirPath}/middleware/wireless/bluetooth/host/interface/ble_sig_defines.h"
"${SdkRootDirPath}/middleware/wireless/bluetooth/host/interface/ble_utils.h"
"${SdkRootDirPath}/middleware/wireless/bluetooth/host/interface/gap_interface.h"
"${SdkRootDirPath}/middleware/wireless/bluetooth/host/interface/gap_ids_interface.h"
"${SdkRootDirPath}/middleware/wireless/bluetooth/host/interface/gap_types.h"
"${SdkRootDirPath}/middleware/wireless/bluetooth/host/interface/gatt_client_interface.h"
"${SdkRootDirPath}/middleware/wireless/bluetooth/host/interface/gatt_database.h"
"${SdkRootDirPath}/middleware/wireless/bluetooth/host/interface/gatt_db_app_interface.h"
"${SdkRootDirPath}/middleware/wireless/bluetooth/host/interface/gatt_db_att_interface.h"
"${SdkRootDirPath}/middleware/wireless/bluetooth/host/interface/gatt_db_dynamic.h"
"${SdkRootDirPath}/middleware/wireless/bluetooth/host/interface/gatt_interface.h"
"${SdkRootDirPath}/middleware/wireless/bluetooth/host/interface/gatt_server_interface.h"
"${SdkRootDirPath}/middleware/wireless/bluetooth/host/interface/gatt_types.h"
"${SdkRootDirPath}/middleware/wireless/bluetooth/host/interface/hci_interface.h"
"${SdkRootDirPath}/middleware/wireless/bluetooth/host/interface/hci_types.h"
"${SdkRootDirPath}/middleware/wireless/bluetooth/host/interface/l2ca_cb_interface.h"
"${SdkRootDirPath}/middleware/wireless/bluetooth/host/interface/l2ca_interface.h"
"${SdkRootDirPath}/middleware/wireless/bluetooth/host/interface/l2ca_types.h"
"${SdkRootDirPath}/middleware/wireless/bluetooth/host/interface/vendor_debug_commands.h"
"${SdkRootDirPath}/middleware/wireless/bluetooth/port/fwk_generic_list.h"
"${SdkRootDirPath}/middleware/wireless/bluetooth/port/fwk_mem_manager.h"
"${SdkRootDirPath}/middleware/wireless/bluetooth/port/fwk_messaging.h"
"${SdkRootDirPath}/middleware/wireless/bluetooth/port/fwk_os_abs.h"
"${SdkRootDirPath}/middleware/wireless/bluetooth/port/fwk_panic.h"
"${SdkRootDirPath}/middleware/wireless/bluetooth/port/fwk_timer_manager.h"
"${SdkRootDirPath}/middleware/wireless/bluetooth/port/fwk_seclib.h"
"${SdkRootDirPath}/middleware/wireless/bluetooth/host/config/ble_config.h"
"${SdkRootDirPath}/middleware/wireless/bluetooth/application/common/ble_host_task_config.h"
"${SdkRootDirPath}/middleware/wireless/bluetooth/application/common/ble_conn_manager.h"
"${SdkRootDirPath}/middleware/wireless/bluetooth/application/common/ble_service_discovery.h"
"${SdkRootDirPath}/middleware/wireless/bluetooth/application/common/gatt_db/macros/gatt_alloc_x.h"
"${SdkRootDirPath}/middleware/wireless/bluetooth/application/common/gatt_db/macros/gatt_db_macros.h"
"${SdkRootDirPath}/middleware/wireless/bluetooth/application/common/gatt_db/macros/gatt_db_x_macros.h"
"${SdkRootDirPath}/middleware/wireless/bluetooth/application/common/gatt_db/macros/gatt_decl_x.h"
"${SdkRootDirPath}/middleware/wireless/bluetooth/application/common/gatt_db/macros/gatt_enum_x.h"
"${SdkRootDirPath}/middleware/wireless/bluetooth/application/common/gatt_db/macros/gatt_init_x.h"
"${SdkRootDirPath}/middleware/wireless/bluetooth/application/common/gatt_db/macros/gatt_size_x.h"
"${SdkRootDirPath}/middleware/wireless/bluetooth/application/common/gatt_db/macros/gatt_uuid_decl_x.h"
"${SdkRootDirPath}/middleware/wireless/bluetooth/application/common/gatt_db/macros/gatt_uuid_def_x.h"
"${SdkRootDirPath}/middleware/wireless/bluetooth/application/common/gatt_db/gatt_db_handles.h"
"${SdkRootDirPath}/middleware/wireless/bluetooth/application/common/ieee11073.h"
"${SdkRootDirPath}/middleware/wireless/bluetooth/profiles/battery/battery_interface.h"
"${SdkRootDirPath}/middleware/wireless/bluetooth/profiles/wireless_uart/wireless_uart_interface.h"
"${SdkRootDirPath}/middleware/wireless/ble_controller/interface/snps_controller/sdk_integration/ble_controller.h"
"${SdkRootDirPath}/middleware/wireless/ble_controller/interface/snps_controller/sdk_integration/ble_controller_lowlevel.h"
"${SdkRootDirPath}/middleware/wireless/ble_controller/interface/snps_controller/ble_controller/hci.h"
"${SdkRootDirPath}/middleware/wireless/ble_controller/interface/snps_controller/ble_controller/ll_intf.h"
"${SdkRootDirPath}/middleware/wireless/ble_controller/interface/snps_controller/ble_controller/ll_error.h"
"${SdkRootDirPath}/middleware/wireless/ble_controller/interface/snps_controller/shrd_utils/bsp.h"
#"${SdkRootDirPath}/middleware/wireless/ble_controller/interface/snps_controller/shrd_utils/_40nm_reg_files/DWC_ble154combo.h"
#"${SdkRootDirPath}/middleware/wireless/ble_controller/interface/snps_controller/shrd_utils/common_types.h"
"${SdkRootDirPath}/middleware/wireless/ble_controller/interface/snps_controller/shrd_utils/event_manager.h"
#"${SdkRootDirPath}/middleware/wireless/ble_controller/interface/snps_controller/shrd_utils/ll_fw_config.h"
#"${SdkRootDirPath}/middleware/wireless/ble_controller/interface/snps_controller/shrd_utils/ll_mem.h"
#"${SdkRootDirPath}/middleware/wireless/ble_controller/interface/snps_controller/shrd_utils/mem_intf.h"
"${SdkRootDirPath}/middleware/wireless/ble_controller/interface/snps_controller/shrd_utils/os_wrapper.h"
#"${SdkRootDirPath}/middleware/wireless/ble_controller/interface/snps_controller/shrd_utils/power_table.h"
#"${SdkRootDirPath}/middleware/wireless/ble_controller/interface/snps_controller/shrd_utils/hci_transport.h"
"${SdkRootDirPath}/middleware/wireless/ble_controller/interface/snps_controller/sdk_integration/nxp_hoststack_adapter/nxp_hoststack_adapter.h"
"${SdkRootDirPath}/middleware/wireless/ble_controller/interface/controller_api.h"
"${SdkRootDirPath}/middleware/wireless/ble_controller/interface/snps_controller/sdk_integration/controller_api/controller_interface.h"
"${SdkRootDirPath}/middleware/wireless/bluetooth/boards/frdmmcxw23/app_preinclude_common.h"
"${SdkRootDirPath}/middleware/wireless/bluetooth/application/common/freertos/FreeRTOSConfig.h"
"${SdkRootDirPath}/middleware/wireless/bluetooth/application/common/app_conn.h"
"${SdkRootDirPath}/middleware/wireless/bluetooth/application/common/ble_init.h"
"${SdkRootDirPath}/middleware/wireless/bluetooth/application/common/app_advertiser.h"
"${SdkRootDirPath}/middleware/wireless/bluetooth/application/common/app_scanner.h"
"${SdkRootDirPath}/middleware/wireless/bluetooth/examples/w_uart/gatt_db.h"
"${SdkRootDirPath}/middleware/wireless/bluetooth/examples/w_uart/gatt_uuid128.h"
"${SdkRootDirPath}/middleware/wireless/bluetooth/examples/w_uart/wireless_uart.h"
"${SdkRootDirPath}/utils/systick_utils.h"
"${SdkRootDirPath}/middleware/wireless/bluetooth/boards/frdmmcxw23/bluetooth/w_uart/app_preinclude.h"
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PRIVATE
    ${ProjDirPath}/.
    ${SdkRootDirPath}/devices/MCX/MCXW/MCXW236
    ${SdkRootDirPath}/devices/MCX/MCXW/periph4
    ${SdkRootDirPath}/devices/MCX/MCXW/MCXW236/drivers
    ${SdkRootDirPath}/devices/MCX/MCXW/MCXW236/drivers/timer_manager_mcxw23
    ${SdkRootDirPath}/arch/arm/CMSIS/Core/Include
    ${SdkRootDirPath}/arch/arm/CMSIS/Core/Include/m-profile
    ${SdkRootDirPath}/examples/_boards/frdmmcxw23
    ${SdkRootDirPath}/examples/_common/project_segments/wireless/mcxw23/components
    ${SdkRootDirPath}/examples/_common/project_segments/wireless/wireless_mcu/app_common
    ${SdkRootDirPath}/examples/_boards/frdmmcxw23/wireless_examples
    ${SdkRootDirPath}/CMSIS_driver/Include
    ${SdkRootDirPath}/drivers/common
    ${SdkRootDirPath}/drivers/ctimer
    ${SdkRootDirPath}/drivers/flexcomm
    ${SdkRootDirPath}/drivers/inputmux
    ${SdkRootDirPath}/drivers/lpc_gpio
    ${SdkRootDirPath}/drivers/lpc_iocon
    ${SdkRootDirPath}/drivers/pint
    ${SdkRootDirPath}/drivers/trng
    ${SdkRootDirPath}/drivers/flexcomm/i2c
    ${SdkRootDirPath}/drivers/flexcomm/spi
    ${SdkRootDirPath}/drivers/flexcomm/usart
    ${SdkRootDirPath}/drivers/cmsis
    ${SdkRootDirPath}/drivers/dma
    ${SdkRootDirPath}/sensors
    ${SdkRootDirPath}/interfaces
    ${SdkRootDirPath}/components/button
    ${SdkRootDirPath}/components/debug_console_lite
    ${SdkRootDirPath}/components/gpio
    ${SdkRootDirPath}/components/internal_flash
    ${SdkRootDirPath}/components/led
    ${SdkRootDirPath}/components/lists
    ${SdkRootDirPath}/components/log
    ${SdkRootDirPath}/components/mem_manager
    ${SdkRootDirPath}/components/messaging
    ${SdkRootDirPath}/components/osa/config
    ${SdkRootDirPath}/components/osa
    ${SdkRootDirPath}/components/panic
    ${SdkRootDirPath}/components/reset
    ${SdkRootDirPath}/components/serial_manager
    ${SdkRootDirPath}/components/str
    ${SdkRootDirPath}/components/timer
    ${SdkRootDirPath}/components/timer_manager
    ${SdkRootDirPath}/components/uart
    ${SdkRootDirPath}/components/format
    ${SdkRootDirPath}/rtos/freertos/freertos-kernel/include
    ${SdkRootDirPath}/rtos/freertos/freertos-kernel/portable/GCC/ARM_CM33_NTZ/non_secure
    ${SdkRootDirPath}/middleware/wireless/framework/Common
    ${SdkRootDirPath}/middleware/wireless/framework/services/DBG
    ${SdkRootDirPath}/middleware/wireless/framework/Common/rtos/freertos
    ${SdkRootDirPath}/middleware/wireless/framework/services/FunctionLib
    ${SdkRootDirPath}/middleware/wireless/framework/services/ModuleInfo
    ${SdkRootDirPath}/middleware/wireless/framework/services/NVM/Interface
    ${SdkRootDirPath}/middleware/wireless/framework/services/NVM/Source
    ${SdkRootDirPath}/middleware/wireless/framework/platform/mcxw23
    ${SdkRootDirPath}/middleware/wireless/framework/platform/include
    ${SdkRootDirPath}/middleware/wireless/framework/platform/wireless_mcu
    ${SdkRootDirPath}/middleware/wireless/framework/platform/mcxw23/configs
    ${SdkRootDirPath}/middleware/wireless/framework/services/SecLib_RNG
    ${SdkRootDirPath}/middleware/wireless/framework/services/Sensors
    ${SdkRootDirPath}/middleware/wireless/bluetooth/host/interface
    ${SdkRootDirPath}/middleware/wireless/bluetooth/host/config
    ${SdkRootDirPath}/middleware/wireless/bluetooth/port
    ${SdkRootDirPath}/middleware/wireless/bluetooth/application/common
    ${SdkRootDirPath}/middleware/wireless/bluetooth/application/common/gatt_db/macros
    ${SdkRootDirPath}/middleware/wireless/bluetooth/application/common/gatt_db
    ${SdkRootDirPath}/middleware/wireless/bluetooth/profiles/battery
    ${SdkRootDirPath}/middleware/wireless/bluetooth/profiles/wireless_uart
    ${SdkRootDirPath}/middleware/wireless/ble_controller/interface/snps_controller/sdk_integration
    ${SdkRootDirPath}/middleware/wireless/ble_controller/interface/snps_controller/ble_controller
    ${SdkRootDirPath}/middleware/wireless/ble_controller/interface/snps_controller/shrd_utils
    ${SdkRootDirPath}/middleware/wireless/ble_controller/interface/snps_controller/sdk_integration/nxp_hoststack_adapter
    ${SdkRootDirPath}/middleware/wireless/ble_controller/interface/snps_controller/sdk_integration/controller_api
    ${SdkRootDirPath}/middleware/wireless/ble_controller/interface
    ${SdkRootDirPath}/middleware/wireless/bluetooth/boards/frdmmcxw23
    ${SdkRootDirPath}/middleware/wireless/bluetooth/examples/w_uart
    ${SdkRootDirPath}/middleware/wireless/bluetooth/application/common/freertos
	${SdkRootDirPath}/utils
)


IF(NOT DEFINED TARGET_LINK_SYSTEM_LIBRARIES)  
    SET(TARGET_LINK_SYSTEM_LIBRARIES "-lm -lc -lgcc -lnosys")  
ENDIF()  

TARGET_LINK_LIBRARIES(${MCUX_SDK_PROJECT_NAME} PRIVATE -Wl,--start-group)

target_link_libraries(${MCUX_SDK_PROJECT_NAME} PRIVATE ${TARGET_LINK_SYSTEM_LIBRARIES})

if(CMAKE_BUILD_TYPE STREQUAL debug)
    target_link_libraries(${MCUX_SDK_PROJECT_NAME} PRIVATE ${SdkRootDirPath}/devices/MCX/MCXW/MCXW236/arm/libpower.a)
endif(CMAKE_BUILD_TYPE STREQUAL debug)

if(CMAKE_BUILD_TYPE STREQUAL debug)
    target_link_libraries(${MCUX_SDK_PROJECT_NAME} PRIVATE ${SdkRootDirPath}/middleware/wireless/framework/services/SecLib_RNG/lib_crypto_m33.a)
endif(CMAKE_BUILD_TYPE STREQUAL debug)

if(CMAKE_BUILD_TYPE STREQUAL debug)
    target_link_libraries(${MCUX_SDK_PROJECT_NAME} PRIVATE ${SdkRootDirPath}/middleware/wireless/bluetooth/host/lib/lib_ble_host_cm33_gcc.a)
endif(CMAKE_BUILD_TYPE STREQUAL debug)

if(CMAKE_BUILD_TYPE STREQUAL debug)
    target_link_libraries(${MCUX_SDK_PROJECT_NAME} PRIVATE ${SdkRootDirPath}/middleware/wireless/ble_controller/lib/snps_controller/libble_ll_freertos.a)
endif(CMAKE_BUILD_TYPE STREQUAL debug)

if(CMAKE_BUILD_TYPE STREQUAL debug)
    target_link_libraries(${MCUX_SDK_PROJECT_NAME} PRIVATE ${SdkRootDirPath}/middleware/wireless/ble_controller/lib/snps_controller/libble_ll_utils_freertos.a)
endif(CMAKE_BUILD_TYPE STREQUAL debug)

TARGET_LINK_LIBRARIES(${MCUX_SDK_PROJECT_NAME} PRIVATE -Wl,--end-group)

ADD_CUSTOM_COMMAND(TARGET ${MCUX_SDK_PROJECT_NAME} POST_BUILD COMMAND ${CMAKE_OBJCOPY}
-Obinary ${EXECUTABLE_OUTPUT_PATH}/${MCUX_SDK_PROJECT_NAME} ${EXECUTABLE_OUTPUT_PATH}/wireless_uart_freertos.bin)

set_target_properties(${MCUX_SDK_PROJECT_NAME} PROPERTIES ADDITIONAL_CLEAN_FILES "output.map;${EXECUTABLE_OUTPUT_PATH}/wireless_uart_freertos.bin")

