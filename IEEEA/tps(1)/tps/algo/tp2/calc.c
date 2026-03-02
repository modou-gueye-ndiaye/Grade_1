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
#define NB_MAX 8
#define ADD "ADD"
#define MUL "MUL"
#define END "END"
#define SUB "SUB"
#define QUO "QUO" 
#define REM "REM"
/* Déclarations des fonctions et des macros */


/* Fonction principale */

int main(void) {
  char s[STRLEN_MAX + 1] ;
  long int t [NB_MAX] = {0} ;
  long int h = 0;
  char *p = 0 ;
  
    while (scanf("%" STRLEN_MAX_S "s", s) == 1) {
          if (strcmp(s, ADD) == 0) {
			 if (h < 2) {
			   fprintf(stderr, "Hauteur de la pile insuffisante\n") ;
			   return EXIT_FAILURE;
			 }
			t[h - 2] += t[h - 1] ;
			--h;
	
	  	  } else if (strcmp(s, MUL) == 0) {
			 if (h < 2) {
			   fprintf(stderr, "Hauteur de la pile insuffisante\n") ;
			   return EXIT_FAILURE;
			 }
			t[h - 2] *= t[h - 1] ;
			--h ;
			   } else if (strcmp(s, SUB) == 0) {
			       if (h < 2) {
			          fprintf(stderr, "Hauteur de la pile insuffisante\n") ;
			          return EXIT_FAILURE;
			       }
			     t[h - 2] -= t[h - 1] ;
			     --h ;
			      } else if (strcmp(s, QUO) == 0) {
			           if (h < 2) {
			             fprintf(stderr, "Hauteur de la pile insuffisante\n") ;
			             return EXIT_FAILURE;
			           }
			              t[h - 2] /= t[h - 1] ;
			              --h ;
			           } else if (strcmp(s, REM) == 0) {
							if (h < 2) {
							 fprintf(stderr, "Hauteur de la pile insuffisante\n") ;
							 return EXIT_FAILURE;
							}
						 t[h - 2] %= t[h - 1] ;
						 --h ;
			        } else if (strcmp(s, END) == 0) {
			            if (h != 1) {
				        return EXIT_FAILURE;
			          }
			           printf ("%ld\n", t[0]) ;
				       //return EXIT_SUCCESS;
		              } else {
               	         errno = 0 ;
               	         long int a  = strtol(s, &p, 10) ;
		                 if (*p != '\0'  || s == p || errno == ERANGE) {
		                 return EXIT_FAILURE;
		                 }
		                  if (h >= NB_MAX) {
					      fprintf (stderr, "Erreur de debordement\n");
			              return EXIT_FAILURE;
		                  }
		               t[h] = a ;
		               ++h ;
                      }
     }

  return EXIT_SUCCESS;
}

/* Définitions des fonctions */
