IF(NOT DEFINED FPU)  
    SET(FPU "-mfloat-abi=hard -mfpu=fpv5-sp-d16")  
ENDIF()  

IF(NOT DEFINED SPECS)  
    SET(SPECS "--specs=nosys.specs")  
ENDIF()  

IF(NOT DEFINED DEBUG_CONSOLE_CONFIG)  
    SET(DEBUG_CONSOLE_CONFIG "-DSDK_DEBUGCONSOLE_UART")  
ENDIF()  

SET(CMAKE_ASM_FLAGS_DEBUG " \
    ${CMAKE_ASM_FLAGS_DEBUG} \
    -DCPU_MCXW236BIHNAR \
    -D__STARTUP_CLEAR_BSS \
    -DMCUXPRESSO_SDK \
    -DOSA_USED \
    -DUSE_RTOS=1 \
    -DSERIAL_PORT_TYPE_UART=1 \
    -DTIMER_PORT_TYPE_CTIMER=1 \
    -DgNvmSaveOnIdlePolicy_d=0 \
    -DgRngUseSecureSubSystem_d=0 \
    -include \
    mcux_config.h \
    -mthumb \
    -mcpu=cortex-m33 \
    -g \
    -include \
    middleware/wireless/bluetooth/boards/frdmmcxw23/bluetooth/w_uart/app_preinclude.h \
    ${FPU} \
")
SET(CMAKE_C_FLAGS_DEBUG " \
    ${CMAKE_C_FLAGS_DEBUG} \
    -DHAL_CTIMER_COUNTER_RESET=false \
    -DUSE_MCXW23_TIMER_MANAGER \
    -DCPU_MCXW236BIHNAR \
    -DTRNG0=TRNG \
    -DTRNG0_IRQn=TRNG_IRQn \
    -DDEBUG \
    -DMCUX_META_BUILD \
    -DMCUXPRESSO_SDK \
    -DOSA_USED \
    -DUSE_RTOS=1 \
    -DSERIAL_PORT_TYPE_UART=1 \
    -DTIMER_PORT_TYPE_CTIMER=1 \
    -DSDK_OS_FREE_RTOS \
    -DgNvmSaveOnIdlePolicy_d=0 \
    -DENABLE_RAM_VECTOR_TABLE \
    -DgRngUseSecureSubSystem_d=0 \
    -DBLE \
    -DSUPPORT_MASTER_CONNECTION \
    -DSUPPORT_SLAVE_CONNECTION \
    -DSERIAL_USE_CONFIGURE_STRUCTURE=1 \
    -DgButtonSupported_d=1 \
    -DSDK_COMPONENT_INTEGRATION=1 \
    -DFSL_OSA_TASK_ENABLE=1 \
    -DCR_INTEGER_PRINTF \
    -DCFG_BLE_PRJ=1 \
    -DHAL_FLASH_ROMAPI_DRIVER=1 \
    -include \
    mcux_config.h \
    --specs=nano.specs \
    -Wall \
    -fno-common \
    -ffunction-sections \
    -fdata-sections \
    -fno-builtin \
    -mthumb \
    -mapcs \
    -std=gnu99 \
    -mcpu=cortex-m33 \
    -g \
    -Og \
    -include \
    middleware/wireless/bluetooth/boards/frdmmcxw23/bluetooth/w_uart/app_preinclude.h \
    ${FPU} \
    ${DEBUG_CONSOLE_CONFIG} \
")
SET(CMAKE_EXE_LINKER_FLAGS_DEBUG " \
    ${CMAKE_EXE_LINKER_FLAGS_DEBUG} \
    -Wall \
    -fno-common \
    -ffunction-sections \
    -fdata-sections \
    -fno-builtin \
    -mthumb \
    -mapcs \
    -Wl,--gc-sections \
    -Wl,-static \
    -Wl,--print-memory-usage \
    -Xlinker \
    -Map=output.map \
    -mcpu=cortex-m33 \
    -g \
    -Xlinker \
    --no-wchar-size-warning \
    -Xlinker \
    -znoexecstack \
    ${FPU} \
    ${SPECS} \
    -T\"${SdkRootDirPath}/examples/_boards/frdmmcxw23/wireless_examples/linker/gcc/connectivity_ble.ld\" -static \
")
