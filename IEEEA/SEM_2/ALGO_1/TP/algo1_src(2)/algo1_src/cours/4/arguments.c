//  Chapitre 4, Exemple : la fonction principale et ses paramètres.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//  usage : affiche l'aide.
void usage();

int main(int argc, char *argv[]) {
  //
  //  pour un programme normal, tester les arguments de la commande :
  //
  for (int k = 1; k < argc; ++k) {
    if (strcmp(argv[k], "--help") == 0) {
      usage();
    }
  }
  //
  //  pour un programme normal, l'exécuter en fonction des arguments de la
  //    commande :
  //
  for (int k = 0; k < argc; ++k) {
    if (k == 0) {
      printf("commande");
    } else {
      printf("argument %d", k);
    }
    printf(" : %s\n", argv[k]);
  }
  return EXIT_SUCCESS;
}

void usage() {
  //
  // pour un programme normal, afficher l'aide :
  //
  printf("Usage: ...\n");
  exit(EXIT_SUCCESS);
}
