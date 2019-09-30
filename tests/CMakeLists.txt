add_executable(test_cursor test.c)
target_link_libraries(test_cursor cursor)

add_test(NAME test_cursor COMMAND test_cursor)
