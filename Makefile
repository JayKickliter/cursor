# Travis does not set CC to custom installed c-compiler.
# It also does not allow you to override CC. The only option
# is to use COMPILER which travis does allow you to export.
COMPILER ?= $(CC)
CFLAGS   += -Isrc -pedantic -W -Wall -Werror -Wextra -std=gnu11
SRC	  = $(wildcard src/*.c)
OBJ       = $(patsubst %.c,%.o,$(SRC))
TEST      = tests/test
EXAMPLE   = examples/simple

# Enable coverage reporting when GENERATE_COVERAGE=ON
# GENERATE_COVERAGE is defined to ON when building on travis
# with gcc
ifeq ($(COVERAGE),ON)
CFLAGS += --coverage
endif


all: $(EXAMPLE) $(TEST)

%.o: %.c
	$(COMPILER) $(CFLAGS) -c $< -o $@

$(TEST): $(OBJ) tests/test.o
	$(COMPILER) $(CFLAGS) -o $(TEST) $^

$(EXAMPLE): $(OBJ) examples/simple.o
	$(COMPILER) $(CFLAGS) -o $(EXAMPLE) $^

test: $(TEST) $(EXAMPLE)
	$(TEST)
	$(EXAMPLE)

clean:
	find . -name *.o | xargs rm
	find . -name *.gcda* | xargs rm
	find . -name *.gcno* | xargs rm
	rm -f $(TEST)
	rm -f $(EXAMPLE)
