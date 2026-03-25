#include <stdio.h>
#include <stdlib.h>

int numberlines(const char *filename);

int main(int argc, char *argv[]) {
  int r = EXIT_SUCCESS;
  
  for (int k = 1; k < argc; ++k) {
    const char * const a = argv[k];
    if (numberlines(a) != 0) {
      fprintf(stderr, "An error occurred while processing '%s'\n", a);
      r = EXIT_FAILURE;
    }
  }
  return r;
}
