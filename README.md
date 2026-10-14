
**This code is in the progress of being rewritten for 64bit**

* done: convert all Xcode projects to 64bit
* done: move build environment to cmake (see "Make CMake" below)
* TODO: 


* NEWT / 0 for 

NEWT / 0 Apple's PDA "Newton" was in the running of the original prototype 
implementation NewtonScript-oriented language. NewtonScript from the command 
line to read the source code can be executed shortly. 


* Operating Environment 

   Mac OS X 
   Darwin 
   Linux 
   FreeBSD 
   Windows 
   BeOS 


* How to compile 

  - Mac OS X 10.3 or higher 
    Xcode by the extension. Xcode project to compile 

  - Mac OS X 10.2: / Darwin 
  - Linux 
  - BeOS 
    to make 

  - FreeBSD 
    GNU make (gmake) to make use 

  - Windows 
    To make on MinGW + MSYS 


About * doxygen 

   doxygen doxygen.conf document from the source code can be generated. 
   Doxygen.conf according to the environment and please correct. 

   For example:
```
cd misc
Doxygen Doxyfile
```     
or
```
Doxygen Doxyfile.en
```


* Other 

  - Mac OS X has to work with. DS_Store files and other garbage may be mixed 
  

* Terms of distribution 

Please refer to the file COPYING.ja. 


* Author 

Comments, bug reports gnue@so-kukan.com others. 
http://www.so-kukan.com/gnue/

* Make CMake

CMake builds the library, the `newt64` command, and the extensions in `ext/`
(not on Windows). It needs flex and bison, except on Windows. Generated files,
including `version.h`, go into the build directory.

```
;; Release version
cmake -S . -B _Build_/Release -DCMAKE_BUILD_TYPE=Release
cmake --build _Build_/Release
sudo cmake --install _Build_/Release
```
```
;; Debug version
cmake -S . -B _Build_/Debug -DCMAKE_BUILD_TYPE=Debug
cmake --build _Build_/Debug
```
```
;; Xcode version (Xcode 27 needs a deployment target of 12.0 or later)
cmake -S . -B _Build_/Xcode -G Xcode -DCMAKE_OSX_DEPLOYMENT_TARGET=12.0
```

Options:

  - `-DNEWT64_BUILD_EXTENSIONS=OFF` skips `ext/`.
  - `-DCMAKE_OSX_DEPLOYMENT_TARGET=...` and `-DCMAKE_OSX_ARCHITECTURES=...`
    replace the macOS defaults, 10.13 and `arm64;x86_64`.

Extensions install into `lib/newt64`, where `Require()` finds them. Set
`NEWTLIB` to a `:`-separated list of directories to look elsewhere.

Tests: run `ctest` in the build directory (`ctest -C Release` for Xcode).
The scripts are in `tests/`; see `tests/README.md`.
