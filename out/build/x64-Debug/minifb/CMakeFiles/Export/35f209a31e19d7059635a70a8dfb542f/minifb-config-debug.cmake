#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "minifb::minifb" for configuration "Debug"
set_property(TARGET minifb::minifb APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(minifb::minifb PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "C;CXX"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/lib/minifb.lib"
  )

list(APPEND _cmake_import_check_targets minifb::minifb )
list(APPEND _cmake_import_check_files_for_minifb::minifb "${_IMPORT_PREFIX}/lib/minifb.lib" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
