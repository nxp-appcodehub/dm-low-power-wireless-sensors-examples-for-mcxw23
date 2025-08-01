/*
 * Copyright 2025 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 * @file mpl3115_board.h
 * @brief The mpl3115_board.h file declares mapping of the MCU
         Device peripherals to the frdm-ke15z and mpl3115 shield board
 */


 #ifndef _MPL3115_BOARD_H_
 #define _MPL3115_BOARD_H_
 
 /* The shield name */
 #define SHIELD_NAME "MPL3115-BOARD"
 
 // FXLS8974 Sensor Information
 #define FXLS8974_I2C_ADDR 0x18
 // MPL3115 Sensor Information
 #define MPL3115_I2C_ADDR 0x60

#endif /* _MPL3115_BOARD_H_ */
