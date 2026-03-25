//  Chapitre 2, Exemple : échange de valeurs.

#include <stdio.h>
#include <stdlib.h>

//  int_swap : échange les valeurs des deux variables de type int d'adresses p1
//    et p2.
//  AE : *p1 == a && *p2 == b
//  AS : *p1 == b && *p2 == a
void int_swap(int *p1, int *p2);

int main() {
  int x1 = 7;
  int x2 = 3;
  printf("%d\t%d\n", x1, x2);
  int_swap(&x1, &x2);
  printf("%d\t%d\n", x1, x2);
  int_swap(&x1, &x2);
  printf("%d\t%d\n", x1, x2);
  return EXIT_SUCCESS;
}

void int_swap(int *p1, int *p2) {
  int t = *p1;
  *p1 = *p2;
  *p2 = t;
}
