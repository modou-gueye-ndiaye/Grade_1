//  Chapitre 6, Exemples : une procédure de modification de chaines.

#include <stdio.h>
#include <stdlib.h>

//  str_all_stars : remplace tous les caractères de la chaine pointée par s par
//    '*' à l'exception du '\0' final.
//  AE : s == { c_{0}, c_{1}, ..., c_{n - 1}, '\0' }
//  AS : s == { '*' }^n . { '\0' }
void str_all_stars(char *s);

int main() {
  char p[] = "abcd";
  printf("%s\n", p);
  str_all_stars(p);
  printf("%s\n", p);
  char *s = p;
  printf("%s\n", s);
  str_all_stars(s);
  printf("%s\n", s);
  char *t = "ABCDEF"; // erreur à la compilation avec -Wwrite-strings
  printf("%s\n", t);
  str_all_stars(t);   // erreur à l'exécution sans -Wwrite-strings
  printf("%s\n", t);
  return EXIT_SUCCESS;
}

void str_all_stars(char *s) {
  char *p = s;
  // IB : 0 <= p - s && p - s <= n
  //   && s == { '*' }^(p - s) . { c_{p - s}, ..., c_{n - 1}, '\0' }
  // QC : p - s
  while (*p != '\0') {
    *p = '*';
    ++p;
  }
}
