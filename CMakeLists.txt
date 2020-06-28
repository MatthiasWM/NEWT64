#
# Use a single CMake setup to compile Newt/64 on all supported platforms.
# 

cmake_minimum_required(VERSION 3.15)
cmake_policy(SET CMP0091 NEW)

set (CMAKE_CXX_STANDARD 14)

set (CMAKE_OSX_ARCHITECTURES=x86_64)
set (CMAKE_OSX_DEPLOYMENT_TARGET 10.9)

set (CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

project("Newt64" VERSION "2020.4.5")

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
    src/newt_core/incs/win/config.h
    src/newt_core/incs/win/NewtConf.h
    src/newt_core/incs/Darwin/config.h
    src/newt_core/incs/Darwin/NewtConf.h
    )

#set_source_files_properties(${CMAKE_CURRENT_SOURCE_DIR}/app/Version.h PROPERTIES GENERATED TRUE)

#string(TIMESTAMP COMPILE_TIME_YYYY "%Y")
#string(TIMESTAMP COMPILE_TIME_MM "%m")
#string(TIMESTAMP COMPILE_TIME_DD "%d")

#configure_file(
#		${CMAKE_CURRENT_SOURCE_DIR}/app/Version.h.in
#		${CMAKE_CURRENT_SOURCE_DIR}/app/Version.h
#)


    add_executable(newt
        ${sources}
        src/main.c
    )
    add_library(newt64
        ${sources}
    )


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
if (APPLE)
    set_property(GLOBAL PROPERTY USE_FOLDERS ON)
    source_group(TREE "${CMAKE_SOURCE_DIR}" PREFIX "Sources" FILES ${sources})

    find_package(FLEX REQUIRED)
flex_target(lexer src/parser/newt.l ${CMAKE_CURRENT_BINARY_DIR}/newt.l.c)

find_package(BISON REQUIRED)
bison_target(parser src/parser/newt.y ${CMAKE_CURRENT_BINARY_DIR}/y.tab.c)

add_flex_bison_dependency(lexer parser)


    target_include_directories(
        newt PUBLIC
        src/newt_core/incs/Darwin
    )
    target_include_directories(
        newt64 PUBLIC
        src/newt_core/incs/Darwin
    )
    target_link_libraries(newt
	    PUBLIC iconv
    )
elseif (UNIX)

    set_property(GLOBAL PROPERTY USE_FOLDERS ON)
    source_group(TREE "${CMAKE_SOURCE_DIR}" PREFIX "Sources" FILES ${sources})

find_package(FLEX REQUIRED)
flex_target(lexer src/parser/newt.l ${CMAKE_CURRENT_BINARY_DIR}/newt.l.c)

find_package(BISON REQUIRED)
bison_target(parser src/parser/newt.y ${CMAKE_CURRENT_BINARY_DIR}/y.tab.c)

add_flex_bison_dependency(lexer parser)

    target_include_directories(
        newt PUBLIC
        src/newt_core/incs/Darwin
    )
    target_include_directories(
        newt64 PUBLIC
        src/newt_core/incs/Darwin
    )
    target_link_libraries(newt
	    PUBLIC /usr/local/lib/libiconv.a dl
    )
elseif (WIN32)

    set_property(GLOBAL PROPERTY USE_FOLDERS ON)
    source_group(TREE "${CMAKE_SOURCE_DIR}" PREFIX "Sources" FILES ${sources} Resources/MSWindows/Einstein.rc.in)

set(FLEX_ROOT c:/GnuWin32/bin)
        find_package(FLEX REQUIRED)
flex_target(lexer src/parser/newt.l ${CMAKE_CURRENT_BINARY_DIR}/newt.l.c)

set(BISON_ROOT c:/GnuWin32/bin)
find_package(BISON REQUIRED)
bison_target(parser src/parser/newt.y ${CMAKE_CURRENT_BINARY_DIR}/y.tab.c)

add_flex_bison_dependency(lexer parser)

    target_include_directories(
        newt PUBLIC
        src/newt_core/incs/win
    )
    target_include_directories(
        newt64 PUBLIC
        src/newt_core/incs/win
    )
    target_link_libraries(newt
        shlwapi
    )
    target_link_libraries(newt64
        shlwapi
    )

else()

	message ("NEWT/64 CMake is not configured for this platform.")

endif(APPLE)



