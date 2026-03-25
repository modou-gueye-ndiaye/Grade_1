//  Tente d'afficher sur la sortie standard la suite des composants du fichier
//    homogène de « float » dont le nom est spécifié sur la ligne de commande.
//    En cas de succès, notifie un succès à l'environnement d'exécution. En cas
//    d'échec, parce qu'un et un seul paramètre ne figure pas sur la ligne de
//    commande, qu'une erreur survient lors du traitement du fichier ou sur la
//    sortie standard, affiche un message d'erreur sur la sortie erreur puis
//    notifie un échec à l'environnement d'exécution.

#include <stdio.h>
#include <stdlib.h>

//  fail_if : si expr ne vaut pas zéro, affiche le message msg sur la sortie
//    erreur et termine le programme en notifiant un échec à l'environnement
//    d'exécution.
void fail_if(int expr, const char *msg);

//  print_ffloatb : tente d'afficher sur la sortie standard la suite des
//    composants du fichier homogène de « float » de nom la chaine pointée par
//    filename. Un flottant est écrit par ligne. Renvoie zéro en cas de succès,
//    une valeur non nulle en cas d'échec
//  AE : aucune
//  AS : print_ffloatb == 0 ^^ une erreur est survenue
int print_ffloatb(const char *filename);

int main(int argc, char *argv[]) {
  fail_if(argc != 2, "One and only one parameter expected");
  int r = print_ffloatb(argv[1]);
  fail_if(r != 0, "An error occurred");
  return EXIT_SUCCESS;
}

void fail_if(int expr, const char *msg) {
  if (!expr) {
    return;
  }
  fprintf(stderr, "%s\n", msg);
  exit(EXIT_FAILURE);
}

int print_ffloatb(const char *filename) {
  FILE *f = fopen(filename, "rb");
  if (f == nullptr) {
    return -1;
  }
  float x;
  //  sans tenir compte des derniers effets de l'évaluation de l'ECB
  //  IB : tous les composants lus sur f ont été écrits sur la sortie standard
  //  QC : nombre d'appels fread(&x, ..., 1, f)
  while (fread(&x, sizeof(float), 1, f) == 1 && printf("%f\n", x) >= 0) {
  }
  int r = 0;
  if (!feof(f)) {
    r = -1;
  }
  if (fclose(f) != 0) {
    r = -1;
  }
  return r;
}
