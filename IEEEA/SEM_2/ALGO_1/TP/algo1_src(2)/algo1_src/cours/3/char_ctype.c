//  Chapitre 3, Types scalaires, Types caractères.

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define CHECK(fun, c)                                                          \
  if (fun(c)) {                                                                \
    printf(" " #fun);                                                          \
  }

#define CONV(fun, c)                                                           \
  printf(" " #fun " -> « %c »", fun(c));

int main() {
  int c;
  while ((c = getchar()) != EOF) {
    if (isprint(c)) {
      printf("« %c »\t", c);
    } else {
      printf("[%3d]\t", c);
    }
    CHECK(isalnum, c);
    CHECK(isalpha, c);
    CHECK(isblank, c);
    CHECK(iscntrl, c);
    CHECK(isdigit, c);
    CHECK(isgraph, c);
    CHECK(islower, c);
    CHECK(isprint, c);
    CHECK(ispunct, c);
    CHECK(isspace, c);
    CHECK(isupper, c);
    CHECK(isxdigit, c);
    if (isprint(c)) {
      printf("\n\t");
      CONV(tolower, c);
      CONV(toupper, c);
    }
    printf("\n");
  }
  return EXIT_SUCCESS;
}
