# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\calc_app_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\calc_app_autogen.dir\\ParseCache.txt"
  "calc_app_autogen"
  )
endif()
