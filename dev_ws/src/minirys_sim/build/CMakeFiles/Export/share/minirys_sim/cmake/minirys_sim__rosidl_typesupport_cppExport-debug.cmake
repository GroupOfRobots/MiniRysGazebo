#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "minirys_sim::minirys_sim__rosidl_typesupport_cpp" for configuration "Debug"
set_property(TARGET minirys_sim::minirys_sim__rosidl_typesupport_cpp APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(minirys_sim::minirys_sim__rosidl_typesupport_cpp PROPERTIES
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/lib/libminirys_sim__rosidl_typesupport_cpp.so"
  IMPORTED_SONAME_DEBUG "libminirys_sim__rosidl_typesupport_cpp.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS minirys_sim::minirys_sim__rosidl_typesupport_cpp )
list(APPEND _IMPORT_CHECK_FILES_FOR_minirys_sim::minirys_sim__rosidl_typesupport_cpp "${_IMPORT_PREFIX}/lib/libminirys_sim__rosidl_typesupport_cpp.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
