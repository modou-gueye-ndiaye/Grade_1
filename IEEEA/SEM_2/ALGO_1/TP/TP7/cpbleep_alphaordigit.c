#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fail_if(int expr, const char *msg, const char *progn);

int cpbleep(const char *destfn, const char *srcfn, int bleep,
    int (*charcond)(int));

int main(int argc, char *argv[]) {
  enum {
    PROGN_IDX,
    BLEEP_IDX,
    CLASS_IDX,
    SRC_IDX,
    DEST_IDX,
    EXPECTED_ARGC
  };
  fail_if(argc != EXPECTED_ARGC, "Bad number of arguments", argv[0]);
  fail_if(strlen(argv[BLEEP_IDX]) != 1, "Invalid BLEEP argument", argv[0]);
  int (*charcond)(int) = NULL;
  if (strcmp(argv[CLASS_IDX], "alpha") == 0) {
    charcond = isalpha;
  } else if (strcmp(argv[CLASS_IDX], "digit") == 0) {
    charcond = isdigit;
  }
  fail_if(charcond == NULL, "Invalid CLASS argument", argv[0]);
  fail_if(
      cpbleep(argv[DEST_IDX], argv[SRC_IDX], *argv[BLEEP_IDX], charcond) != 0,
      "An error occurred while processing the files", argv[0]);
  return EXIT_SUCCESS;
}

void fail_if(int expr, const char *msg, const char *progn) {
  if (!expr) {
    return;
  }
  fprintf(stderr, "%s: %s\n", progn, msg);
  exit(EXIT_FAILURE);
}

int cpbleep(const char *destfn, const char *srcfn, int bleep,
    int (*charcond)(int)) {
  FILE *src = fopen(srcfn, "rb");
  if (src == NULL) {
    return 1;
  }
  FILE *dest = fopen(destfn, "wbx");
  if (dest == NULL) {
    fclose(src);
    return 1;
  }
  int c ;
 c = fgetc(src);
  while (c != EOF) {
    if ((charcond) (c)) {
      fputc(bleep, dest);
    } else {
      fputc(c, dest);
    }
   c = fgetc(src);
  }
  int r = 0;
  if (!feof(src)) {
    fclose(src);
    r = 1;
  }

  if (fclose(src) != 0) {
    r = 1;
  }
  if (fclose(dest) != 0) {
    r = 1;
  }
  return r;
}
