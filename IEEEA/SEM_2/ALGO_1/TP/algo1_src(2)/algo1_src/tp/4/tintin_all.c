//  Utilisation :
//    tintin_all
//
//  Affiche les personnages d'albums de Tintin figurant dans une très petite
//    base de données.
//
//  Renvoie EXIT_FAILURE à l'environnement d'exécution si le nombre d'arguments
//    qui figurent sur la ligne de commande est différent de 1.
//  Renvoie EXIT_SUCCESS sinon.

#include <stdio.h>
#include <stdlib.h>

//  character : alias d'une structure anonyme permettant de mémoriser le nom et
//    le(s) prénom(s) d'un personnage des albums de Tintin ainsi que l'année de
//    publication de l'album dans lequel il apparait pour la première fois.

#define NAME_LENGTH_MAX 63

typedef struct {
  char lastname[NAME_LENGTH_MAX + 1];   //  nom
  char firstname[NAME_LENGTH_MAX + 1];  //  prénom(s)
  int yearfirstapp;                     //  année de première apparition
} character;

//  character_display_names : affiche sur la sortie standard les champs
//    firstname et lastname, dans cet ordre, de l'objet de type « character »
//    pointé par q. Les champs affichés sont séparés d'une espace. Le dernier
//    champ affiché est immédiatement suivi d'une fin de ligne.
void character_display_names(const character *q);
