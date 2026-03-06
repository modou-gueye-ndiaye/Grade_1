//  Chapitre 6 : exemple pour illustrer les notions de portée, de niveau et de
//    durée de vie.

#include <stdio.h>
#include <stdlib.h>

int n = 68;

void p(int k) {
  printf("%d", n + k);
  ++n;
}

int main() {
  int n = 19;
  for (int n = 0; n < 3; ++n) {
    p(n);
  }
  printf("%d", n);
  return EXIT_SUCCESS;
}
