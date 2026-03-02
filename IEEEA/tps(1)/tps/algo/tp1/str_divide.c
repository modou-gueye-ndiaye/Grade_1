/* [Nom du programme]
 * [Date de Création]
 * [Auteur(s)/Auteure(s)]
 * [Descriptif du programme ]
 */
 

/* Appel des bibliothèques */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define STRLEN_MAX 8 
#define STRLEN_MAX_S "8"

/* Déclarations des fonctions et des macros */


/* Fonction principale */

int main(void) {
	char s[STRLEN_MAX + 1] ;
	int n = 1 ;
	while (scanf("%" STRLEN_MAX_S "s", s) == 1) {
		printf ("%d\t%s\n", n, s) ;
		++n;
	}
		
  return EXIT_SUCCESS; 
}

/* Définitions des fonctions */
