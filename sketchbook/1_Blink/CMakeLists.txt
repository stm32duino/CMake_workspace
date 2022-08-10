cmake_minimum_required(VERSION 3.21)

# STEP 1: set up bases of environment
# -----------------------------------------------------------------------------

list(APPEND CMAKE_MODULE_PATH "$ENV{HOME}/Arduino_Core_STM32/cmake")
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
