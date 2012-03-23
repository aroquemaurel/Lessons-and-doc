#include "/home/satenske/cours/AP/chaine.h"
#include "tableau.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;
// tri le tableau t de n entiers par la methode du tri Shell
// necessite 1 <= n <= LG_MAX
void trierShell (Tableau t, const int n, int &nbA, int &nbC);

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
			trierShell (t, lg, nbA, nbC);
			moyenneNbA += nbA;
			moyenneNbC += nbC;
		}
		moyenneNbA /= 100;
		moyenneNbC /= 100;
		cout << lg << " " << moyenneNbA << " " << moyenneNbC << endl;
	}
}

// tri le tableau t de n entiers par la methode du tri Shell
// necessite 1 <= n <= LG_MAX
void trierShell (Tableau t, const int n, int &nbA, int &nbC)
{
    int inc = n / 2;
    int j;
    while (inc > 0)
    {
		nbC++;
        for (int i = inc + 1; i <= n; i++)
        {
			nbC++;
            j = i - inc - 1;
			nbA++;
            while (j >= 0)
			{
				nbC++;
                if (t[j] > t[j+inc])
                {
					nbC++;
                    const int aux = t[j];
                    t[j] = t[j+inc];
                    t[j+inc] = aux;
                    j = j - inc;
					nbA += 4;
                }
                else
                {
                    j = -1;
					nbA++;
                }
            }
        }
        inc = inc / 2;
    }
}
