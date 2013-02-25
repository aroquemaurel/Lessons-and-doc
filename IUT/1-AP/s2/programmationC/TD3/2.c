/* declarations */
#include <stdlib.h>
#include <stdio.h>
#define LG_MAX 256

typedef char * PtrCar;

PtrCar tampon;

/* allocation memoire dynamique du tableau de caracteres */
tampon=(PtrCar)malloc(LG_MAX+1);

if(tampon == NULL)
{
	/* afficher un message d'erreur et arreter le processus */
	perror("echec malloc");
	exit(1);
	/* ou lever une exception (sera vu au TD4) */
}

/* exemple d'utilisation du tableau */
/* saisie d'une chaine de caracteres au clavier */
fgets(tampon,LG_MAX+1,stdin);

