//  Chapitre 4, Exemples : une procédure de modification de chaines.

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
  size_t k = 0;
  //  IB : 0 <= k && k <= n
  //    && s == { '*' }^k . { c_{k}, ..., c_{n - 1}, '\0' }
  //  QC : k
  while (s[k] != '\0') {
    s[k] = '*';
    ++k;
  }
}
