#include "/home/satenske/cours/AP/chaine.h"
#include "tableau.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>

// tri le tableau t de n entiers par la methode du tri rapide
// necessite 1 <= n <= LG_MAX
using namespace std;
void trierPivot (Tableau t, const int n, int &nbA, int &nbC) ;
void trierTranche (Tableau t, const int iDeb, const int iFin, int &nbA, int &nbC);

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
			nbA = 0;
			nbC = 0;
			trierPivot(t, lg, nbA, nbC);
			moyenneNbA += nbA;
			moyenneNbC += nbC;
		}
		moyenneNbA /= 100;
		moyenneNbC /= 100;
		cout << lg << " " << moyenneNbA << " " << moyenneNbC << endl;
	}
}

// tri le tableau t de n entiers par la methode du tri rapide
// necessite 1 <= n <= LG_MAX
void trierPivot (Tableau t, const int n, int &nbA, int &nbC) 
{
    trierTranche (t, 0, n-1, nbA, nbC);
}

// tri recursif de la tranche iDeb..iFin du tableau t
void trierTranche (Tableau t, const int iDeb, const int iFin, int &nbA, int &nbC)
{
    int i = iDeb;
    int j = iFin;
    int pivot;
    if (i < j)
    {
		nbC++;
        pivot = t[i];
		nbA++;
        while (i < j)
        {
			nbC++;
            if (t[j] >= pivot)
            {
				nbC++;
                j--;
            }
            else
            {
                if (t[i+1] < pivot)
                {
					nbC++;
					nbA++;
                    t[i] = t[i+1];
                    i++;
                }
                else
                {
					nbC++;
					nbA+=2;
                    t[i] = t[j];
                    t[j] = t[i+1];
                    i++;
                    j--;
                }
            }
        }
        t[i] = pivot;
		nbA++;
        trierTranche (t, iDeb, i-1, nbA,nbC);
        trierTranche (t, i+1, iFin, nbA, nbC);
    }
}
