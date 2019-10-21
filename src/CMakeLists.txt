add_library(cursor
  cursor.c
  packing.c
  )

target_include_directories(cursor PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../include>
  $<INSTALL_INTERFACE:include>
  )

install(TARGETS cursor
  DESTINATION lib
)

add_subdirectory(include)
