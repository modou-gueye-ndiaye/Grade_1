//  Chapitre 3, Erreurs, terminaisons et diagnostics, Diagnostics.

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

//  except_10 : provoque une terminaison anormale du programme si x vaut 10.
//    Affiche sinon la valeur de x sur la sortie standard.
void except_10(int x);

int main() {
  //
  except_10(123);
  except_10(456);
  except_10(7890);
  except_10(10);
  //
  return EXIT_SUCCESS;
}

void except_10(int x) {
  assert(x != 10);
  printf("%d: OK!\n", x);
}
