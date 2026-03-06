//  Chapitre 2, Exemple : factorielle.

#include <stdio.h>
#include <stdlib.h>

//  int_fact : renvoie n!, la factorielle de n.
//  AE : n >= 0
//  AS : int_fact == n!
int int_fact(int n);

int main() {
  for (int n = 0; n < 20; ++n) {
    printf("%d\t%d\n", n, int_fact(n));
  }
  return EXIT_SUCCESS;
}

int int_fact(int n) {
  int k = 0;
  int f = 1;
  //  IB : 0 <= k && k <= n && f == k!
  //  QC : k
  while (k < n) {
    k = k + 1;
    f = f * k;
  }
  return f;
}
