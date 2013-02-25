#include "tableau.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>

// tri le tableau t de n entiers par la methode des bulles
// necessite 1 <= n <= LG_MAX
void trierBulles (Tableau t, const int n, int &nbA, int &nbC);

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
			trierBulles (t, lg, nbA, nbC);
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

// tri le tableau t de n entiers par la methode des bulles
// necessite 1 <= n <= LG_MAX
void trierBulles (Tableau t, const int n, int &nbA, int &nbC) 
{
    int dernierEchange = 1;
    int dernier;
    bool trie = false;

    while (!trie)
    {
		nbC++;
        trie = true;
		dernier = dernierEchange;
        for (int i = n-1; i >= dernier; i--)
        {
			nbC++;
            if (t[i] < t[i-1])
            {
				nbC++;
                const int aux = t[i];
                t[i] = t[i-1];
                t[i-1] = aux;
                trie = false;
                dernierEchange = i;
				nbA += 3;
            }
        }
    }
}
