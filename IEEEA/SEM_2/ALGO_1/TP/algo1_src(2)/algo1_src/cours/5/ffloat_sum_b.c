//  Tente d'afficher sur la sortie standard la somme des composants du fichier
//    homogène de « float » dont le nom est spécifié sur la ligne de commande.
//    En cas de succès, notifie un succès à l'environnement d'exécution. En cas
//    d'échec, parce qu'un et un seul paramètre ne figure pas sur la ligne de
//    commande ou qu'une erreur survient lors du traitement du fichier, affiche
//    un message d'erreur sur la sortie erreur puis notifie un échec à
//    l'environnement d'exécution.

#include <stdio.h>
#include <stdlib.h>

//  fail_if : si expr ne vaut pas zéro, affiche le message msg sur la sortie
//    erreur et termine le programme en notifiant un échec à l'environnement
//    d'exécution.
void fail_if(int expr, const char *msg);

//  ffloat_sum_b : tente de calculer la somme des composants du fichier homogène
//    de « float » de nom la chaine pointée par filename. En cas de succès,
//    affecte la somme à l'objet pointé par sumptr et renvoie zéro. En cas
//    d'échec, renvoie une valeur non nulle.
//  AE : aucune
//  AS : (ffloat_sum_b == 0 && *sumptr == somme des composants)
//    ^^ (ffloat_sum_b != 0 && une erreur est survenue)
int ffloat_sum_b(const char *filename, float *sumptr);

int main(int argc, char *argv[]) {
  fail_if(argc != 2, "One and only one parameter expected");
  float s;
  int r = ffloat_sum_b(argv[1], &s);
  fail_if(r != 0, "An error occurred");
  printf("%f\n", s);
  return EXIT_SUCCESS;
}

void fail_if(int expr, const char *msg) {
  if (!expr) {
    return;
  }
  fprintf(stderr, "%s\n", msg);
  exit(EXIT_FAILURE);
}

int ffloat_sum_b(const char *filename, float *sumptr) {
  FILE *f = fopen(filename, "rb");
  if (f == nullptr) {
    return -1;
  }
  float s = 0.0;
  float x;
  //  avec rr == (valeur renvoyée par le dernier appel fread(&x, ..., 1, f))
  //  IB : x == (dernier composant lu sur f si rr == 1)
  //    && s == (somme des composants lus sur f, sans compter le dernier
  //              composant lu si rr == 1)
  //  QC : nombre d'appels fread(&x, ..., 1, f)
  while (fread(&x, sizeof(float), 1, f) == 1) {
    s += x;
  }
  int r = 0;
  if (!feof(f)) {
    r = -1;
  }
  if (fclose(f) != 0) {
    r = -1;
  }
  if (r == 0) {
    *sumptr = s;
  }
  return r;
}
