//  Chapitre 3, Erreurs, terminaisons et diagnostics, Erreurs.

#include <errno.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  //
  perror(nullptr);
  //
  strtol("999999999999999999999999999999", nullptr, 10);
  perror(nullptr);
  acos(-2.0);
  perror(nullptr);
  //
  perror(nullptr);
  errno = 0;
  perror(nullptr);
  //
  return EXIT_SUCCESS;
}
