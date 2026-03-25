#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#define FNAME "eof.txt"

FILE *open_or_exit(const char *filename, const char *mode) {
  FILE *f = fopen(filename, mode);
  if (f == nullptr) {
    fprintf(stderr, "*** Error while opening file '%s' in mode '%s'\n",
        filename, mode);
    exit(EXIT_FAILURE);
  }
  return f;
}

void close_or_exit(FILE *f) {
  if (fclose(f) != 0) {
    fprintf(stderr, "*** Error at closing\n");
    exit(EXIT_FAILURE);
  }
}

void remove_or_exit(const char *filename) {
  if (remove(filename) != 0) {
    fprintf(stderr, "*** Error at removing file '%s'\n", filename);
    exit(EXIT_FAILURE);
  }
}

int main() {
  const char *readmode[] = {
    "r", "rb"
  };
  const char *writemode[] = {
    "w", "wb"
  };
  printf("\nCheck fput + fgetc\n");
  for (size_t w = 0; w < sizeof writemode / sizeof *writemode; ++w) {
    for (size_t r = 0; r < sizeof readmode / sizeof *readmode; ++r) {
      printf("Check with \"%s\" and \"%s\"\n", writemode[w], readmode[r]);
      {
        FILE *f = open_or_exit(FNAME, writemode[w]);
        int c = '\0';
        while (c <= SCHAR_MAX && fputc(c, f) != EOF) {
          ++c;
        }
        printf("--- Write stopped with c=%d\n", c);
        close_or_exit(f);
      }
      {
        FILE *f = open_or_exit(FNAME, readmode[r]);
        int d = '\0';
        int c;
        while ((c = fgetc(f)) != EOF && c == d) {
          ++d;
        }
        printf("--- Read stopped with c=%d d=%d\n", c, d);
        close_or_exit(f);
      }
      remove_or_exit(FNAME);
    }
  }
  printf("\nCheck fwrite + fread\n");
  for (size_t w = 0; w < sizeof writemode / sizeof *writemode; ++w) {
    for (size_t r = 0; r < sizeof readmode / sizeof *readmode; ++r) {
      printf("Check with \"%s\" and \"%s\"\n", writemode[w], readmode[r]);
      {
        FILE *f = open_or_exit(FNAME, writemode[w]);
        char a[SCHAR_MAX + 1];
        for (int c = '\0'; c <= SCHAR_MAX; ++c) {
          a[c] = (char) c;
        }
        size_t d = fwrite(a, 1, SCHAR_MAX + 1, f);
        printf("--- Returned value from fwrite is %zu\n", d);
        close_or_exit(f);
      }
      {
        FILE *f = open_or_exit(FNAME, readmode[r]);
        char a[SCHAR_MAX + 1];
        size_t d = fread(a, 1, SCHAR_MAX + 1, f);
        printf("--- Returned value from fread is %zu\n", d);
        close_or_exit(f);
      }
      remove_or_exit(FNAME);
    }
  }
  exit(EXIT_SUCCESS);
}
