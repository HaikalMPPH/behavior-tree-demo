cmake_minimum_required (VERSION 3.20)

project (behavior-tree-demo)

set (CMAKE_CXX_FLAGS "-Wall -Werror -O3")
set (CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} -g")
set (CMAKE_C_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} -O3 -pedantic")

file (
  GLOB source
  "src/*.hpp" "src/*/*.hpp" "src/*/*/*.hpp"
  "src/*.cpp" "src/*/*.cpp" "src/*/*/*.cpp"
)

include_directories (
  "/usr/include/"
  "src/"
)


add_executable (main ${source})

target_link_libraries (
  main
  -lraylib
)
