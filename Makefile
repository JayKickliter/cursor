# Travis does not set CC to custom installed c-compiler.
# It also does not allow you to override CC. The only option
# is to use COMPILER which travis does allow you to export.
COMPILER ?= $(CC)
CFLAGS   += -Isrc -pedantic -W -Wall -Werror -Wextra -std=gnu11
SRC	  = $(wildcard src/*.c)
OBJ       = $(patsubst %.c,%.o,$(SRC))
TEST      = src/cursor_test

all: $(TEST)

%.o: %.c
	$(COMPILER) $(CFLAGS) -c $< -o $@

$(TEST): $(OBJ)
	$(COMPILER) -o $(TEST) $(OBJ)

test: $(TEST)
	$(TEST)

clean:
	rm -f $(TEST)
	rm -f $(OBJ)
