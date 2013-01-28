#ifndef __PILEDYNAMIQUE
#define __PILEDYNAMIQUE

typedef int Element;
typedef struct etCel {
	Element value;
	struct etCel* next;
} Cel;

typedef Cel* Pile;

Pile pile_init();
void pile_afficher(Pile pStack);
bool pile_estVide(const Pile pStack);
bool pile_pleine(const Pile pStack);
void pile_empiler(Pile* pStack, Element pElem);
Element pile_depiler(Pile* pStack);
Pile pile_saisir();
Element pile_sommet(Pile pStack);

#endif


