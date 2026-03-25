//  Chapitre 3, Lisibilité, nombres magiques.

#include <stdio.h>
#include <stdlib.h>

//  time_to_hms : décompose une durée exprimée en secondes, time, en heures,
//    *hourptr, minutes, *minptr, et secondes, *secptr
void time_to_hms(int time, int *hourptr, int *minptr, int *secptr);

int main() {
  int time;
  int hour;
  int min;
  int sec;
  //  IB : ?
  //  QC : ?
  while (scanf("%d", &time) == 1) {
    time_to_hms(time, &hour, &min, &sec);
    printf("%d sec -> %d h %d min %d s\n", time, hour, min, sec);
  }
  return EXIT_SUCCESS;
}

void time_to_hms(int time, int *hourptr, int *minptr, int *secptr) {
  *hourptr = time / 3600;
  *minptr = (time / 60) % 60;
  *secptr = time % 60;
}
