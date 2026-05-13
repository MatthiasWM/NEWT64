# CMake Toolchain file for MinGW (Cross and Native)
#
# Usage (Cross):
# cmake -DCMAKE_TOOLCHAIN_FILE=../cmake/mingw64-toolchain.cmake ..
#
# Usage (Native MSYS2):
# cmake -G "MinGW Makefiles" -DCMAKE_TOOLCHAIN_FILE=../cmake/mingw64-toolchain.cmake ..

set(CMAKE_SYSTEM_NAME Windows)

# Check if we are cross-compiling or native
if(NOT DEFINED CMAKE_C_COMPILER)
    find_program(CROSS_GCC_64 x86_64-w64-mingw32-gcc)
    if(CROSS_GCC_64)
        # Cross-compilation environment (Ubuntu/Debian)
        set(CMAKE_C_COMPILER x86_64-w64-mingw32-gcc)
        set(CMAKE_CXX_COMPILER x86_64-w64-mingw32-g++)
        set(CMAKE_RC_COMPILER x86_64-w64-mingw32-windres)
        set(CMAKE_FIND_ROOT_PATH /usr/x86_64-w64-mingw32)
    else()
        # Native environment (MSYS2 MinGW64)
        set(CMAKE_C_COMPILER gcc)
        set(CMAKE_CXX_COMPILER g++)
    endif()
endif()

# Adjust the search behavior for find_package
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
