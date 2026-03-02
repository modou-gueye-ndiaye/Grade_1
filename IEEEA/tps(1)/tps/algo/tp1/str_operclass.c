/* [Nom du programme]
 * [Date de Création]
 * [Auteur(s)/Auteure(s)]
 * [Descriptif du programme ]
 */


/* Appel des bibliothèques */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <errno.h>
#include <string.h>

#define STRLEN_MAX 32
#define STRLEN_MAX_S "32"
/* Déclarations des fonctions et des macros */


/* Fonction principale */

int main(void) {
  char s[STRLEN_MAX + 1] ;
	int n = 1 ;
	errno = 0 ;
	char *p ;
  while (scanf("%" STRLEN_MAX_S "s", s) == 1) {
		if (strtol(s, &p, 10)) {
		  if (errno == ERANGE) {
			printf("%d\t%s\tvalue out of range\n", n, s) ;
		   } else if (strcmp(s, "ADD") || strcmp(s, "MUL")  || strcmp(s, "END") == 0) {
			printf ("%d\t%s\toperator\n", n, s) ;
		     } else  {
		        printf ("%d\t%s\trejected form", n, s) ;
	           }
	     } else {
			 printf("%d\t%s\toperand = %s\n", n, s, s) ;
		   }
	     ++n;
	}
  return EXIT_SUCCESS;
}

/* Définitions des fonctions */
