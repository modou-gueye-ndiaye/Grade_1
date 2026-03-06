CC = gcc
CFLAGS = -std=c2x \
  -Wall -Wconversion -Werror -Wextra -Wpedantic -Wwrite-strings -O2
LDFLAGS =
objects = x.o y1.o y2.o z.o
executable = x

all: $(executable)

clean:
	$(RM) $(objects) $(executable)

dist: clean
	zip "$(CURDIR).zip" *.c *.h makefile

$(executable): $(objects)
	$(CC) $(objects) $(LDFLAGS) -o $(executable)

x.o: x.c y1.h y2.h
y1.o: y1.c y1.h z.h
y2.o: y2.c y2.h z.h
z.o: z.c z.h
