/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _MCUX_CONFIG_H_
#define _MCUX_CONFIG_H_

// #define configENABLE_FPU 0
// #define configENABLE_MPU 0
// #define configENABLE_TRUSTZONE 0
#define configRUN_FREERTOS_SECURE_ONLY 1
#define CONFIG_FLASH_BASE_ADDRESS 0x0
#define SERIAL_MANAGER_NON_BLOCKING_MODE 1
#define BUTTON_SHORT_PRESS_THRESHOLD 200U
#define BUTTON_LONG_PRESS_THRESHOLD 500U
#define BUTTON_DOUBLE_CLICK_THRESHOLD 200U
// #define CONFIG_STREAM_FLASH 0
// #define gNvDebugEnabled_d 0
// #define gNvTableKeptInRam_d 0
// #define gNvUseExtendedFeatureSet_d 0
// #define gNvSalvageFromEccFault_d 0
// #define gNvFragmentation_Enabled_d 0
// #define CONFIG_NVS 0
// #define CONFIG_SETTINGS 0
// #define LIB_JPEG_USE_HW_ACCEL 0
// #define USE_PNGDEC_DRIVER 0
#define CONFIG_LV_ATTRIBUTE_MEM_ALIGN 
#define CONFIG_LV_ATTRIBUTE_LARGE_CONST 
// #define CONFIG_BOOT_CUSTOM_DEVICE_SETUP 0
// #define CONFIG_FREERTOS_USE_CUSTOM_CONFIG_FRAGMENT 0
// #define MPU_SUPPORT 0
// #define USE_PERCEPIO_TRACELYZER 0

#endif /* _MCUX_CONFIG_H_ */
