/* Exemple de menu */
#include <stdio.h>
#include <string.h>

typedef enum {FAUX=0, VRAI=1} Booleen ;

/* declarations des fonctions */
void afficherMenu(void);
void saisirChoix(int * n);
void traitement1(void);
void traitement2(void);
void traitement3(void);

/* programme principal */
int main(int argc, char *argv[])
{
	int choix ;
	Booleen fini ;

	fini = FAUX ;
	while (! fini)
	{
		afficherMenu( );
		saisirChoix(&choix);

		switch (choix)
		{
			case 1: 
				traitement1( ); 
				break;
			case 2: 
				traitement2( );
				break;
			case 3: 
				traitement3( );
				break;
			case 9: 
				fini = VRAI;
				break;
			default:
		}
	}
}

printf ("\n*** Erreur: choix invalide \n") ;

/* definitions des fonctions */
void afficherMenu(void)
{
	printf ("\nMENU\n") ;
	printf ("----\n") ;
	printf ("1- traitemnt 1\n") ;
	printf ("2- traitemnt 2\n") ;
	printf ("3- traitemnt 3\n") ;
	printf ("..........\n") ;
	printf ("9- arreter le programme\n\n") ;
}
void saisirChoix(int * n)
{
	char tampon[64];
	int dernier;
	int ret;

	/* saisie du choix */
	printf ("Entrer votre choix: ") ;
	fgets (tampon, 64, stdin) ;

	dernier = strlen (tampon)-1 ;
	if (tampon[dernier] == '\n')
		tampon[dernier] = '\0' ;

	ret=sscanf(tampon, "%d", n) ;
	if (ret != 1)
		* n=0 ;
}
void traitement1(void)
{
	printf ("\ntraitement 1\n") ;
}
void traitement2(void)
{
	printf ("\ntraitement 2\n") ;
}
void traitement3(void)
{
	printf ("\ntraitement 3\n") ;
}

