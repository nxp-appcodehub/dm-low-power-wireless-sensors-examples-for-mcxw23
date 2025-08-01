/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*${header:start}*/
#include "pin_mux.h"
#include "fsl_gpio.h"
#include "fsl_iocon.h"
#include "clock_config.h"
#include "board.h"
#include "fsl_power.h"

/*${header:end}*/

/*${variable:start}*/
/*${variable:end}*/

/*${function:start}*/
void BOARD_InitHardware(void)
{
    POWER_Init();
    BOARD_InitPins();
    
    BOARD_BootClockXTAL32M();

    CLOCK_EnableClock(kCLOCK_Iocon);
    CLOCK_EnableClock(kCLOCK_Gpio0);
    GPIO_PortInit(GPIO, 0);
    CLOCK_AttachClk(kFRO12M_to_FLEXCOMM0);
    CLOCK_EnableClock(kCLOCK_FlexComm0);
    CLOCK_AttachClk(kFRO12M_to_FLEXCOMM1);
    CLOCK_EnableClock(kCLOCK_FlexComm1);

    /* reset FLEXCOMM for I2C */
    RESET_PeripheralReset(kFC1_RST_SHIFT_RSTn);
    
    RESET_PeripheralReset(kPINT_RST_SHIFT_RSTn);
    
    CLOCK_AttachClk(kFRO12M_to_FLEXCOMM2);
    CLOCK_EnableClock(kCLOCK_FlexComm2);

    CLOCK_AttachClk(kOSC32K_to_CTIMER0);

    BOARD_Configure32kOsc();

#if (defined(gDebugConsoleEnable_d) && (gDebugConsoleEnable_d == 1))
    BOARD_InitDebugConsole();
#endif
}

uint32_t I2C1_GetFreq(void)
{
    return CLOCK_GetFlexCommClkFreq(1U);
}
/*${function:end}*/
