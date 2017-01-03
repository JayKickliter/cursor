# Travis does not set CC to custom installed c-compiler.
# It also does not allow you to override CC. The only option
# is to use COMPILER which travis does allow you to export.
COMPILER ?= $(CC)
CFLAGS   += -Isrc -pedantic -W -Wall -Werror -Wextra -std=gnu11
SRC	  = $(wildcard src/*.c)
OBJ       = $(patsubst %.c,%.o,$(SRC))
TEST      = src/cursor_test

# Enable coverage reporting when GENERATE_COVERAGE=ON
# GENERATE_COVERAGE is defined to ON when building on travis
# with gcc
ifeq ($(COVERAGE),ON)
CFLAGS += --coverage
endif


all: $(TEST)

%.o: %.c
	$(COMPILER) $(CFLAGS) -c $< -o $@

$(TEST): $(OBJ)
	$(COMPILER) $(CFLAGS) -o $(TEST) $(OBJ)

test: $(TEST)
	$(TEST)

clean:
	rm -f $(TEST)
	rm -f $(OBJ)
	rm -f src/*.gcda*
	rm -f src/*.gcno*
