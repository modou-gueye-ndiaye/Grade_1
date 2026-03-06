CC = gcc
CFLAGS = -std=c2x \
  -Wall -Wconversion -Werror -Wextra -Wpedantic -Wwrite-strings -O2
LDFLAGS =
sources = $(wildcard *.c)
executables = $(patsubst %.c, %, $(sources))

all: $(executables)

clean:
	$(RM) $(executables)

.c:
	$(CC) $(CFLAGS) $< $(LDFLAGS) -o $@
