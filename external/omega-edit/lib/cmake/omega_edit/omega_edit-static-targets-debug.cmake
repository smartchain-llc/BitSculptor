#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "omega_edit::omega_edit" for configuration "Debug"
set_property(TARGET omega_edit::omega_edit APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(omega_edit::omega_edit PROPERTIES
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/lib/libomega_edit.so.0.9.78"
  IMPORTED_SONAME_DEBUG "libomega_edit.so.0"
  )

list(APPEND _IMPORT_CHECK_TARGETS omega_edit::omega_edit )
list(APPEND _IMPORT_CHECK_FILES_FOR_omega_edit::omega_edit "${_IMPORT_PREFIX}/lib/libomega_edit.so.0.9.78" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
