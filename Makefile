.PHONEY: test

CC       ?=
CFLAGS   += -pedantic -W -Wall -Werror -Wextra -std=c11
CPPFLAGS += -Isrc
LIB       = src/libbufrw.a
LIB_SRC   = $(wildcard src/*.c)
LIB_OBJ   = $(patsubst %.c,%.o,$(LIB_SRC))
TESTER    = tests/tester
TEST_SRC  = $(wildcard tests/*.c)
TEST_OBJ  = $(patsubst %.c,%.o,$(TEST_SRC))

all: $(TESTER)

$(LIB): $(LIB_OBJ)
	ar rcs $@ $^

src/libbufrw.a: $(LIB_OBJ)

$(TESTER): $(TEST_OBJ) $(LIB)
	$(CC) -o $(TESTER) $(TEST_OBJ) $(LIB_OBJ)

test: $(TESTER)
	$(TESTER)
