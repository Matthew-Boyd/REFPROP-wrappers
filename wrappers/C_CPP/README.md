# REFPROP wrapper for C/C++

Installation
------------
**NOTE**: for Linux and macOS, you must compile REFPROP yourself, see: [REFPROP-cmake](https://github.com/usnistgov/REFPROP-cmake)

1. Follow the conventional installation instructions for REFPROP.
2. For Linux, compile REFPROP via [REFPROP-cmake](https://github.com/usnistgov/REFPROP-cmake) and copy the resulting `librefprop.so` library file to the REFPROP installation directory.
3. Ensure that the system environment variable `RPprefix` is set to the location of the REFPROP installation (e.g., `C:\Program Files (x86)\REFPROP`).
4. Install CMake, version 3.26 or newer.
   1. Windows: https://cmake.org/download/
   2. Linux: `sudo apt install cmake`
5. Install Git, version 2.0 or newer.
   1. Windows: https://git-scm.com/downloads
   2. Linux: `sudo apt install git`
6. Install compilers and build tools.
   1. Windows:  Install the Microsoft Visual C++ compiler (MSVC).
      1. **Note:** This compiler is included with the Visual Studio IDE and this step can be skipped if that is already installed.)
      2. Go to the Visual Studio download page (https://visualstudio.microsoft.com/downloads/).
      3. Under "Tools for Visual Studio", download "Build Tools for Visual Studio 20XX".
      4. Launch the installer and select the "C++ build tools" workload, ensuring that the MSVC compiler, Windows SDK and C++ Standard Library are included.
      5. Complete the installation.
   2. Linux: `sudo apt install build-essential`
7. Download the top-level `CMakeLists.txt` file into a directory that will be used for building the wrapper and associated code.
8. Run CMake from this directory to generate the build files.
   1. For Visual Studio on Windows, this can be accomplished by creating and running the following batch file (e.g., `build.bat`).
      ```
      rmdir /Q/S build_windows
      mkdir build_windows
      cd build_windows
   
      cmake -G "Visual Studio 17 2022" -DCMAKE_CONFIGURATION_TYPES="Debug;Release" ..
   
      pause
      ```
   2. For Linux, the following shell script can be used (e.g., `build.sh`).
      ```
      #!/bin/bash

      rm -rf build_linux
      mkdir build_linux
      cd build_linux
   
      cmake -G "Ninja" -DCMAKE_BUILD_TYPE=Release ..
   
      make
      ```
   3. As part of the build process, this will download the entire REFPROP-wrappers repository and will also copy the example `/src` and `/include` directories to the top-level directory.
   4. **Note:** In the new top-level `/external` directory, only the files in `/refprop/wrappers/C_CPP` need to be kept if you are just using the C/C++ wrapper.
9. Open the `main.cpp` file in the `/src` directory for example code on how to call various REFPROP functions.


Alternative
---
REFPROP can also be called using the header defining the library at: [REFPROP-headers](https://github.com/CoolProp/REFPROP-headers). This header includes functions for runtime loading of the DLL (shared library). Present there are also examples of how to use it and a CMake-based build system. This is an older approach that is not recommended for new projects.

Help
-----
Please file an issue at https://github.com/usnistgov/REFPROP-issues and we will get back to you as quickly as possible. Please don't email NIST staff directly, the only exception being if you have proprietary code that cannot be shared publicly.