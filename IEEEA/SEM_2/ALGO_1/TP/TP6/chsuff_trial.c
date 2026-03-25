#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define VAL 1000

int main(int argc, char *argv[]) {
  if (argc < 3) {
    printf("Syntax: %s SUFF REPL [FILE]...\n", argv[0]);
    return EXIT_SUCCESS;
  }
  const char * const suff = argv[1];
  const char * const repl = argv[2];

  for (int k = 3; k < argc; ++k) {
   
     char memoire[strlen(argv[k])-strlen(suff)+strlen(repl)+1];


    if ( /* suff n'est pas un suffixe de argv[k] */
        strcmp(argv[k]+strlen(argv[k])-strlen(suff),suff)!=0) {
      fprintf(stderr, "%s: Invalid suffix for file '%s'\n", argv[0], argv[k]);
    } else {
      /*
       *  Réaliser ici la copie attendue dans la zone mémoire.
       */
       //char tab[strlen(argv[k])];
       memcpy(memoire,argv[k], strlen(argv[k]) - strlen(suff));
       memcpy(memoire+strlen(argv[k])-strlen(suff),repl,strlen(repl)+1);
       //memcpy(memoire,tab,strlen(argv[k]));
      printf("%s\t%s\n", argv[k], /* adresse de la zone mémoire */ memoire);
    }
  }
  return EXIT_SUCCESS;
}
