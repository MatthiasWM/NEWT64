


get_filename_component(libCMakePath ${CMAKE_CURRENT_LIST_DIR} DIRECTORY)
get_filename_component(libPath ${libCMakePath} DIRECTORY)
get_filename_component(basePath ${libPath} DIRECTORY)
set (CMAKE_PREFIX_PATH ${basePath})

message("Newt64 install directory found at " ${basePath})

