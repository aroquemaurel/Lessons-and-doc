/* declarations */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef char TabCar60[60+1];

typedef struct
{
	int codeProd;
	TabCar60 designation;
	float puHT;
} EnregProd;

typedef EnregProd * PtrEnregProd;

PtrEnregProd unProduit;

/* allocation memoire dynamique de l'enregistrement unProduit */
unProduit=(PtrEnregProd)malloc(sizeof(EnregProd));

if(unProduit == NULL)
{
	/* afficher un message d'erreur et arreter le processus */
	perror("echec malloc");exit(1);
	/* ou lever une exception (sera vu au TD4) */
}

/* exemples d'utilisation de l'enregistrement unProduit */
unProduit->codeProd=12345;
(* unProduit).puHT=20.45;
strcpy(unProduit->designation, "chocolat poudre YABON 250g");

