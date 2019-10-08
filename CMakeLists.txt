cmake_minimum_required(VERSION 3.1)

project(Cursor
  VERSION 1.0
  LANGUAGES C
  )

include(CTest)


set(CMAKE_C_STANDARD 11)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(src)

if(${BUILD_TESTING})
add_subdirectory(tests)
add_subdirectory(examples)
endif(${BUILD_TESTING})

