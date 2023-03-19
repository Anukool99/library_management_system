# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\LibraryManagementSoftware_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\LibraryManagementSoftware_autogen.dir\\ParseCache.txt"
  "LibraryManagementSoftware_autogen"
  )
endif()
