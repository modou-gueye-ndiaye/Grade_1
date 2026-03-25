//  Tente de lire la suite des flottants au format "%f" qui figurent sur
//    l'entrée standard, d'afficher leur somme sur la sortie standard puis de
//    notifier un succès à l'environnement d'exécution. Si une erreur survient
//    sur l'entrée ou que l'entrée n'est pas uniquement constituée de flottants
//    qui peuvent être lus au format "%f", affiche un message d'erreur sur la
//    sortie erreur puis notifie un échec à l'environnement d'exécution.

#include <stdio.h>
#include <stdlib.h>

int main() {
  float s = 0.0;
  float x;
  int rs = scanf("%f", &x);
  //  IB : rs == (valeur renvoyée par le dernier appel scanf("%f", &x))
  //    && x == (dernier flottant lu sur l'entrée standard si rs == 1)
  //    && s == (somme des flottants lus sur l'entrée standard, sans compter le
  //              dernier flottant lu si rs == 1)
  //  QC : nombre d'appels scanf("%f", &x)
  while (rs == 1) {
    s += x;
    rs = scanf("%f", &x);
  }
  int r = EXIT_SUCCESS;
  if (!feof(stdin)) {
    r = EXIT_FAILURE;
  }
  if (r == EXIT_FAILURE) {
    fprintf(stderr, "An error occurred\n");
  } else {
    printf("%f\n", s);
  }
  return r;
}
