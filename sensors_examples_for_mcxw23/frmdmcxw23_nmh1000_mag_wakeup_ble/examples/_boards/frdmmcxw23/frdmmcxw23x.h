/*
 * Copyright 2025 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 * @file frdmmcxw23x.h
 * @brief The frdmmcxw23x.h file defines GPIO pin mappings for frdmmcxw23x board
 */

#ifndef FRDMMCXW23X_H_
#define FRDMMCXW23X_H_

#include "pin_mux.h"
#include "RTE_Device.h"
#include "fsl_clock.h"

// I2C_S2: Driver information for alternate I2C bus on shield

#define I2C_S2_DRIVER       Driver_I2C1
#define I2C_S2_DEVICE_INDEX I2C1_INDEX
#define I2C_S2_SIGNAL_EVENT I2C1_SignalEvent_t

// SPI: Driver information default SPI brought to shield
#define SPI_S_DRIVER       Driver_SPI1
#define SPI_S_BAUDRATE     500000U ///< Transfer baudrate - 500k
#define SPI_S_DEVICE_INDEX SPI1_INDEX
#define SPI_S_SIGNAL_EVENT SPI1_SignalEvent_t

// UART: Driver information for default UART to communicate with HOST PC.
#define HOST_S_DRIVER       Driver_USART1
#define HOST_S_SIGNAL_EVENT HOST_SignalEvent_t

/* Compatability definitions for frdmmcxw7x */
#define I2C            I2C1
#define I2C_Type       I2C_Type
#define SPI            SPI1
#define SPI_Type       SPI_Type
#define UART           USART0
#define UART_Type      USART_Type

#endif /* FRDMMCXW23X_H_ */
