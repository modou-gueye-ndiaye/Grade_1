#include <math.h>
#include <stdio.h>
#include <stdlib.h>

//  sinh_tunc : renvoie la troncature à l'ordre n
//    du développement en série au voisinage de 0
//    de la fonction x --> sinh(x).
//  AE : aucune
//  AS : sinh_trunc(x, n) == somme(x ^ 2j + 1 / (2j + 1)! ; j == 0 ... n)
double sinh_trunc(double x, int n);

#define N_MAX 9

#define PRI_FLT "13.10lf"

int main() {
  double x;
  //  IB : pour toutes les valeurs lues sur l'entrée standard, sans compter la
  //        dernière valeur lue si la valeur renvoyée par le dernier appel à
  //        scanf égale 1, les lignes avec les troncatures et l'image en ces
  //        valeurs ont été affichées conformément à la spécification
  //    && x == dernière valeur lue sur l'entrée standard si la valeur renvoyée
  //        par le dernier appel à scanf égale 1
  //  QC : nombre d'appels à scanf
  while (scanf("%lf", &x) == 1) {
    //  IB : 0 <= k && k <= N_MAX + 1
    //    && les lignes avec les troncatures en x de 0 à k - 1 ont été affichées
    //        conformément à la spécification
    //  QC : k
    for (int k = 0; k <= N_MAX; ++k) {
      printf("%" PRI_FLT "\t%d\n", sinh_trunc(x, k), k);
    }
    //printf("%" PRI_FLT "\n", sinh(x));
  }
  return EXIT_SUCCESS;
}

double sinh_trunc(double x, int n) {
  if (n <= 0) {
    return 0.0;
  }
  int k = 0;
  double t = x;
  double s = t;
  //  IB : 0 <= k && k <= n
  //    && t == x ^ 2k + 1 / (2 * k + 1)!
  //    && s == somme(x ^ 2 * j + 1 / (2 * j + 1)! ; j == 0 ... k)
  //  QC : k
  while (k < n) {
    k += 1;
    t *= x / (2 * k + 1) * (2 * k);
    s += t;
  }
  return s;
}
