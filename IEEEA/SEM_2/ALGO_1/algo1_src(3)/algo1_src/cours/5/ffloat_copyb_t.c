//  Tente de créer le fichier homogène de « float » dont le nom est spécifié sur
//    la ligne de commande et d'y écrire les flottants lus au format "%f" sur
//    l'entrée standard. En cas de succès, notifie un succès à l'environnement
//    d'exécution. En cas d'échec, parce qu'un et un seul paramètre ne figure
//    pas sur la ligne de commande, qu'une erreur survient sur l'entrée, que
//    l'entrée n'est pas uniquement constituée de flottants qui peuvent être lus
//    au format "%f" ou qu'une erreur survient lors du traitement du fichier,
//    affiche un message d'erreur sur la sortie erreur puis notifie un échec à
//    l'environnement d'exécution.

#include <stdio.h>
#include <stdlib.h>

//  fail_if : si expr ne vaut pas zéro, affiche le message msg sur la sortie
//    erreur et termine le programme en notifiant un échec à l'environnement
//    d'exécution.
void fail_if(int expr, const char *msg);

//  ffloat_copyb_t : tente de créer le fichier homogène de « float » de nom la
//    chaine pointée par filename et d'y écrire les flottants lus au format "%f"
//    sur l'entrée standard. En cas de succès, renvoie zéro. En cas d'échec,
//    parce qu'une erreur survient sur l'entrée, que l'entrée n'est pas
//    uniquement constituée de flottants qui peuvent être lus au format "%f" ou
//    qu'une erreur survient lors du traitement du fichier, renvoie une valeur
//    non nulle.
//  AE : aucune
//  AS : ffloat_copyb_t == 0 ^^ une erreur est survenue
int ffloat_copyb_t(const char *filename);

int main(int argc, char *argv[]) {
  fail_if(argc != 2, "One and only one parameter expected");
  int r = ffloat_copyb_t(argv[1]);
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

int ffloat_copyb_t(const char *filename) {
  FILE *f = fopen(filename, "wbx");
  if (f == nullptr) {
    return -1;
  }
  float x;
  //  sans tenir compte des derniers effets de l'évaluation de l'ECB
  //  IB : tous les flottants lus sur l'entrée standard ont été écrits sur f
  //  QC : nombre d'appels scanf("%f", &x)
  while (scanf("%f", &x) == 1 && fwrite(&x, sizeof(float), 1, f) == 1) {
  }
  int r = 0;
  if (!feof(stdin)) {
    r = -1;
  }
  if (fclose(f) != 0) {
    r = -1;
  }
  return r;
}
