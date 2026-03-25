//  Chapitre 3, Types scalaires, Types entiers.

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  //
  signed char sc = CHAR_MAX;
  short int ss = SHRT_MAX;
  int si = INT_MAX;
  long int sl = LONG_MAX;
  long long int sll = LLONG_MAX;
  printf("%hhd\n", sc);
  printf("%hd\n", ss);
  printf("%d\n", si);
  printf("%ld\n", sl);
  printf("%lld\n", sll);
  //
  unsigned char uc = UCHAR_MAX;
  unsigned short int us = USHRT_MAX;
  unsigned int ui = UINT_MAX;
  unsigned long int ul = ULONG_MAX;
  unsigned long long int ull = ULLONG_MAX;
  printf("%hhu\n", uc);
  printf("%hu\n", us);
  printf("%u\n", ui);
  printf("%lu\n", ul);
  printf("%llu\n", ull);
  //
  //  même chose pour scanf
  //
  return EXIT_SUCCESS;
}
