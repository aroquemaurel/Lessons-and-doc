#ifndef __LISTEDOUBLEMENTCHAINE
#define __LISTEDOUBLEMENTCHAINE

typedef struct LDCInterne* LDC;
// TODO refactor
typedef struct etCell {
	struct etCell* prec;
	struct etCell* suiv;
	Element val;
} Cell;

typedef struct LDCInterne {
	Cell* premier;
	Cell* dernier;
} LDCInterne;
///

LDC creer(void);
LDC ajouter(LDC, Element);
void affichageCroisant(LDC);
void affichageDecroissant(LDC liste);
LDC supprimer(LDC, Element);

#endif
