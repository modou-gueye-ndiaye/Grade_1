//  Chapitre 6 : exemple pour illustrer l'utilisation des pointeurs génériques
//    void *.

#include <stdio.h>
#include <stdlib.h>

//  mem_swap : échange les contenus des zones mémoires de taille size pointées
//    par s1 et s2.
//  AE : les deux zones ne se recouvrent pas
//  AS : les contenus des deux zones ont été échangés
void mem_swap(void *s1, void *s2, size_t size);

//  mem_copy : copie de contenu de la zone mémoire de taille size pointée par
//    src à partir de la zone mémoire pointée par dest.
//  AE : les deux zones ne se recouvrent pas
//  AS : le contenu de la zone source a été copié vers la zone destinataire
void mem_copy(void *dest, const void *src, size_t size);

void print2_int(int *ptr1, int *ptr2);

typedef struct {
  double x;
  double y;
} couple;

void print2_couple(couple *ptr1, couple *ptr2);

int main() {
  //
  int x = 20;
  int y = 21;
  print2_int(&x, &y);
  mem_swap(&x, &y, sizeof(int));
  print2_int(&x, &y);
  //
  couple c1 = {
    .x = 1.234567890, .y = 2.345678901
  };
  couple c2 = {
    .x = 3.456789012, .y = 4.567890123
  };
  print2_couple(&c1, &c2);
  mem_swap(&c1.y, &c2.y, sizeof(double));
  print2_couple(&c1, &c2);
  mem_swap(&c1, &c2, sizeof(couple));
  print2_couple(&c1, &c2);
  mem_swap(&c1.x, &c2.y, sizeof(double));
  print2_couple(&c1, &c2);
  //
  return EXIT_SUCCESS;
}

void mem_swap(void *s1, void *s2, size_t size) {
  char t[size];
  mem_copy(t, s1, size);
  mem_copy(s1, s2, size);
  mem_copy(s2, t, size);
}

#if 1

void mem_copy(void *dest, const void *src, size_t size) {
  //  IB : 0 <= k && k <= size
  //    && ((char *) dest)[0 ... k - 1] == ((char *) src)[0 ... k - 1]
  //  QC : k
  for (size_t k = 0; k < size; ++k) {
    ((char *) dest)[k] = ((char *) src)[k];
  }
}

#elif 1

void mem_copy(void *dest, const void *src, size_t size) {
  char *pd = dest;
  const char *ps = src;
  //  IB : 0 <= k && k <= size
  //    && pd == (char *) dest + k
  //    && ps == (char *) src + k
  //    && ((char *) dest)[0 ... k - 1] == ((char *) src)[0 ... k - 1]
  //  QC : k
  for (size_t k = 0; k < size; ++k) {
    *pd = *ps;
    ++pd;
    ++ps;
  }
}

#elif 1

void mem_copy(void *dest, const void *src, size_t size) {
  char *pd = dest;
  const char *ps = src;
  const char * const pse = ps + size;
  //  IB : pse == (char *) src + size
  //    && (char *) src <= ps && ps <= pse
  //    && pd == (char *) dest + (ps - ((char *) src))
  //    && ((char *) dest)[0 ... ps - ((char *) src) - 1]
  //        == ((char *) src)[0 ... ps - ((char *) src) - 1]
  //  QC : pse - ps
  while (ps < pse) {
    *pd = *ps;
    ++pd;
    ++ps;
  }
}

#endif

void print2_int(int *ptr1, int *ptr2) {
  printf("%d / %d\n",
      *ptr1, *ptr2);
}

void print2_couple(couple *ptr1, couple *ptr2) {
  printf("(%lf, %lf) / (%lf, %lf)\n",
      ptr1->x, ptr1->y, ptr2->x, ptr2->y);
}
