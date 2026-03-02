

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
    long int a  = strtol(s, &p, 10) ;
		if (*p == '\0') {
		  if (errno == ERANGE) {
			printf("%d\t%s\tvalue out of range\n", n, s) ;
		   } else  {
			printf ("%d\t%s\tvalue = %ld\n", n, s, a) ;
		     }
		 } else {
		  printf ("%d\t%s\tillegal value\n", n, s) ;
	     }
	     ++n;
	}

  return EXIT_SUCCESS;
}

/* Définitions des fonctions */
