#include <string>
#include <iostream> 

#include "matrices.h" 
using namespace std;

bool estImpair(const int i)
{
int test = 0;

test = i%2;
if(test == 0)	
return false;
else
return true;
}

void ecrireCarre (const Carre carre, const int n)
throw (string)
{
	/* les exceptions */
	if (n < 0) 
		throw string ("Err 1.1 Ordre inférieur à zéro");
	else if (n > TAILLE)
		throw string ("Err 1.2 Ordre trop grand"); 

	for (int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			 /* pour aligner les nombres des matrices */
			if(carre[i][j] < 10 && n > 4){
				//un espace de plus pour les nombres < 10
				cout << " " << carre[i][j] << " " << " " ; 
			}
			else{
				cout << carre[i][j] << " " << " " ;
			}

		}
		cout << endl;
	}
	cout << endl;

}

void lireCarre (Carre &carre, const int n)
throw (string)
{
	/* les exceptions */
	if (n < 0) 
		throw string ("Err 1.1 Ordre inférieur à zéro");
	else if (n > TAILLE)
		throw string ("Err 1.2 Ordre trop grand"); 

	cout << "Entrer " << n << " nombres svp" << endl;
	for(int i = 0; i < n; i++)
	{
		cout << i+1 << "ème " << "ligne" << endl;
		for(int j = 0; j < n; j++)
		{
			cin >> carre[i][j];
			cout << " " ;
		}
		cout << endl << endl;
	}	
}

void initialiserCarre (Carre &carre, const int n)
throw (string)
{
	/* les exceptions */
	if (n < 0) 
		throw string ("Err 1.1 Ordre inférieur à zéro");
	else if (n > TAILLE)
		throw string ("Err 1.2 Ordre trop grand"); 

	for(int i=0; i < n; i++)
	{
		for (int j =0; j < n; j++)
		{
			carre[i][j] = 0;
		}
	}	
}
