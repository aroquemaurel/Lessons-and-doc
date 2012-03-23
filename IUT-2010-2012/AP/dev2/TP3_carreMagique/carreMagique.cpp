#include <iostream>
#include <string>

#include "matrices.h"
#include "carreMagique.h"

using namespace std;


int sommeLigne(const Carre carre, const int n, const int i)
throw (string)
{
	/* les exceptions */
	if (n < 0) 
		throw string ("Err 1.1 Ordre inférieur à zéro");
	else if (n > TAILLE)
		throw string ("Err 1.2 Ordre trop grand"); 

	if (i < 0)
		throw string ("Err 2.1 Numéro de ligne inférieur à zéro");
	else if (i > n-1)
		throw string ("Err 2.2 Numéro de ligne superieur à n-1");


	int somme = 0;

	for(int j = 0; j < n; j++){ somme += carre[i][j]; }

	return somme;
}
int sommeColonne(const Carre carre, const int n, const int j)
throw (string)
{
	/* les exceptions */
	if (n < 0) 
		throw string ("Err 1.1 Ordre inférieur à zéro");
	else if (n > TAILLE)
		throw string ("Err 1.2 Ordre trop grand"); 

	if (j < 0)
		throw string ("Err 2.1 Numéro de colonne inférieur à zéro");
	else if (j > n-1)
		throw string ("Err 2.2 Numéro de colonne superieur à n-1");


	int somme = 0;

	for(int i = 0; i < n; i++)
	{
		somme += carre[i][j];
	}
	return somme;
}

int sommeDiagonale1 (const Carre carre, const int n)
throw (string)
{
	/* les exceptions */
	if (n < 0) 
		throw string ("Err 1.1 Ordre inférieur à zéro");
	else if (n > TAILLE)
		throw string ("Err 1.2 Ordre trop grand"); 

	int somme = 0;
	int j = 0;

	for(int i = 0; i < n; i++)
	{
		somme += carre[i][i];
	}
	return somme;
}	

int sommeDiagonale2 (const Carre carre, const int n)
throw (string)
{
	/* les exceptions */
	if (n < 0) 
		throw string ("Err 1.1 Ordre inférieur à zéro");
	else if (n > TAILLE)
		throw string ("Err 1.2 Ordre trop grand"); 

	int somme = 0;
	int j = 0;
	
	for(int i = 0; i < n; i++)
	{
		j = i;
		somme += carre[j][j];
	}

	return somme;
}	

bool estCarreMagique (const Carre carre, const int n)
throw (string)
{
	/* les exceptions */
	if (n < 0) 
		throw string ("Err 1.1 Ordre inférieur à zéro");
	else if (n > TAILLE)
		throw string ("Err 1.2 Ordre trop grand"); 


	int somme = 0;
	bool estCarre = true;

	/* les lignes*/
	for(int i=0; i<=n; i++)
	{
		if(sommeLigne(carre, n, 0) != somme)
			estCarre = false;
	}
	/* les colonnes*/
	for(int i=0; i<=n; i++)
	{
		if(sommeColonne(carre, n, 0) != somme)
			estCarre = false;
	}
	if(sommeDiagonale1(carre, n) != somme)
		estCarre = false;

	if(sommeDiagonale2(carre, n) != somme)
		estCarre = false;
	
	return estCarre;
}

void construireCarreMagique(Carre &carre, const int n)
throw (string)
{
	/* les exceptions */
	if (n < 0) 
		throw string ("Err 1.1 Ordre inférieur à zéro");
	else if (n > TAILLE)
		throw string ("Err 1.2 Ordre trop grand"); 

	if (!estImpair(n))
		throw string ("Err 3 Ordre pair et différent de 6"); 

	int i=0; //Ligne de la matrice
	// sauvegarde de la ligne (permet de revenir a la case précédente si on tombe sur une case occupée)
	int iBack = 0; 
	int j=0; //Colonne de la matrice
	// sauvegarde de la colonne (permet de revenir a la case précédente si on tombe sur une case occupée)
	int jBack= 0; 
	int nombreCourant = 2; 
	bool finit = false; //finit = true veux dire que le carré est entierrement généré

	initialiserCarre(carre, n);

	/* on initialise la matrice avec 1, centré sur la première ligne*/
	j = n/2;
	carre[i][j] = 1;

	while(!finit) //tantque le carré n'est pas généré
	{
		 /* on fait la sauvegarde de notre position */
		iBack = i;
		jBack = j;
		
		/*on avance en diagonale vers la droite*/
		i--;
		j++;

		if(i < 0) //ligne supérieure
			i = n - 1;

		if(j > n-1) //colonne superieure
			j = 0;

			/* si il y a déjà un nombre sur la case */
		if(carre[i][j] != 0){ 
			/* on revient a la case précédente*/
			i = iBack;
			j = jBack;
			i++;
		}

		if(nombreCourant == n*n) // on a finit quand toutes les cases sont remplis
			finit = true;
		
		carre[i][j] = nombreCourant;
		nombreCourant++;
	}
}

void construireCarreMagique6(Carre &carre)
{
	Carre carre33;
	construireCarreMagique(carre33, 3);

	for(int i = 0; i < 6; i++)
	{
		for(int j = 0; j < 6; j++)
		{
			carre[i][j] = MEDGIG[i][j] * 9 + carre33[i/2][j/2];			
		}
	}
}
