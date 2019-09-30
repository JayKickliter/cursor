cmake_minimum_required(VERSION 3.1)
enable_testing()

project(Cursor
  VERSION 1.0
  LANGUAGES C
  )

set(CMAKE_C_STANDARD 11)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(examples)
add_subdirectory(src)
add_subdirectory(tests)
