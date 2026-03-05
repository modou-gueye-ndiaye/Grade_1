#include <stdio.h>
#include <stdlib.h>

#define NAME_LENGTH_MAX 63

typedef struct {
  char lastname[NAME_LENGTH_MAX + 1];   //  nom
  char firstname[NAME_LENGTH_MAX + 1];  //  prénom(s)
  int yearfirstapp;                     //  année de première apparition
} character;

void character_display_names(const character *q);
int main (int argc, char *argv[]){
  if(argc!=1){
    fprintf(stderr,"%s :erreur trop d'argument sur la ligne de commande \n", argv[0]);
    return EXIT_FAILURE;

  }
  character personnages[] ={
   {"Ben Kalish Ezab","Abdallah",1950},
   {"Ben Salaad","Omar",1941},
   {"Alcazar","Peggy",1976},
   {"Bolivar","Hippolyte",1932},
   {"Haddock","Archibald",1941},
   {"Bada","Ramon",1937},
   {"Wagner","Igor",1939},
   {"Charlet","Marc",1948},
   {"Perez","Alonzo",1937},
   {"Bazaroff","Basil",1937},
   {"Ben Moulfrid","Youssouf",1950},
   {"Tortilla","Rodrigo",1937},
   {"Cartoffoli","Arturo Benedetto Giovanni Giuseppe Pietro Archangelo Alfredo",1956},
   {"Boullu","Isidore",1963},
   {"Capone","Al",1932},
   {"Sakharine","Ivan Ivanovitch",1943},
   {"Topolino","Alfredo",1956},
   {"Tournesol","Tryphon",1945},
   {"Thompson","Allan",1934},
   {"Lampion","Seraphin",1956},
   {"Rastapopoulos","Roberto",1934},
   {"Castafiore","Blanca",1939},
   {"Zarate","Ramon",1948},
   {"Bergamotte","Hippolyte",1948},
   {"Szprinkoth","Stephan",1956},
   {"Ben Mahmoud","Ali",1950},

   };
   size_t n_member=27;
   size_t k=0;
   while(n_member-k!=0){
     ++k;
     character_display_names(&personnages[k]);
   }
   return EXIT_SUCCESS;
}
void character_display_names(const character *q){
    printf("%s\t%s\n",q->firstname,q->lastname);
}
