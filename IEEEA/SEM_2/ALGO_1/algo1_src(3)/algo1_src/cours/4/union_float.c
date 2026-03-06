//  Chapitre 4, Unions.

#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

//  float_show : affiche les bits de chacun des bytes sur lesquels est codé le
//    réel flottant x.
void float_show(float x);

int main() {
  float_show(0.0);
  float_show(-0.0);
  float_show(1.0);
  float_show(-1.0);
  float_show((float) (1.0 / 0.0));
  float_show((float) (-1.0 / 0.0));
  float_show((float) acos(2.0));
  float_show((float) (0.0 / 0.0));
  return EXIT_SUCCESS;
}

void float_show(float x) {
  union {
    float x;
    unsigned char c[sizeof(float)];
  } u;
  u.x = x;
  printf("%8.4f", u.x);
  //  IB : 0 <= k && k <= sizeof(float)
  //    && les bits des k premiers bytes sur lesquels est codé x ont été
  //        affichés
  //  QC : k
  for (size_t k = 0; k < sizeof(float); ++k) {
    printf(" ");
    printf("%3u ", u.c[k]);
    int j = CHAR_BIT;
    //  IB : 0 <= k && k < sizeof(float)
    //    && 0 <= j && j <= CHAR_BIT
    //    && les bits des k premiers bytes sur lesquels est codé x ont été
    //        affichés
    //    && les bits CHAR_BIT - 1 à j du k + 1-ième byte sur lequel est codé x
    //        ont été affichés
    //  QC : j
    while (j != 0) {
      --j;
      printf("%1u", (u.c[k] & (1U << j)) != 0);
    }
  }
  printf("\n");
}
