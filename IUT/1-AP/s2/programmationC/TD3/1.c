/* declarations */
#include <stdlib.h>
#include <stdio.h>

#define LG_MAX 30
typedef int * PtrEntier;

PtrEntier tabVal;

/* allocation memoire dynamique du tableau d'entiers */
tabVal=(PtrEntier)malloc(LG_MAX * sizeof(int));

if(tabVal == NULL)
{
	/* afficher un message d'erreur et arreter le processus */
	perror("echec malloc");
	exit(1);
	/* ou lever une exception (sera vu au TD4) */
}

/* exemple d'utilisation du tableau */
tabVal[i]= -25;

