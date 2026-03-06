//  Chapitre 6 : exemple pour illustrer l'utilisation de qsort sur un tableau
//    d'éléments du type int.

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void intarray_scan(int *a, size_t n);
void intarray_print(const int *a, size_t n);
void intarray_sort(int *a, size_t n);

#define ARRAYLENGTH 10

int main() {
  int a[ARRAYLENGTH];
  intarray_scan(a, ARRAYLENGTH);
  intarray_print(a, ARRAYLENGTH);
  intarray_sort(a, ARRAYLENGTH);
  intarray_print(a, ARRAYLENGTH);
  return EXIT_SUCCESS;
}

void intarray_scan(int *a, size_t n) {
  for (size_t k = 0; k < n; ++k) {
    printf("-> ");
    assert(scanf("%d", &a[k]) == 1);
  }
}

void intarray_print(const int *a, size_t n) {
  for (size_t k = 0; k < n; ++k) {
    if (k > 0) {
      printf(" ");
    }
    printf("%d", a[k]);
  }
  printf("\n");
}

int int_comp(const int *ptr1, const int *ptr2) {
  return (*ptr1 > *ptr2) - (*ptr1 < *ptr2);
}

void intarray_sort(int *a, size_t n) {
  qsort(
      a,
      n,
      sizeof(int), // ou : sizeof(a[0]), ou : sizeof(*a)
      (int (*)(const void *, const void *)) int_comp);
}
