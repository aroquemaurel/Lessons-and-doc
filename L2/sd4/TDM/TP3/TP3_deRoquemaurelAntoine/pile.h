#ifndef PILESTATIQUE
#define PILESTATIQUE

#include "elt_pile.h"
#include <stdbool.h>
#include <assert.h>

#define TAILLEMAX 8

/* ----------------------------------
        D�claration des types
   --------------------------------*/

/* D�claration du type d'une pile (avec masquage)*/

typedef struct cell* T_pile;



/* ----------------------------------
            Constructeurs
   --------------------------------*/

/*
 * Donn�es:
 * Objet: Initialisation d'une T_pile
 * R�sultats: la T_pile p cr��e
*/
void initialiser_pile(T_pile *p);

/*
 * Donn�es: un T_element el, une T_pile p
 * Objet: empiler el sur la pile p
 * R�sultats: la T_pile p modifi�e
*/
void empiler(T_pile *p, T_element el);

/*
 * Donn�es: une T_pile p
 * Objet: Suppression du T_element situ� au sommet de la T_pile p
 * R�sultats: la T_pile p modifi�e
*/
void depiler(T_pile *p);


/* ----------------------------------
            Accesseurs
   --------------------------------*/

/*
 * Donn�es: une T_pile p
 * Objet: Acc�der au T_element situ� au sommet de la T_pile p
 * R�sultats: le T_element renvoy�
*/
T_element sommet_pile(T_pile p);

/*
 * Donn�es: une T_pile p
 * Objet: Afficher une T_pile � partir du sommet
 * R�sultats:
*/
void afficher_pile(T_pile p);

/*
 * Donn�es: une T_pile p
 * Objet: D�terminer si la T_pile p est vide
 * R�sultats: un bool�en renvoy�
*/
bool pile_vide(T_pile p);

/*
 * Donn�es: une T_pile p
 * Objet: D�terminer si la T_pile p est pleine
 * R�sultats: un bool�en renvoy�
*/
bool pile_pleine(T_pile p);


#endif





