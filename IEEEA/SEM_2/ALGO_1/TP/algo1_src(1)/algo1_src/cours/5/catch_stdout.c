//  Chap. 5, Association, ouverture et fermeture : freopen.

#define CATCH_FILE "catch_stdout.log"

#define YES "yes"
#define NO  "no"

//  Trois cas sont à distinguer selon les paramètres qui figurent sur la ligne
//    de commande : 1) l'un d'eux n'est ni (la chaine de caractères désignée par
//    la macroconstante) YES ni (la chaine de caractères désignée par la
//    macroconstante) NO ; 2) le dernier est NO ; 3) aucun paramètre ne figure
//    sur la ligne de commande ou le dernier est YES. Dans le cas 1), affiche un
//    message d'erreur sur la sortie erreur. Dans le cas 2), affiche le contenu
//    de l'entrée standard sur la sortie standard. Dans le cas 3), capture la
//    sortie standard, vide ou crée le fichier (désigné par la macroconstante)
//    CATCH_FILE, puis lui donne comme contenu celui de l'entrée standard. Dans
//    le cas 1), dans les cas 2) et 3) lorsqu'une erreur survient sur l'entrée
//    ou sur la sortie, ou alors dans le cas 3) lorsque la capture de la sortie
//    standard ne peut être réalisée, affiche un message d'erreur puis notifie
//    un échec à l'environnement d'exécution. Notifie sinon un succès à
//    l'environnement d'exécution.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  bool g = true;
  //  IB : 1 <= k && k <= argc
  //    && chacune des chaines pointées par argv[1] à argv[k - 1] est égale à
  //        YES ou à NO
  //    && g == (k == 1 || la chaine pointée par argv[k - 1] est égale à YES)
  for (int k = 1; k < argc; ++k) {
    if (strcmp(argv[k], YES) == 0) {
      g = true;
    } else if (strcmp(argv[k], NO) == 0) {
      g = false;
    } else {
      fprintf(stderr, "Invalid parameter '%s'\n", argv[k]);
      return EXIT_FAILURE;
    }
  }
  if (g) {
    if (freopen(CATCH_FILE, "w", stdout) == nullptr) {
      fprintf(stderr, "Error while redefining a stream\n");
      return EXIT_FAILURE;
    }
  }
  int c;
  //  sans tenir compte des derniers effets de l'évaluation de l'ECB
  //  IB : ((g && stdout est associé au fichier CATCH_FILE)
  //        ^^ (!g && stdout est la sortie standard))
  //    && tous les caractères lus sur l'entrée standard ont été écrits sur
  //        stdout
  //  QC : nombre d’appels getchar()
  while ((c = getchar()) != EOF && putchar(c) != EOF) {
  }
  int r = EXIT_SUCCESS;
  if (!feof(stdin)) {
    fprintf(stderr, "Read error on standard input or write error on %s\n",
        g ? CATCH_FILE : "standard output");
    r = EXIT_FAILURE;
  }
  if (g && fclose(stdout) != 0) {
    fprintf(stderr, "Error while closing %s\n", CATCH_FILE);
    r = EXIT_FAILURE;
  }
  return r;
}
