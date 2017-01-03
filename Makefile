.PHONEY: test

CC       ?=
CFLAGS   += -pedantic -W -Wall -Werror -Wextra -std=gnu11
CPPFLAGS += -Isrc
LIB       = src/libcursor.a
LIB_SRC   = $(wildcard src/*.c)
LIB_OBJ   = $(patsubst %.c,%.o,$(LIB_SRC))
TESTER    = tests/cursor_test
TEST_SRC  = $(wildcard tests/*.c)
TEST_OBJ  = $(patsubst %.c,%.o,$(TEST_SRC))

all: $(TESTER)

$(LIB): $(LIB_OBJ)
	ar rcs $@ $^

src/libcursor.a: $(LIB_OBJ)

$(TESTER): $(TEST_OBJ) $(LIB)
	$(CC) -o $(TESTER) $(TEST_OBJ) $(LIB_OBJ)

test: $(TESTER)
	$(TESTER)

clean:
	rm -f $(LIB_OBJ)
	rm -f $(TEST_OBJ)
	rm -f $(LIB)
