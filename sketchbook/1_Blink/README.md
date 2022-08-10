# 1. Blink

To begin with, let us demonstrate the most basic configuration file using the most basic sketch!

CMake expects a file named "CMakeLists.txt" at the root of the project. It will parse it to generate a build configuration to use with a build tool, usually `make` or `ninja`.

## Invoking CMake

Before detailing the content of the file, let us recall the use of CMake in a system shell:
```sh
cmake -G Ninja -S ./1_Blink -B ./1_Blink/build # -S source -B build, nowadays you want to separate the two
cmake --build ./1_Blink/build # build, or rebuild, the project (target "all")
```

## The CMakeLists.txt

In the following, we will detail on a line-per-line basis the content of the CMakeLists.txt found in this example.

-------------------

```cmake
cmake_minimum_required(VERSION 3.21)
```
This first line is mandatory per CMake. Its role is to ensure the version of CMake used to build has the right features and semantics.

-------------------

```cmake
# STEP 1: set up bases of environment
```
This is just a comment. No comment is mandatory, but putting some does improve maintenability in the long run.

-------------------

```cmake
list(APPEND CMAKE_MODULE_PATH "$ENV{HOME}/Arduino_Core_STM32/cmake")
```
If you ever coded in Python, you might have seen sometimes a line like `sys.path.append(...)`.
This here serves the same role: adding a new directory for CMake to search modules, in this case the `/cmake` folder of Arduino_Core_STM32.
(In this example it was put in the user's home directory.)
This is crucial, because it is the only reference your sketch has to the core, for now.

-------------------

```cmake
set(CMAKE_TOOLCHAIN_FILE toolchain)
```
Arduino_Core_STM32 needs specific tools to build: compiler, linker, Python, ...
It has a module witch takes care of all these requirements. This, in the language of CMake, is a "toolchain file".
The purpose of this line is to make CMake aware that a file called "toolchain.cmake" is available and should be parsed to set up the environment.

-------------------

```cmake
project("Blink_project")
```
This function is really CMake's "setup" function. Calling it is mandatory before tacking the "real" build description (settings, source files...)
Notably, as part of this function, the toolchain file is actually executed.

The name of the project is arbitrary; in addition, many other optional arguments are not illustrated here. Please refer to the [CMake docs](https://cmake.org/cmake/help/latest/command/project.html) for the full signature of the function.

-------------------

```cmake
include(overall_settings)
overall_settings(
  # ... no argument, use default config ...
)
```
The first line searches and executes a CMake module. In this case, the `overall_settings` module is a part of Arduino_Core_STM32, so CMake can find it thanks to the earlier `list(APPEND CMAKE_MODULE_PATH ...)`.
Most modules of Arduino_Core_STM32 define a function with the same name. This is the case here, and that is what the second line does: call `overall_settings()`.

The role of this function is to define all the settings needed to build the project, for those settings that are not related to the board itself: e.g., optimization level, software features, HAL modules...
For our first project, the default values are satisfying, so the body can be left empty.
Note: Calling this function with no argument is _not_ the same as skipping it altogether: not all default values are empty!


-------------------

```cmake
include(set_board)
set_board(NUCLEO_F031K6
  # ... use default Serial/USB configuration ...
)
```
Here is another function defined in Arduino_Core_STM32. Therefore, it is first imported, then called, as in the previous step.

The role of `set_board()` is to define all the settings needed to build for a particular board.
It takes a mandatory board name, and optionally a series of features to enable (e.g., USB or Serial support). In our case, the default values are fine, so these settings are left out.


-------------------

```cmake
include(build_sketch)
build_sketch(TARGET "Blink"
  SOURCES
  1_Blink.ino
)
```

Now we can handle our sketch. This is done with yet another function of Arduino_Core_STM32.
Still the same pattern of "import-then-call" is used.
Now notice the keywords, "TARGET" and "SOURCES", that are structuring the call:
- "TARGET" needs one argument: the name of the logical target for your sketch. This will also be the file name of the executable to be built.
- "SOURCES" needs any number of arguments: following is a list of the source files to build as part of the sketch. Relative paths are interpreted from the folder the CMakeLists.txt is in.

Some more explanations about the sources:
- only the files that have to be compiled are to be listed here. Headers (.h) are not relevant.
- listing the sources files can look tedious, but it really is the most robust way to proceed (as opposed to using wildcards: `*.c`, `*.ino`). Please refer to the [note in the CMake documentation of `file(GLOB)`](https://cmake.org/cmake/help/latest/command/file.html#glob) for more on this topic.


# Result of the build

After building, you will find "Blink", "Blink.bin", "Blink.hex" in your build directory (`cmake -B ...`).
Uploading is not supported, though; please use your favorite external tool for this (or copy/paste the .bin file to the board's mass storage, when supported)
