#
# Use a single CMake setup to compile Newt/64 on all supported platforms.
# 

cmake_minimum_required(VERSION 3.13)

project("Newt64" VERSION "2020.4.5")

set (CMAKE_CXX_STANDARD 14)

# prepare for various platforms
if (${CMAKE_SYSTEM_NAME} STREQUAL "Darwin")

	# MacOS
	# Defaults; override them with -D. Xcode 27 needs a target of 12.0 or later.
	if (NOT CMAKE_OSX_ARCHITECTURES)
		set (CMAKE_OSX_ARCHITECTURES "arm64;x86_64")
	endif ()
	if (NOT CMAKE_OSX_DEPLOYMENT_TARGET)
		set (CMAKE_OSX_DEPLOYMENT_TARGET "10.13")
	endif ()
	set (NEWT64_INSTALL_PREFIX "")

elseif (${CMAKE_SYSTEM_NAME} STREQUAL "Linux")

	# Linux
	set (NEWT64_INSTALL_PREFIX "")

elseif (${CMAKE_SYSTEM_NAME} STREQUAL "OpenBSD")

	# OpenBSD
	set (NEWT64_INSTALL_PREFIX "")

elseif (${CMAKE_SYSTEM_NAME} STREQUAL "Windows")

	# MSWindows
	cmake_policy(SET CMP0091 NEW)
	set (CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
	set(BISON_ROOT c:/GnuWin32/bin)
	set(FLEX_ROOT c:/GnuWin32/bin)
	set (NEWT64_INSTALL_PREFIX ${CMAKE_CURRENT_BINARY_DIR}/ )

else ()

    # not supported
	message ("Newt/64 is not configured to build on this platform: " ${CMAKE_SYSTEM_NAME} ".")

endif ()

#
# ---- Timestamp --------------------------------------------------------------
#

# version.h is generated into the build tree, so the sources stay untouched
# and several build directories can share one checkout.
string (TIMESTAMP COMPILE_TIME_YYYY "%Y")
string (TIMESTAMP COMPILE_TIME_MM "%m")
string (TIMESTAMP COMPILE_TIME_DD "%d")
configure_file(
	${CMAKE_CURRENT_SOURCE_DIR}/src/version.h.in
	${CMAKE_CURRENT_BINARY_DIR}/version.h
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
)

if (${CMAKE_SYSTEM_NAME} STREQUAL "Windows")
	list ( APPEND sources
		src/parser/newt.l.c
		src/parser/y.tab.c
	)
else ()
	list ( APPEND sources
		${CMAKE_CURRENT_BINARY_DIR}/newt.l.c
		${CMAKE_CURRENT_BINARY_DIR}/y.tab.c
		src/parser/newt.l
		src/parser/newt.y
	)
endif ()

set (headers
	${CMAKE_CURRENT_BINARY_DIR}/version.h
	src/newt_core/incs/NewtBC.h
	src/newt_core/incs/NewtConf.h.in
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
	$<$<PLATFORM_ID:Darwin>:  src/newt_core/incs/darwin/config.h src/newt_core/incs/darwin/NewtConf.h>
	$<$<PLATFORM_ID:Linux>:   src/newt_core/incs/darwin/config.h src/newt_core/incs/darwin/NewtConf.h>
	$<$<PLATFORM_ID:OpenBSD>: src/newt_core/incs/darwin/config.h src/newt_core/incs/darwin/NewtConf.h>
	$<$<PLATFORM_ID:Windows>: src/newt_core/incs/win/config.h src/newt_core/incs/win/NewtConf.h>
)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

#
# ---- lex and yacc -----------------------------------------------------------
#

if (${CMAKE_SYSTEM_NAME} STREQUAL "Windows")
	# avoid Lex and Yacc on Windows as they are a pain to install.
else ()
	find_package(FLEX REQUIRED)
	flex_target(lexer src/parser/newt.l ${CMAKE_CURRENT_BINARY_DIR}/newt.l.c)

	find_package(BISON REQUIRED)
	bison_target(parser src/parser/newt.y ${CMAKE_CURRENT_BINARY_DIR}/y.tab.c)

	add_flex_bison_dependency(lexer parser)
endif ()

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

# for the generated version.h
target_include_directories (libnewt64 PUBLIC ${CMAKE_CURRENT_BINARY_DIR})

if (${CMAKE_SYSTEM_NAME} STREQUAL "Windows")
	target_compile_options(libnewt64 PUBLIC "/bigobj")
	target_compile_definitions(libnewt64 PRIVATE WIN32_LEAN_AND_MEAN=1 _CRT_SECURE_NO_WARNINGS=1)
endif ()

target_include_directories (libnewt64 PUBLIC
	src/newt_core/incs/
	src/parser/
	src/
	$<$<PLATFORM_ID:Darwin>:  src/newt_core/incs/darwin >
	$<$<PLATFORM_ID:Linux>:   src/newt_core/incs/darwin >
	$<$<PLATFORM_ID:OpenBSD>:   src/newt_core/incs/darwin >
	$<$<PLATFORM_ID:Windows>: src/newt_core/incs/win >
)

target_link_libraries(libnewt64 PUBLIC 
	$<$<PLATFORM_ID:Darwin>:  >
	$<$<PLATFORM_ID:Linux>:   >
	$<$<PLATFORM_ID:OpenBSD>:   >
	$<$<PLATFORM_ID:Windows>: shlwapi >
)

target_compile_definitions(libnewt64 PRIVATE
	$<$<PLATFORM_ID:Darwin>:  TARGET_OS_DARWIN=1 >
	$<$<PLATFORM_ID:Linux>:   TARGET_OS_LINUX=1 HAVE_ENDIAN_H=1>
	$<$<PLATFORM_ID:OpenBSD>: TARGET_OS_LINUX=1 HAVE_ENDIAN_H=1>
	$<$<PLATFORM_ID:Windows>: TARGET_OS_WINDOWS=1 >
)

install (TARGETS libnewt64
	ARCHIVE DESTINATION ${NEWT64_INSTALL_PREFIX}lib
)

install (DIRECTORY src/newt_core/incs/
	DESTINATION ${NEWT64_INSTALL_PREFIX}include/newt64
)

#
# ---- newt64 command line app ------------------------------------------------
#

add_executable(newt64
	src/main.c
)

if (${CMAKE_SYSTEM_NAME} STREQUAL "Windows")
	target_compile_options(newt64 PUBLIC "/bigobj")
	target_compile_definitions(newt64 PRIVATE WIN32_LEAN_AND_MEAN=1 _CRT_SECURE_NO_WARNINGS=1)
endif ()

target_include_directories (newt64 PUBLIC
	src/newt_core/incs/
	src/parser/
	src/
	$<$<PLATFORM_ID:Darwin>:  src/newt_core/incs/darwin >
	$<$<PLATFORM_ID:Linux>:   src/newt_core/incs/darwin >
	$<$<PLATFORM_ID:OpenBSD>: src/newt_core/incs/darwin >
	$<$<PLATFORM_ID:Windows>: src/newt_core/incs/win >
)

target_link_libraries(newt64
	PUBLIC 
	libnewt64
	$<$<PLATFORM_ID:Linux>:dl>
)

install (TARGETS newt64
    RUNTIME DESTINATION ${NEWT64_INSTALL_PREFIX}bin
)

if (${CMAKE_SYSTEM_NAME} STREQUAL "Windows")
	install (FILES Newt64Config.cmake
		DESTINATION ${NEWT64_INSTALL_PREFIX}lib/cmake/Newt64
	)
	set (CMAKE_EXPORT_PACKAGE_REGISTRY 1)
	export(PACKAGE Newt64)
endif()

#
# ---- extensions -------------------------------------------------------------
#

# Require("protoFILE") loads protoFILE<DYLIBSUFFIX> from the NEWTLIB path with
# dlopen(). The extensions call back into newt64, which exports its symbols
# (ENABLE_EXPORTS: -rdynamic on Linux).

if (${CMAKE_SYSTEM_NAME} STREQUAL "Windows")
	set (NEWT64_BUILD_EXTENSIONS_DEFAULT OFF)
else ()
	set (NEWT64_BUILD_EXTENSIONS_DEFAULT ON)
endif ()
option (NEWT64_BUILD_EXTENSIONS "Build the loadable extensions in ext/" ${NEWT64_BUILD_EXTENSIONS_DEFAULT})

if (NEWT64_BUILD_EXTENSIONS)

	set_target_properties (newt64 PROPERTIES ENABLE_EXPORTS ON)

	foreach (ext protoFILE protoREGEX)
		add_library (${ext} MODULE ext/${ext}/${ext}.c)
		# Must match __DYLIBSUFFIX__ in the platform config.h, which is
		# ".dylib" for every platform that uses incs/darwin.
		set_target_properties (${ext} PROPERTIES PREFIX "" SUFFIX ".dylib")
		# Only the headers: linking libnewt64 in would give each extension
		# its own copy of the interpreter (and fails where it is not PIC).
		target_include_directories (${ext} PRIVATE
			$<TARGET_PROPERTY:libnewt64,INTERFACE_INCLUDE_DIRECTORIES>
		)
		if (APPLE)
			# check the NEWT functions against newt64 at link time
			target_link_options (${ext} PRIVATE "LINKER:-bundle_loader,$<TARGET_FILE:newt64>")
			add_dependencies (${ext} newt64)
		endif ()
	endforeach ()

	# __LIBDIR__ in config.h: /usr/local/lib/newt64
	install (TARGETS protoFILE protoREGEX
		LIBRARY DESTINATION ${NEWT64_INSTALL_PREFIX}lib/newt64
	)

endif ()

#
# ---- tests ------------------------------------------------------------------
#

# Each tests/*.newt script prints "FAIL" for a failed check and "ALL OK" when
# it reaches its end. newt64 exits with 0 even after an uncaught exception, so
# a test passes only when "ALL OK" appears. Scripts that write files put them
# in NEWT64_TEST_TMP, the build directory. Run the tests with ctest.

enable_testing ()

file (GLOB NEWT64_TESTS CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/tests/*.newt)
if (NEWT64_BUILD_EXTENSIONS)
	file (GLOB NEWT64_EXT_TESTS CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/tests/ext/*.newt)
	list (APPEND NEWT64_TESTS ${NEWT64_EXT_TESTS})
endif ()

foreach (test ${NEWT64_TESTS})
	get_filename_component (test_name ${test} NAME_WE)
	get_filename_component (test_dir ${test} DIRECTORY)
	add_test (NAME ${test_name}
		COMMAND ${CMAKE_COMMAND} -E env NEWTLIB=$<TARGET_FILE_DIR:newt64>
			NEWT64_TEST_TMP=${CMAKE_CURRENT_BINARY_DIR}
			$<TARGET_FILE:newt64> ${test}
		WORKING_DIRECTORY ${test_dir}
	)
	set_tests_properties (${test_name} PROPERTIES
		PASS_REGULAR_EXPRESSION "ALL OK"
		FAIL_REGULAR_EXPRESSION "FAIL"
	)
endforeach ()
