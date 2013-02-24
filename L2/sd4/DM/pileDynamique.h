#ifndef __PILE_DYNAMIQUE
#define __PILE_DYNAMIQUE

PileDynamique pileDynamiqueCreer();
void pileDynamiqueEmpiler(PileDynamique p, Element v);
int pileDynamiqueDepiler(PileDynamique p);
int pileDynamiqueEstVide(PileDynamique p);
int pileDynamiqueEstPleine(PileDynamique p);
int pileDynamiqueSommet(PileDynamique p);
void PileDynamiqueAfficher(PileDynamique pStack);

#endif


