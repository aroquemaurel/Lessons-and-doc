#ifndef MIXTE_STACK_H
#define MIXTE_STACK_H
#include "element.h"
#include "pileDynamique.h"

typedef PileDynamique PileMixte;

/*  Constructeur */
/*  Créé une pile statique */
PileMixte pileMixteCreer();

/*  Empile un entier sur une PileMixte */
/*  précondition d’implantation: !PileMixteEstPleine(p) */
void pileMixteEmpiler(PileMixte* p, int v);

/*  Accesseurs */
/*  accède et supprime la valeur du sommet de pile*/
/*  précondition : !PileMixteEstVide(p) */
int pileMixteDepiler(PileMixte* p);

/*  accède à la valeur du sommet de pile*/
/*  précondition : !PileMixteEstVide(p) */
int pileMixteSommet(PileMixte p);

/*  Destructeur */
/*  libère la mémoire occupée par la pile statique */
void pileMixteDetruire(PileMixte *p);

/*  indique si la pile est vide */
/*  renvoie 1 si pile vide, 0 sinon */
int pileMixteEstVide(PileMixte p);

/*  indique si la pile est pleine*/
/*  renvoie 1 si pile pleine, 0 sinon */
int pileMixteEstPleine(PileMixte p);

#endif


