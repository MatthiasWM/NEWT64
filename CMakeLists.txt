#
# Use a single CMake setup to compile Newt/64 on all supported platforms.
# 

cmake_minimum_required(VERSION 3.15)

project("Newt64" VERSION "2020.4.5")

set (CMAKE_CXX_STANDARD 14)

# prepare for various platform
if (${CMAKE_SYSTEM_NAME} STREQUAL "Darwin")

	# MacOS
	set (CMAKE_OSX_ARCHITECTURES=x86_64)
	set (CMAKE_OSX_DEPLOYMENT_TARGET 10.9)

elseif (${CMAKE_SYSTEM_NAME} STREQUAL "Linux")

	# Linux

elseif (${CMAKE_SYSTEM_NAME} STREQUAL "Windows")

	# MSWindows
	cmake_policy(SET CMP0091 NEW)
	set (CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
	set(BISON_ROOT c:/GnuWin32/bin)
	set(FLEX_ROOT c:/GnuWin32/bin)

else ()

    # not supported
	message ("Newt/64 is not configured to build on this platform: " ${CMAKE_SYSTEM_NAME} ".")

endif ()

#
# ---- Timestamp --------------------------------------------------------------
#

set_source_files_properties (${CMAKE_CURRENT_SOURCE_DIR}/src/version.h PROPERTIES GENERATED TRUE)
string (TIMESTAMP COMPILE_TIME_YYYY "%Y")
string (TIMESTAMP COMPILE_TIME_MM "%m")
string (TIMESTAMP COMPILE_TIME_DD "%d")
configure_file(
	${CMAKE_CURRENT_SOURCE_DIR}/src/version.h.in
	${CMAKE_CURRENT_SOURCE_DIR}/src/version.h
)

#
# ---- Newt/64 ----------------------------------------------------------------
#

set (sources
	src/newt_core/NewtBC.c
	src/newt_core/NewtEnv.c
	src/newt_core/NewtFile.c
	src/newt_core/NewtFns.c
	src/newt_core/NewtGC.c
	src/newt_core/NewtIconv.c
	src/newt_core/NewtIO.c
	src/newt_core/NewtMem.c
	src/newt_core/NewtNSOF.c
	src/newt_core/NewtPkg.c
	src/newt_core/NewtObj.c
	src/newt_core/NewtParser.c
	src/newt_core/NewtPrint.c
	src/newt_core/NewtStr.c
	src/newt_core/NewtVM.c
	src/parser/lookup_words.c
	src/utils/endian_utils.c
	${CMAKE_CURRENT_BINARY_DIR}/newt.l.c
	${CMAKE_CURRENT_BINARY_DIR}/y.tab.c
	src/parser/newt.y
)

set (headers
	src/version.h
	src/newt_core/incs/NewtBC.h
	src/newt_core/incs/NewtConf.h
	src/newt_core/incs/NewtCore.h
	src/newt_core/incs/NewtEnv.h
	src/newt_core/incs/NewtErrs.h
	src/newt_core/incs/NewtFile.h
	src/newt_core/incs/NewtFns.h
	src/newt_core/incs/NewtGC.h
	src/newt_core/incs/NewtIconv.h
	src/newt_core/incs/NewtIO.h
	src/newt_core/incs/NewtLib.h
	src/newt_core/incs/NewtMem.h
	src/newt_core/incs/NewtNSOF.h
	src/newt_core/incs/NewtObj.h
	src/newt_core/incs/NewtParser.h
	src/newt_core/incs/NewtPkg.h
	src/newt_core/incs/NewtPrint.h
	src/newt_core/incs/NewtStr.h
	src/newt_core/incs/NewtType.h
	src/newt_core/incs/NewtVM.h
	src/newt_core/incs/platform.h
	src/newt_core/incs/win/config.h
	src/newt_core/incs/win/NewtConf.h
	$<$<PLATFORM_ID:Darwin>:  src/newt_core/incs/Darwin/config.h src/newt_core/incs/Darwin/NewtConf.h>
	$<$<PLATFORM_ID:Linux>:   src/newt_core/incs/Darwin/config.h src/newt_core/incs/Darwin/NewtConf.h>
	$<$<PLATFORM_ID:Windows>: src/newt_core/incs/win/config.h src/newt_core/incs/win/NewtConf.h>
)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

#
# ---- lex and yacc -----------------------------------------------------------
#

find_package(FLEX REQUIRED)
flex_target(lexer src/parser/newt.l ${CMAKE_CURRENT_BINARY_DIR}/newt.l.c)

find_package(BISON REQUIRED)
bison_target(parser src/parser/newt.y ${CMAKE_CURRENT_BINARY_DIR}/y.tab.c)

add_flex_bison_dependency(lexer parser)

#
# ---- newt64 library ---------------------------------------------------------
#

add_library (libnewt64 STATIC
	${sources}
	${headers}
)
set_target_properties(libnewt64
	PROPERTIES OUTPUT_NAME newt64
)

target_include_directories (libnewt64 PUBLIC
	src/newt_core/incs/
	src/parser/
	src/
	$<$<PLATFORM_ID:Darwin>:  src/newt_core/incs/Darwin >
	$<$<PLATFORM_ID:Linux>:   src/newt_core/incs/Darwin >
	$<$<PLATFORM_ID:Windows>: src/newt_core/incs/win >
)

target_link_libraries(libnewt64 PUBLIC 
	$<$<PLATFORM_ID:Darwin>:  >
	$<$<PLATFORM_ID:Linux>:   >
	$<$<PLATFORM_ID:Windows>: shlwapi >
)

target_compile_definitions(libnewt64 PRIVATE
	$<$<PLATFORM_ID:Darwin>:  TARGET_OS_DARWIN=1 >
	$<$<PLATFORM_ID:Linux>:   TARGET_OS_LINUX=1 >
	$<$<PLATFORM_ID:Windows>: TARGET_OS_WINDOWS=1 >
)

install (TARGETS libnewt64
    ARCHIVE DESTINATION lib
)

install (DIRECTORY src/newt_core/incs/
    DESTINATION include/newt64
)

#
# ---- newt64 command line app ------------------------------------------------
#

add_executable(newt64
	src/main.c
)

target_include_directories (newt64 PUBLIC
	src/newt_core/incs/
	src/parser/
	src/
	$<$<PLATFORM_ID:Darwin>:  src/newt_core/incs/Darwin >
	$<$<PLATFORM_ID:Linux>:   src/newt_core/incs/Darwin >
	$<$<PLATFORM_ID:Windows>: src/newt_core/incs/win >
)

target_link_libraries(newt64
	PUBLIC 
	libnewt64
)

install (TARGETS newt64
    RUNTIME DESTINATION bin
)

