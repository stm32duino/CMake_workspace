cmake_minimum_required(VERSION 3.21)

# STEP 1: set up bases of environment
# -----------------------------------------------------------------------------

file(REAL_PATH "~/Arduino_Core_STM32" CORE_PATH EXPAND_TILDE)
file(TO_CMAKE_PATH "${CORE_PATH}" CORE_PATH)

list(APPEND CMAKE_MODULE_PATH ${CORE_PATH}/cmake)
set(CMAKE_TOOLCHAIN_FILE toolchain)

set(CMAKE_TOOLCHAIN_FILE toolchain)

project("Blink_project")

# STEP 2: configure the build
# -----------------------------------------------------------------------------

include(overall_settings)
overall_settings(
  # ... no argument, use default config ...
)

include(set_board)
set_board(NUCLEO_L433RC_P
  # ... use default Serial/USB configuration ...
)

# STEP 3: configure your sketch
# -----------------------------------------------------------------------------

include(build_sketch)
build_sketch(TARGET "Blink"
  SOURCES
  1_Blink.ino
)
