#ifndef __PLATEAU
#define __PLATEAU
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "pile.h"

typedef T_pile* Plateau;
void plateau_deplacerAnneau(Plateau pPlateau, const int pBegin, const int pEnd);
Plateau plateau_initialiser(const int pNbelement);
void plateau_afficher(const Plateau pPlateau);
bool plateau_deplacementEstPossible();

#endif
