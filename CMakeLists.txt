cmake_minimum_required(VERSION 3.1)
if(${BUILD_TESTING})
enable_testing()
endif(${BUILD_TESTING})

project(Cursor
  VERSION 1.0
  LANGUAGES C
  )

set(CMAKE_C_STANDARD 11)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(src)

if(${BUILD_TESTING})
add_subdirectory(tests)
add_subdirectory(examples)
endif(${BUILD_TESTING})

