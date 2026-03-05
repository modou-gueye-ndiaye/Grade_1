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

//  fail_if : si expr ne vaut pas zéro, affiche le message msg sur la sortie
//    erreur et termine le programme en notifiant un échec à l'environnement
//    d'exécution.
void fail_if(int expr, const char *msg);

//  ffloat_sum_t : tente de lire la suite des flottants au format "%f" qui
//    figurent dans le fichier texte de nom la chaine pointée par filename. Si
//    une erreur survient lors du traitement du fichier ou que le fichier n'est
//    pas uniquement constitué de flottants qui peuvent être lus au format "%f",
//    renvoie une valeur non nulle. Sinon, affecte la somme à l'objet pointé par
//    sumptr et renvoie zéro.
//  AE : aucune
//  AS : (ffloat_sum_t == 0 && *sumptr == somme des flottants)
//    ^^ (ffloat_sum_t != 0 && une erreur est survenue)
int ffloat_sum_t(const char *filename, float *sumptr);

int main(int argc, char *argv[]) {
  fail_if(argc != 2, "One and only one parameter expected");
  float s;
  int r = ffloat_sum_t(argv[1], &s);
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

int ffloat_sum_t(const char *filename, float *sumptr) {
  FILE *f = fopen(filename, "r");
  if (f == nullptr) {
    return -1;
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
