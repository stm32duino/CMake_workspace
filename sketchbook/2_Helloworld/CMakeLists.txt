cmake_minimum_required(VERSION 3.21)

# STEP 1: set up bases of environment
# -----------------------------------------------------------------------------

file(REAL_PATH "~/Arduino_Core_STM32" CORE_PATH EXPAND_TILDE)
file(TO_CMAKE_PATH "${CORE_PATH}" CORE_PATH)

list(APPEND CMAKE_MODULE_PATH ${CORE_PATH}/cmake)
set(CMAKE_TOOLCHAIN_FILE toolchain)

project("2_Helloworld_project")

# STEP 2: configure the build
# -----------------------------------------------------------------------------

include(set_board)
set_board("NUCLEO_L433RC_P"
  # SERIAL generic
  # USB none
  # XUSB FS
  # VIRTIO disabled
  # BOOTLOADER dfuo / dfu2 / hid
)

include(overall_settings)
overall_settings(
  # STANDARD_LIBC
  # PRINTF_FLOAT
  # SCANF_FLOAT
  # DEBUG_SYMBOLS
  # LTO
  # NO_RELATIVE_MACRO
  # UNDEF_NDEBUG
  # OPTIMIZATION "s"
  # BUILD_OPT ./build.opt
  # DISABLE_HAL_MODULES ADC I2C RTC SPI TIM DAC EXTI ETH SD QSPI
  # CORE_CALLBACK
)

# STEP 3: configure your sketch
# -----------------------------------------------------------------------------

include(build_sketch)
build_sketch(TARGET "2_Helloworld"
  SOURCES
  2_Helloworld.ino
)

# STEP 4: optional features
# -----------------------------------------------------------------------------

include(insights)
insights(TARGET "2_Helloworld"
  # DIRECT_INCLUDES
  # TRANSITIVE_INCLUDES
  # SYMBOLS
  # ARCHIVES
  # LOGIC_STRUCTURE
)
