# config to select component, the format is CONFIG_USE_${component}
# Please refer to cmake files below to get available components:
#  ${SdkRootDirPath}/devices/MCXW236/all_lib_device.cmake

set(CONFIG_COMPILER gcc)
set(CONFIG_TOOLCHAIN armgcc)
set(CONFIG_USE_COMPONENT_CONFIGURATION false)
set(CONFIG_CORE cm33)
set(CONFIG_DEVICE MCXW236)
set(CONFIG_BOARD frdmmcxw23)
set(CONFIG_KIT frdmmcxw23)
set(CONFIG_DEVICE_ID MCXW236)
set(CONFIG_FPU SP_FPU)
set(CONFIG_CORE_ID cm33)
