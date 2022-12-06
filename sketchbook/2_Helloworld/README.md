# 2. "Hello world"

The CMakeLists.txt from this sketch has, for the most part, the same structure as the one in the previous example.
The major difference between this example and Blink is that we now use a board feature, namely Serial. Fortunately, this feature is enabled by default in the Arduino environment.

As you can see, the options for `set_board()` and `overall_settings()` have also been filled in, but commented.

```cmake
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
```

This is meant to give an overview of the available switches, although the default values are still in place.
The meaning of each switch is documented [on the wiki](https://github.com/stm32duino/wiki/wiki/Functions-reference#overall_settings).
Also, for those keywords that take an argument, usual values for the arguments are listed there.

As an exercise, you can try to uncomment the line `SERIAL generic` in the `set_board()` call.
When you try rebuilding afterwards, no work will be done: indeed, Serial=generic is the default value.
Now, try to change that line to `SERIAL disabled` and rebuilding.
The build will now fail, since the serial support is needed for this sketch.
You can also play with the diverse switches of `overall_settings()` in this fashion to best suit your needs in terms of features, or performance.

-------------------

Another point of interest is the `insights()` function at the end of the file.
The role of this function is to produce graphs to illustrate the build process: CMake generation, compilation, linking.
The documentation for this function is available [here](https://github.com/stm32duino/wiki/wiki/Functions-reference#insights).
These graphs may be useful to understand the complete structure of the project, or to understand where such or other symbol came from.

As documented, however, enabling these insights can slow the build significantly (however, just calling the fuction without enabling any insight is harmless).
They may also hinder debugging by removing some error log.
Anyway, the insights are special targets not built by default: when enabled, use the following command to build them:
```sh
# to build the target "logicstrucure.svg", which goes with LOGIC_STRUCTURE
cmake --build ./2_helloworld/build --target logicstructure.svg
```
