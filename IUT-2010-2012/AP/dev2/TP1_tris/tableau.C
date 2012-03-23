#include "tableau.h"
#include <stdlib.h>
#include <iostream>

using namespace std;
// ecrit les n premiers elements du tableau t
// necessite 1 <= n <= LG_MAX
void ecrireTableau (const Tableau t, const int n)
{
    cout << t[0];
    for (int i = 1; i < n; i++)
    {
        cout << ", " << t[i];
    }
	cout << endl;
}

// remplit les n premiers elements du tableau t avec des valeurs aleatoires
// necessite 1 <= n <= LG_MAX
void remplirTableau (Tableau t, const int n)
{
    for (int i = 0; i < n; i++)
    {
        t[i] = random();
    }
}
