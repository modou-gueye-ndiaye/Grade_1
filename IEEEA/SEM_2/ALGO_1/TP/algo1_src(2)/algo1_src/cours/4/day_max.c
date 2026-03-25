//  Chapitre 4, Tableaux : généralités : initialisation, tableaux
//    multidimensionnels.
//  Voir Kernighan et Ritchie, section 5.7.
//  Le choix du type int pour coder le quantième maximum suit celui des champs
//    de la structure struct tm de l'en-tête standard <time.h>. Parmi ces
//    champs :
//    int tm_mday; // day of the month -- [1, 31]
//    [sous-sous-section 7.29.1 dans la norme C23].

#include <stdio.h>
#include <stdlib.h>

//  trois définitions équivalentes :

const int daymax1[12] = {
  31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

const int daymax2[] = {
  31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

const int daymax3[] = {
  [1] = 29,
  [3] = 30, [5] = 30, [8] = 30, [10] = 30,
  [0] = 31, [2] = 31, [4] = 31, [6] = 31, [7] = 31, [9] = 31, [11] = 31
};

//  trois définitions équivalentes :

const int day2max1[2][12] = {
  //  année non bissextile
  { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
  //  année bissextile
  { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }
};

const int day2max2[][12] = {
  //  année non bissextile
  { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
  //  année bissextile
  { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }
};

const int day2max3[][12] = {
  //  année non bissextile
  [0] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
  //  année bissextile
  [1] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }
};

//  fonction principale :

int main() {
  //
  printf("%zu\n", sizeof(daymax1));
  printf("%zu\n", sizeof(daymax2));
  printf("%zu\n", sizeof(daymax3));
  printf("%zu\n", sizeof(day2max1));
  printf("%zu\n", sizeof(day2max2));
  printf("%zu\n", sizeof(day2max3));
  //
  return EXIT_SUCCESS;
}
