//  Chapitre 3, Types scalaires, Types réels flottants.

#include <float.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

//  status : affiche le statut du réel flottant x sous la forme d'une suite de
//    0 (non) et de 1 (oui) : est un nombre, est infini, est NaN, est
//    strictement négatif.
void status(double x);

//  zeroone : renvoie 0 ou 1 selon que x est nul ou non.
int zeroone(int x);

int main() {
  //
  printf("max=%le\n", DBL_MAX);
  printf("min=%le\n", DBL_MIN);
  printf("eps=%le\n", DBL_EPSILON);
  printf("dig=%d\n", DBL_DIG);
  //
  printf("%15s\n", "fins"),
  status(1.0);
  status(-1.0);
  status(0.0);
  status(-0.0);
  status(acos(-1.0));
  status(asin(-1.0));
  status(1.0 / 0.0);
  status(-(-1.0) / (-0.0));
  status(acos(2.0));
  //
  return EXIT_SUCCESS;
}

void status(double x) {
  printf("%10.6lf %d%d%d%d\n",
      x,
      zeroone(isfinite(x)),
      zeroone(isinf(x)),
      zeroone(isnan(x)),
      zeroone(signbit(x)));
}

int zeroone(int x) {
  return x != 0;
}
