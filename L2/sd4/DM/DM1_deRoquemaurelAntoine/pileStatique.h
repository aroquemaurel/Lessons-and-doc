#ifndef STATIC_STACK_H
#define STATIC_STACK_H

/*  Taille maximale de la Pile */
#define TAILLE_MAX 1000 

/*  Définition cachée du type */
typedef struct pileStatiqueCachee *PileStatique;

/*  Constructeur */
/*  Créé une pile statique */
PileStatique pileStatiqueCreer();

/*  Empile un entier sur une PileStatique */
/*  précondition d’implantation: !pileStatiqueEstPleine(p) */
void pileStatiqueEmpiler(PileStatique* p, int v);

/*  Accesseurs */
/*  accède et supprime la valeur du sommet de pile*/
/*  précondition : !pileStatiqueEstVide(p) */
int pileStatiqueDepiler(PileStatique* p);

/*  accède à la valeur du sommet de pile*/
/*  précondition : !pileStatiqueEstVide(p) */
int pileStatiqueSommet(PileStatique p);

/*  Destructeur */
/*  libère la mémoire occupée par la pile statique */
void pileStatiqueDetruire(PileStatique *p);

/*  indique si la pile est vide */
/*  renvoie 1 si pile vide, 0 sinon */
int pileStatiqueEstVide(PileStatique p);

/*  indique si la pile est pleine*/
/*  renvoie 1 si pile pleine, 0 sinon */
int pileStatiqueEstPleine(PileStatique p);

#endif
