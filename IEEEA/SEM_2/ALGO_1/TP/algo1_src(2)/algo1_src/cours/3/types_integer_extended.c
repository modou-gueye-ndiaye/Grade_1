//  Chapitre 3, Types scalaires, Types entiers étendus.

#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  //  entiers signés taille exacte 16 bits
  int16_t n = INT16_MAX;
  printf("%" PRId16 "\n", n);
  //  entiers signés taille maximale
  intmax_t nmax = INTMAX_MAX;
  printf("%" PRIdMAX "\n", nmax);
  //  entiers signés taille minimale 16 bits
  int_least16_t nleast = INT_LEAST16_MAX;
  printf("%" PRIdLEAST16 "\n", nleast);
  //  entiers signés rapides taille minimale 16 bits
  int_fast16_t nfast = INT_FAST16_MAX;
  printf("%" PRIdFAST16 "\n", nfast);
  //
  //  même chose sur 8, 32 et 64 bits
  //  même chose en non signé
  //  même chose pour scanf-SCN
  //
  return EXIT_SUCCESS;
}
