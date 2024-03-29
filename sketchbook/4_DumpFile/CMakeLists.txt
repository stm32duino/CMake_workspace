# This file was autogenerated by ~/Arduino_Core_STM32/cmake/scripts/cmake_easy_setup.py.
# Use it in your CMake configuration by `include()`'ing it.
# You can also copy it in your sketch's folder and edit it to fit your project.

cmake_minimum_required(VERSION 3.21)

# STEP 1: set up bases of environment
# -----------------------------------------------------------------------------

file(REAL_PATH "~/Arduino_Core_STM32" CORE_PATH EXPAND_TILDE)
file(TO_CMAKE_PATH "${CORE_PATH}" CORE_PATH)

file(REAL_PATH "~/Arduino/libraries" USER_LIBS EXPAND_TILDE)
file(TO_CMAKE_PATH "${USER_LIBS}" USER_LIBS)

set(BOARDNAME "NUCLEO_L433RC_P")

list(APPEND CMAKE_MODULE_PATH ${CORE_PATH}/cmake)
set(CMAKE_TOOLCHAIN_FILE toolchain)


# You may remove this block when using this file as the sketch's CMakeLists.txt
if (NOT ${CMAKE_PARENT_LIST_FILE} STREQUAL ${CMAKE_CURRENT_LIST_FILE})
    # When we are imported from the main CMakeLists.txt, we should stop here
    # not to interfere with the true build config.
    return()
endif()

project("4_DumpFile_project")

# STEP 2: configure the build
# -----------------------------------------------------------------------------

include(set_board)
set_board("${BOARDNAME}"
  # SERIAL generic
  # USB none
  # XUSB FS
  # VIRTIO disabled
  # BOOTLOADER dfuo/dfu2/hid
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
include(external_library)
external_library(PATH "${USER_LIBS}/SD" DEPENDS SPI)

include(build_sketch)
build_sketch(TARGET "4_DumpFile"
  SOURCES
  4_DumpFile.ino

  DEPENDS
  SD
  SPI
)

# STEP 4: optional features
# -----------------------------------------------------------------------------

include(insights)
insights(TARGET "4_DumpFile"
  # DIRECT_INCLUDES
  # TRANSITIVE_INCLUDES
  # SYMBOLS
  # ARCHIVES
  # LOGIC_STRUCTURE
)
