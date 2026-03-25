#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fail_if(int expr, const char *msg, const char *progn);

int chbleep(const char *filename, int bleep, int (*charcond)(int));

int main(int argc, char *argv[]) {
  enum {
    PROGN_IDX,
    BLEEP_IDX,
    CLASS_IDX,
    EXPECTED_ARGC_MIN
  };
  fail_if(argc < EXPECTED_ARGC_MIN, "Bad number of arguments", argv[0]);
  fail_if(strlen(argv[BLEEP_IDX]) != 1, "Invalid BLEEP argument", argv[0]);
  int (*charcond)(int) = NULL;
  if (strcmp(argv[CLASS_IDX], "alpha") == 0) {
    charcond = isalpha;
  } else if (strcmp(argv[CLASS_IDX], "digit") == 0) {
    charcond = isdigit;
  }
  fail_if(charcond == NULL, "Invalid CLASS argument", argv[0]);
  int const b = *argv[BLEEP_IDX];
  int r = EXIT_SUCCESS;
  
  for (int k = EXPECTED_ARGC_MIN; k < argc; ++k) {
    const char * const a = argv[k];
    if (chbleep(a, b, charcond) != 0) {
      fprintf(stderr, "%s: An error occurred while processing file '%s'\n",
          argv[0], a);
      r = EXIT_FAILURE;
    } else {
      printf("%s\tBleeped\n", a);
    }
  }
  return r;
}

void fail_if(int expr, const char *msg, const char *progn) {
  if (!expr) {
    return;
  }
  fprintf(stderr, "%s: %s\n", progn, msg);
  exit(EXIT_FAILURE);
}
int chbleep(const char *filename, int bleep, int (*charcond)(int)){
  FILE *f= fopen(filename, "rb+");
  if (f == NULL) {
    return 1;
  }
  int c ;
 c = fgetc(f);
  while (c != EOF) {
    if ((charcond) (c)) {
      fseek(f,-1,SEEK_CUR);
      fputc(bleep, f);
    }
    fseek(f,-1,SEEK_CUR);
   c = fgetc(f);
  }
   int r = 0;
  if (!feof(f)) {
    fclose(f);
    r = 1;
  }

  if (fclose(f) != 0) {
    r = 1;
  }

  return r;
}
