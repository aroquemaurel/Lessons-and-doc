#ifndef DYNAMIC_STACK_H
#define DYNAMIC_STACK_H
#include "element.h"

/*  Définition cachée du type */
typedef struct etCell* PileDynamique; //TODO

/*  Constructeur */
/*  Créé une pile statique */
PileDynamique pileDynamiqueCreer();

/*  Empile un entier sur une PileDynamique */
/*  précondition d’implantation: !PileDynamiqueEstPleine(p) */
void pileDynamiqueEmpiler(PileDynamique* p, Element v);

/*  Accesseurs */
/*  accède et supprime la valeur du sommet de pile*/
/*  précondition : !PileDynamiqueEstVide(p) */
Element pileDynamiqueDepiler(PileDynamique* p);

/*  accède à la valeur du sommet de pile*/
/*  précondition : !PileDynamiqueEstVide(p) */
Element pileDynamiqueSommet(PileDynamique p);

/*  Destructeur */
/*  libère la mémoire occupée par la pile statique */
void pileDynamiqueDetruire(PileDynamique *p);

/*  indique si la pile est vide */
/*  renvoie 1 si pile vide, 0 sinon */
int pileDynamiqueEstVide(PileDynamique p);

/*  indique si la pile est pleine*/
/*  renvoie 1 si pile pleine, 0 sinon */
int pileDynamiqueEstPleine(PileDynamique p);

#endif


