cmake_minimum_required(VERSION 3.21)

# STEP 1: set up bases of environment (easy way)
# -----------------------------------------------------------------------------
include("../easy_setup.cmake")

project(Fusion6X_pj)
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
external_library(PATH "${USER_LIBS}/STM32duino_IIS2MDC" DEPENDS SPI Wire)
external_library(PATH "${USER_LIBS}/STM32duino_ISM330DHCX" DEPENDS SPI Wire)
external_library(PATH "${USER_LIBS}/STM32duino_LIS2MDL" DEPENDS SPI Wire)
external_library(PATH "${USER_LIBS}/STM32duino_LSM303AGR" DEPENDS SPI Wire)
external_library(PATH "${USER_LIBS}/STM32duino_LSM6DSL" DEPENDS SPI Wire)
external_library(PATH "${USER_LIBS}/STM32duino_LSM6DSO" DEPENDS SPI Wire)
external_library(PATH "${USER_LIBS}/STM32duino_MotionFX" DEPENDS SPI Wire)

include(build_sketch)
build_sketch(TARGET Fusion6X
  SOURCES
  ./Fusion6X_IKS01A2.ino

  DEPENDS
  STM32duino_MotionFX
  STM32duino_LSM6DSL
  Wire
)

# STEP 5: optional features
# -----------------------------------------------------------------------------

include(insights)
insights(TARGET Fusion6X
  # DIRECT_INCLUDES
  # TRANSITIVE_INCLUDES
  # SYMBOLS
  # ARCHIVES
  # LOGIC_STRUCTURE
)
