#include <stdio.h>
#include <stdlib.h>

typedef struct {
  struct {
    int gyear;
    int month;
    int mday;
  } date;
  float tx; 
  float tn; 
  float rr; 
  float w;  
} report;

const char *moyenne_w(const char *filename, float *msrptr);

#define MSR_FORMAT  "%6.1f w/j"


int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Syntax: %s [FILE]...\n", argv[0]);
    return EXIT_SUCCESS;
  }
  
  for (int k = 1; k < argc; ++k) {
    float msr;
    const char *r = moyenne_w(argv[k], &msr);
    if (r != NULL) {
      fprintf(stderr, "%s: %s '%s'\n", argv[0], r, argv[k]);
    } else {
      printf(MSR_FORMAT "\t%s\n", msr, argv[k]);
    }
  }
  return EXIT_SUCCESS;
}

static int freport_csv_get(FILE *f, report *p) {
  if (fscanf(f, "%d%d%d%f%f%f",
      &p->date.gyear,
      &p->date.month,
      &p->date.mday,
      &p->tx,
      &p->tn,
      &p->rr) != 6) {
    return -1;
  }
  if (fgetc(f) == '\n') {
    p->w = 0;
    return 0;
  }
  if (fscanf(f, "%f", &p->w) != 1) {
    return -1;
  }
  return 0;
}

const char *moyenne_w(const char *filename, float *msrptr) {
  FILE *f = fopen(filename, "r");
  if (f == NULL) {
    return "Error when opening for reading file";
  }
  float s = 0.0;
  int n = 0;
  report x;
  int rg = freport_csv_get(f, &x);

  while (rg == 0) {
    s += x.w;
    ++n;
    rg = freport_csv_get(f, &x);
  }
  if (!feof(f)) {
    fclose(f);
    return "Error while processing file";
  }
  if (fclose(f) != 0) {
    return "Error on closing file";
  }
  if (n == 0) {
    return "empty_file"; 
  }
  *msrptr = s / (float) n;
  return NULL;
}
