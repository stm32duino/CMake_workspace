# 3. Mouse control

You may have noticed that, up to this example, the sketches did not use any library.
In contrast, the purpose of this example is to introduce the first library dependencies.
The sketch here makes use of the Mouse library, which is built in Arduino_Core_STM32.
(It's actually the example this library provides.)

Apart from the different setting in `set_board()` (this library requires USB support in HID mode), the only difference with the previous example lies in `build_sketch()`, with the addition of a `DEPENDS` clause.
```cmake
include(build_sketch)
build_sketch(TARGET "3_ButtonMouseControl"
  SOURCES
  3_ButtonMouseControl.ino

  DEPENDS
  Mouse
)
```

Indeed, as opposed to Arduino IDE, there is no automatic dependency detection with CMake: they all have to be explicitly listed.
For the libraries bundled in Arduino_Core_STM32, the process is as simple as listing the dependencies in the function call.
Third-party libraries (those in the user's sketchbook) require an additional step; this will be covered in the next example.
