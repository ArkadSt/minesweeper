# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\appguiMinesweeper_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\appguiMinesweeper_autogen.dir\\ParseCache.txt"
  "appguiMinesweeper_autogen"
  )
endif()
