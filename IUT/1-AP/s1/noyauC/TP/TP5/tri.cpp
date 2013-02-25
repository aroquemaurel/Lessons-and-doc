#include <string.h>
#include <iostream>
using namespace std;

void trierABulles(int *tab, int tailleTab); 
void trierParSelection(int *tab, int tailleTab);

int main (void)
{
	int tab[11] = {0, 1, 6548, 3, 2, 21, 54, 23, 4, 235, 24}; //initialisation du tableau à trier
	trierParSelection(tab, 10); //tri par séléction²
//	trierABulles(tab, 10)- //tri à bulle;

	/* affichage du tableau trié */	
	for (int i = 0; i <= 10; i++) 
	{
		cout << tab[i] << endl;
	}
}
void trierParSelection(int *tab, int tailleTab)
{
	int indicePetitElement = tab[0], echange = 0;
	for(int j = 0; j < tailleTab; j++)
	{
		indicePetitElement= j;
		for(int i = j; i <= tailleTab; i++)
		{
				/* on cherche le plus petit élément */
			if(tab[i] < tab[indicePetitElement])
			{
				indicePetitElement= i;
			}
		}
			
		echange = tab[indicePetitElement] ;
		tab[indicePetitElement] = tab[j];
		tab[j] = echange;

	}
}

void trierABulles(int *tab, int tailleTab)
{
	int echange = 0;
	bool tri = 0;
 
	while(!tri)
	{
		tri = 1;
		for (int i = 0; i <= tailleTab; i++)
		{
			if((tab[i]) > (tab[i+1]))
			{
				echange = tab[i];
				tab[i] = tab[i+1];
				tab[i+1] = echange;
				tri=0;
			}
		}
	}

}
