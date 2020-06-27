#
# Use a single CMake setup to compile Newt/64 on all supported platforms.
# 

cmake_minimum_required(VERSION 3.15)
cmake_policy(SET CMP0091 NEW)

set (CMAKE_CXX_STANDARD 14)

set (CMAKE_OSX_ARCHITECTURES=x86_64)
set (CMAKE_OSX_DEPLOYMENT_TARGET 10.9)

set (CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

project("Newt64" VERSION "2020.4.4")

find_package(FLEX REQUIRED)
flex_target(lexer src/parser/newt.l ${CMAKE_CURRENT_BINARY_DIR}/newt.l.c)

find_package(BISON REQUIRED)
bison_target(parser src/parser/newt.y ${CMAKE_CURRENT_BINARY_DIR}/y.tab.c)

add_flex_bison_dependency(lexer parser)

set ( sources
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
set ( headers
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
    src/newt_core/config.h
    )

#set_source_files_properties(${CMAKE_CURRENT_SOURCE_DIR}/app/Version.h PROPERTIES GENERATED TRUE)

#string(TIMESTAMP COMPILE_TIME_YYYY "%Y")
#string(TIMESTAMP COMPILE_TIME_MM "%m")
#string(TIMESTAMP COMPILE_TIME_DD "%d")

#configure_file(
#		${CMAKE_CURRENT_SOURCE_DIR}/app/Version.h.in
#		${CMAKE_CURRENT_SOURCE_DIR}/app/Version.h
#)


if (APPLE)
    set_property(GLOBAL PROPERTY USE_FOLDERS ON)
    source_group(TREE "${CMAKE_SOURCE_DIR}" PREFIX "Sources" FILES ${sources})

	add_executable(newt
        ${sources}
        src/main.c
    )
	add_library(newt64
        ${sources}
    )

	# how to compile and link
#	target_compile_options(newt PUBLIC -Wall)
#	target_compile_definitions(newt PRIVATE TARGET_UI_FLTK=1 NO_PORT_AUDIO NO_X11 TARGET_OS_OPENSTEP=1 TARGET_OS_MAC=1 NS_BLOCK_ASSERTIONS=1)
    target_include_directories(
        newt PUBLIC
        src/newt_core/incs/Darwin
    )
    target_include_directories(
        newt64 PUBLIC
        src/newt_core/incs/Darwin
    )
	target_link_libraries(newt
        iconv
    )

elseif (UNIX)

	# configure to use FLTK as the GUI
	set(FLTK_SKIP_OPENGL true)
	set(FLTK_FLUID_EXECUTABLE /usr/local/bin/fluid)
	find_package(FLTK REQUIRED NO_MODULE)

    build_with_fluid(TFLAppUI app)
    build_with_fluid(TFLSettingsUI app)
    build_with_fluid(TFLToolkitUI Toolkit)

	# additional source code
	list (APPEND sources
			# calling native functions (very limited support in this version of EInsten)
			Emulator/NativeCalls/NativeCallsDefines.h
			Emulator/NativeCalls/TNativeCalls.cpp
			Emulator/NativeCalls/TNativeCalls.h
			# Unix sound support
			Emulator/Sound/TPulseAudioSoundManager.cpp
			Emulator/Sound/TPulseAudioSoundManager.h
			# Network card emulations
			Emulator/Network/TUsermodeNetwork.cpp
			Emulator/Network/TUsermodeNetwork.h
			)
    set_property(GLOBAL PROPERTY USE_FOLDERS ON)
    source_group(TREE "${CMAKE_SOURCE_DIR}" PREFIX "Sources" FILES ${sources})

	# create the application
	add_executable(Einstein ${sources})

    # add all the source file that Fluid generates for us
    #add_dependencies(Einstein ${fluid_dependencies})

	# how to compile and link
	target_compile_options(Einstein PUBLIC -Wall -Wno-multichar)
	target_compile_definitions(Einstein PRIVATE TARGET_UI_FLTK=1 TARGET_OS_LINUX=1)
	target_link_libraries(Einstein
			fltk
			pulse # sound
			)

    if ( USE_NEWT64 MATCHES true )
        message(STATUS ${newt64_lib_path})
        target_include_directories(Einstein SYSTEM PUBLIC ${newt64_incl_path} ${newt64_incl_path}/darwin)
        target_link_libraries(Einstein
            ${newt64_lib}
            iconv
            )
        target_compile_definitions(Einstein PRIVATE USE_NEWT64=1)
    endif ()

elseif (WIN32)

	# configure to use FLTK as the GUI
	set(FLTK_DIR "C:/Program Files/FLTK")
    set(FLTK_FLUID_EXECUTABLE "C:/Program Files/FLTK/bin/fluid.exe")
	set(FLTK_SKIP_OPENGL true)
	find_package(FLTK REQUIRED NO_MODULE)

    build_with_fluid(TFLAppUI app)
    build_with_fluid(TFLSettingsUI app)
    build_with_fluid(TFLToolkitUI Toolkit)

	# additional source code
	list (APPEND sources
			# calling native functions (very limited support in this version of EInsten)
			Emulator/NativeCalls/NativeCallsDefines.h
			Emulator/NativeCalls/TNativeCalls.cpp
			Emulator/NativeCalls/TNativeCalls.h
			# Windows sound support
			Emulator/Sound/TWaveSoundManager.cpp
			Emulator/Sound/TWaveSoundManager.h
			# Network card emulations
			Emulator/Network/TUsermodeNetwork.cpp
			Emulator/Network/TUsermodeNetwork.h
			)
    set_property(GLOBAL PROPERTY USE_FOLDERS ON)
    source_group(TREE "${CMAKE_SOURCE_DIR}" PREFIX "Sources" FILES ${sources} Resources/MSWindows/Einstein.rc.in)

	# Create a resources file for Windows
	configure_file(
			Resources/MSWindows/Einstein.rc.in
			Einstein.rc
	)

	# create the application
	add_executable(Einstein WIN32
			${sources} ${data}
			${CMAKE_CURRENT_BINARY_DIR}/Einstein.rc
			)

    # add all the source file that Fluid generates for us
    add_dependencies(Einstein ${fluid_dependencies})

	# how to compile and link
	target_compile_options(Einstein PUBLIC "/bigobj")
	target_compile_definitions(Einstein PRIVATE TARGET_UI_FLTK=1 TARGET_OS_WIN32=1 WIN32_LEAN_AND_MEAN=1 _CRT_SECURE_NO_WARNINGS=1)
	target_link_libraries(Einstein
			# this vvv always includes the debug version, even in release mode
			fltk
			# alternatively, this loads the correct library but needs additional libs that would be included automatically in the line above
			#"${FLTK_BASE_LIBRARY_RELEASE}" # FIXME: or it will select the debug version even in release mode!
			#comctl32
			#ws2_32
			# end of alternative
			winmm
			)
	if (CMAKE_BUILD_TYPE MATCHES Debug)
		target_link_options(Einstein PUBLIC /NODEFAULTLIB:msvcrt.lib )
	else()
		target_link_options(Einstein PUBLIC /NODEFAULTLIB:libcmtd.lib /NODEFAULTLIB:msvcrtd.lib)
	endif()

else()

	message ("Einstein CMake is not configured for this platform.")

endif(APPLE)


target_include_directories(
    newt PUBLIC
    src/newt_core/incs/
    src/parser/
    src/
)
target_include_directories(
    newt64 PUBLIC
    src/newt_core/incs/
    src/parser/
    src/
)

