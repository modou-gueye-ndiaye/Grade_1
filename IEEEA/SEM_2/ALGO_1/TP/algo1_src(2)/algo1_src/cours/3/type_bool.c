//  Chapitre 3, Types scalaires, Type booléen.

#include <stdio.h>
#include <stdlib.h>

int main() {
  //
  bool b = false;
  printf("%d\n", b);
  b = !b;
  printf("%d\n", b);
  //
  int k = 666;
  printf("%d\n", k);
  printf("%d\n", (bool) k);
  k = 0;
  printf("%d\n", (bool) k);
  //
  double x = 15.04;
  printf("%lf\n", x);
  printf("%d\n", (bool) x);
  x = 0.0;
  printf("%d\n", (bool) x);
  //
  return EXIT_SUCCESS;
}
