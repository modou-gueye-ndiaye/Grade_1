//  Tente de lire la suite des flottants au format "%f" qui figurent dans le
//    fichier texte dont le nom est spécifié sur la ligne de commande,
//    d'afficher leur somme sur la sortie standard puis de notifier un succès à
//    l'environnement d'exécution. Si un et un seul paramètre ne figure pas sur
//    la ligne de commande, qu'une erreur survient lors du traitement du fichier
//    ou que le fichier n'est pas uniquement constitué de flottants qui peuvent
//    être lus au format "%f", affiche un message d'erreur sur la sortie erreur
//    puis notifie un échec à l'environnement d'exécution.

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "One and only one parameter expected\n");
    return EXIT_FAILURE;
  }
  FILE *f = fopen(argv[1], "r");
  if (f == nullptr) {
    fprintf(stderr, "File not found\n");
    return EXIT_FAILURE;
  }
  float s = 0.0;
  float x;
  //  avec rs == (valeur renvoyée par le dernier appel fscanf(f, "%f", &x))
  //  IB : x == (dernier flottant lu sur f si rs == 1)
  //    && s == (somme des flottants lus sur f, sans compter le dernier flottant
  //              lu si rs == 1)
  //  QC : nombre d'appels fscanf(f, "%f", &x)
  while (fscanf(f, "%f", &x) == 1) {
    s += x;
  }
  int r = EXIT_SUCCESS;
  if (!feof(f)) {
    r = EXIT_FAILURE;
  }
  if (fclose(f) != 0) {
    r = EXIT_FAILURE;
  }
  if (r == EXIT_FAILURE) {
    fprintf(stderr, "An error occurred\n");
  } else {
    printf("%f\n", s);
  }
  return r;
}
