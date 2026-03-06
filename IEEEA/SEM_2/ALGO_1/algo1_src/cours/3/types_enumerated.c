//  Chapitre 3, Types scalaires, Types énumérés.

#include <stdlib.h>

//  Définition d'une énumération anonyme, constantes symboliques numérotées
//    implicitement à partir de 0 :

enum {
  winter, spring, summer, autumn
};

//  Définition d'un type énuméré, constantes symboliques numérotées
//    explicitement à partir de 1 :

enum months {
  january = 1, february, march,
  april, may, june,
  july, august, september,
  october, november, december,
};

//  Définition d'un type énuméré, dont les constantes symboliques sont
//    compatibles avec le type char :

enum typeinteger {
  plus = '+', minus = '-',
  zero = '0', one, two, three, four, five, six, seven, eight, nine,
};

//  Définition d'un nom (alias) associé à une énumération anonyme :

typedef enum {
  male, female, other,
} gender;

int main() {
  return EXIT_SUCCESS;
}
