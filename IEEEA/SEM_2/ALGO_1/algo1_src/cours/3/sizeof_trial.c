//  Chapitre 3, Préséance des opérateurs, opérateur sizeof et type size_t.

#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("%zu\n", sizeof(char));
  printf("%zu\n", sizeof(short int));
  printf("%zu\n", sizeof(int));
  printf("%zu\n", sizeof(long int));
  printf("%zu\n", sizeof(long long int));
  printf("%zu\n", sizeof(int8_t));
  printf("%zu\n", sizeof(int16_t));
  printf("%zu\n", sizeof(int32_t));
  printf("%zu\n", sizeof(int64_t));
  printf("%zu\n", sizeof(float));
  printf("%zu\n", sizeof(double));
  printf("%zu\n", sizeof(long double));
  return EXIT_SUCCESS;
}
