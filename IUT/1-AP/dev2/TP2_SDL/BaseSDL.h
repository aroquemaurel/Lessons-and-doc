#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <SDL.h>

using namespace std;

typedef struct
{
    SDL_Surface* affichage;
} ecran;



void attendre(void);

void afficherPixel(ecran e, int x, int y, char couleur) throw (string);


ecran creerEcran(void);

void actualiser(ecran e);


