CC = gcc
CFLAGS = -std=c2x \
  -Wall -Wconversion -Werror -Wextra -Wpedantic -Wwrite-strings -O2
LDFLAGS = -lm
sources = $(wildcard *.c)
executables = $(patsubst %.c, %, $(sources))

.PHONY: all clean

all: $(executables)

clean:
	$(RM) $(executables)

.c:
	$(CC) $(CFLAGS) $< $(LDFLAGS) -o $@
