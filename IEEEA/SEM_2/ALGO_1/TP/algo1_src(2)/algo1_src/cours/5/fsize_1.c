//  Affiche sur la sortie standard la taille des fichiers dont le nom est
//    spécifié par les paramètres de la ligne de commande. Notifie un succès à
//    l'environnement d'exécution.

#include <stdio.h>
#include <stdlib.h>

//  fsize : en cas de succès, renvoie la taille du fichier de nom la chaine
//    pointée par filename. En cas d'échec, renvoie -1.
//  AE : aucune
//  AS : (fsize != -1 && fsize == taille du fichier)
//    ^^ (fsize == -1 && une erreur est survenue lors du traitement du fichier)
long int fsize(const char *filename);

int main(int argc, char *argv[]) {
  //  IB : 1 <= k && k <= argc
  //    && les fichiers de nom les chaines pointées par argv[1] à argv[k - 1]
  //        ont été traités
  //  QC : k
  for (int k = 1; k < argc; ++k) {
    const char * const a = argv[k];
    long int n = fsize(a);
    if (n == -1) {
      fprintf(stderr, "An error occurred on '%s'\n", a);
    } else {
      printf("%10ld bytes\t%s\n", n, a);
    }
  }
  return EXIT_SUCCESS;
}

long int fsize(const char *filename) {
  FILE *f = fopen(filename, "rb");
  if (f == nullptr) {
    return -1;
  }
  long int n = 0;
  //  sans tenir compte des derniers effets de l'évaluation de l'ECB
  //  IB : n == (nombre de caractères lus sur f)
  //  QC : nombre d'appels fgetc(f)
  while (fgetc(f) != EOF) {
    ++n;
  }
  if (!feof(f)) {
    n = -1;
  }
  if (fclose(f) != 0) {
    n = -1;
  }
  return n;
}
