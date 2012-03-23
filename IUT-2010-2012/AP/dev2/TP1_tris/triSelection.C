#include "tableau.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>
// tri le tableau t de n entiers par la methode des bulles // necessite 1 <= n <= LG_MAX
void trierSelection(Tableau t, const int n, int &nbA, int &nbC) ;
using namespace std;

int main() 
{ 
	Tableau t;
	int moyenneNbA=0;
	int moyenneNbC=0;
	int nbA = 0, nbC = 0;
    // initialisation du generateur de nombres aleatoires avec l'heure courante
    for(int lg = 0; lg <= LG_MAX; lg++)
	{
		for(int i =0; i <= 100; i++)
		{
			srandom(time(NULL));
			// initialisation du tableau avec des valeurs aleatoires
			remplirTableau (t, lg);
			// affichage du tableau initial
			// ecrireTableau (t, LG);
			// tri du tableau
			nbA = 0;
			nbC = 0;
			trierSelection(t, lg, nbA, nbC);
			moyenneNbA += nbA;
			moyenneNbC += nbC;
		}
		moyenneNbA /= 100;
		moyenneNbC /= 100;
		cout << lg << " " << moyenneNbA << " " << moyenneNbC << endl;
	}
    // affichage du tableau trie
//    ecrireTableau (t, LG);
}

// tri le tableau t de n entiers par la methode du tri par insertion 
// necessite 1 <= n <= LG_MAX
void trierSelection(Tableau t, const int n, int &nbA, int &nbC) 
{
	int plusPetit = t[0]; // le plus petit élément du tableau amputé
	int nTaille = 0; //la taille du tableau amputé
	int iPlusPetit = 0; //l'indice du plus petit élément du tableau amputé

	while(nTaille < n)
	{
		nbC++;
		/* on cherche le plus petit élément du tableau de taill nTaille*/
		for(int i=n-1; i >= nTaille; i--)
		{
			if(t[i] < plusPetit)
			{
				plusPetit = t[i]; 
				iPlusPetit=i;
				nbA+=2;
				nbC++;
			}
			nbC++;
		}

		for(int j=iPlusPetit; j >= nTaille; j--)
		{	
			nbC++;
			t[j] = t[j-1]; //on décale les éléments du tableau vers la droite
			nbA+=2;
		}	
	
		/* on insère le plus petit élément puis on réduit la taille du tableau*/	
		t[nTaille] = plusPetit;
		nbA+=2;
		nTaille++; 

		/* une initialisation des valeurs*/
		plusPetit = t[n-1]; 
		nbA+=2;
		iPlusPetit = n-1;
	}
}
