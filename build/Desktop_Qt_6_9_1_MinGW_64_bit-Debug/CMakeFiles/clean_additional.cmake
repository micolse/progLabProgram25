# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\progLabProgram25_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\progLabProgram25_autogen.dir\\ParseCache.txt"
  "progLabProgram25_autogen"
  )
endif()
