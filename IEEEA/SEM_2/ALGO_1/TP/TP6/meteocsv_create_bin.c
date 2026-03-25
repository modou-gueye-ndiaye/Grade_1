#define SUFF ".csv"
#define REPL /* Chaine à fixer */

#include <stdio.h>
#include <stdlib.h>


typedef struct {
  struct {
    int gyear;
    int month;
    int mday;
  } date;
  float tx; // température maximale
  float tn; // température minimale
  float rr; // précipitations
  float w;  // ensoleillement
} report;



enum {
  CREATE_BIN_SUCCESS,
  CREATE_BIN_FAILURE_SRC,
  CREATE_BIN_FAILURE_DEST,
};

int create_bin(const char *destfn, const char *srcfn, const char **errptr);


int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Syntax: %s [FILE]...\n", argv[0]);
    return EXIT_SUCCESS;
const char * const suff = argv[1];
  const char * const repl = argv[2];

  for (int k = 1; k < argc; ++k) {

     char memoire[strlen(argv[k])-strlen(suff)+strlen(repl)+1];
     const char **errptr

     if ( strcmp(argv[k]+strlen(argv[k])-strlen(suff),suff)==0) {
       memcpy(memoire,argv[k], strlen(argv[k]) - strlen(suff));
       memcpy(memoire+strlen(argv[k])-strlen(suff),repl,strlen(repl)+1);
       create_bin(memoire,argv[k],&errptr);
     }

     else{
       if(&errptr!=NULL){
	 fprintf(stderr,"%s",&errptr);
       }



  }
  return EXIT_SUCCESS;
}


static int freport_csv_get(FILE *f, report *p) {
  if (fscanf(f, "%d%d%d%f%f%f%f",
      &p->date.gyear,
      &p->date.month,
      &p->date.mday,
      &p->tx,
      &p->tn,
      &p->rr,
      &p->w) != 7) {
    return -1;
  }
  return 0;
}
