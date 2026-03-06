//  Chap. 5, Manipulation de fichiers : tmpfile.

//  Tente d'afficher sur la sortie standard le contenu de l'entrée standard
//    après l'avoir lu entièrement. En cas de succès, notifie un succès à
//    l'environnement d'exécution. En cas d'échec, affiche un message d'erreur
//    sur la sortie erreur puis notifie un échec à l'environnement d'exécution.
//    Utilise un fichier temporaire.

#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *f = tmpfile();
  if (f == nullptr) {
    fprintf(stderr, "Error when creating a temporary file\n");
    return EXIT_FAILURE;
  }
  int c;
  //  sans tenir compte des derniers effets de l'évaluation de l'ECB
  //  IB : tous les caractères lus sur l'entrée standard ont été écrits sur f
  //  QC : nombre d’appels fgetc(stdin)
  while ((c = fgetc(stdin)) != EOF && fputc(c, f) != EOF) {
  }
  if (!feof(stdin)) {
    fclose(f);
    fprintf(stderr,
        "Read error on standard input or write error on temporary file\n");
    return EXIT_FAILURE;
  }
  rewind(f);
  //  sans tenir compte des derniers effets de l'évaluation de l'ECB
  //  IB : tous les caractères lus sur l'entrée standard ont été écrits sur f
  //    && tous les caractères lus sur f ont été écrits sur la sortie standard
  //  QC : nombre d’appels fgetc(f)
  while ((c = fgetc(f)) != EOF && fputc(c, stdout) != EOF) {
  }
  int r = EXIT_SUCCESS;
  if (!feof(f)) {
    r = EXIT_FAILURE;
  }
  if (fclose(f) != 0) {
    r = EXIT_FAILURE;
  }
  if (r == EXIT_FAILURE) {
    fprintf(stderr,
        "Read error on the temporary file or write error on standard output\n");
  }
  return r;
}
