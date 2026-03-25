//  Chapitre 3, Types scalaires, Types réels complexes.

#include <complex.h>
#include <stdio.h>
#include <stdlib.h>

#define XVALUE 12345678901234567890.1
#define YVALUE 98765432109876543210.9
#define ZVALUE (XVALUE + I * YVALUE)

int main() {
  //
  float complex zf = (float) XVALUE + I * (float) YVALUE;
  double complex z = ZVALUE;
  long double complex zl = ZVALUE;
  printf("%f %f\n", crealf(zf), cimagf(zf));
  printf("%lf %lf\n", creal(z), cimag(z));
  printf("%Lf %Lf\n", creall(zl), cimagl(zl));
  //
  double complex z2 = 1.0 + I * 2.0;
  printf("%lf %lf\n", creal(z2), cimag(z2));
  z2 = z2 * z2;
  printf("%lf %lf\n", creal(z2), cimag(z2));
  //
  return EXIT_SUCCESS;
}
