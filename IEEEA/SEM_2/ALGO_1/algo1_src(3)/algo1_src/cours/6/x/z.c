#include <stdio.h>
#include "z.h"

static int zs = 21;

void z(int n) {
  zs += n;
  printf("%d", zs);
}
