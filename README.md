
**This code is in the progress of being rewritten for 64bit**

* done: convert all Xcode projects to 64bit
* TODO: move build environment ot cmake
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

```
;; Debug version
mkdir \_Build\_; cd \_Build\_
mkdir Debug; cd Debug
cmake -DCMAKE\_BUILD\_TYPE=Debug ../..
cmake --build .
sudo cmake --install .
```
```
;; Release version
mkdir \_Build\_; cd \_Build\_
mkdir Release; cd Release
cmake -DCMAKE\_BUILD\_TYPE=Release ../..
cmake --build .
sudo cmake --install .
```
```
;; Xcode version
mkdir \_Build\_; cd \_Build\_
mkdir Release; cd Release
cmake -P Xcode ../..
```
