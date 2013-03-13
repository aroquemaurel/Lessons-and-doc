#ifndef __LISTEDOUBLEMENTCHAINE
#define __LISTEDOUBLEMENTCHAINE

typedef struct LDCInterne* LDC;

LDC creer(void);
LDC ajouter(LDC, Element);
void affichageCroisant(LDC);
void affichageDecroissant(LDC liste);
LDC supprimer(LDC, Element);

#endif
