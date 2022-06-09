cmake_minimum_required(VERSION 3.21)

# STEP 1: set up bases of environment
# -----------------------------------------------------------------------------

# update this to point to the instrumented Arduino core
# get it on GitHub at https://github.com/massonal/Arduino_Core_STM32
set(CORE_PATH "$ENV{HOME}/Arduino_Core_STM32")

# lots of automation is implemented there, you want to get it easily
list(APPEND CMAKE_MODULE_PATH ${CORE_PATH}/cmake)

set(CMAKE_TOOLCHAIN_FILE toolchain) # ${CORE_PATH}/cmake/toolchain.cmake

project(I2Ctemp_pj)

# STEP 2: configure the build
# -----------------------------------------------------------------------------

include(set_board)
set_board("NUCLEO_L433RC_P"
  # SERIAL generic
  # USB none
  # XUSB FS
  # VIRTIO disabled
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

# STEP 4: configure your sketch
# -----------------------------------------------------------------------------

include(external_library)
external_library(PATH ../../libraries/Temperature_LM75_Derived FORCE DEPENDS Wire)

include(build_sketch)
build_sketch(TARGET I2Ctemp
  SOURCES
  ./I2Ctemp.ino

  DEPENDS
  Temperature_LM75_Derived
  Wire
)

# STEP 5: optional features
# -----------------------------------------------------------------------------

include(insights)
insights(TARGET I2Ctemp
  # DIRECT_INCLUDES
  # TRANSITIVE_INCLUDES
  # SYMBOLS
  # ARCHIVES
  # LOGIC_STRUCTURE
)
