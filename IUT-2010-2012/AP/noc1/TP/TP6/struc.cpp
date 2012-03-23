#include <string.h>
#include <iostream>
using namespace std;

struct Date
{
	int jour;
	int mois;
	int annee;
}; 

int main (void)
{
	Date aujourdhui = {1, 1, 2010};
	
	cout << "Nous sommes le " << aujourdhui.jour << "/" << aujourdhui.mois << "/" << aujourdhui.annee << endl;

	cout << "Ou plutôt le " << aujourdhui.jour ;
	switch(aujourdhui.mois)
	{
		case 1:
			cout << "Janvier";
		break;
		case 2:
			cout << "Février";
		break;
		case 3:
			cout << "Mars";
		break;
		case 4:
			cout << "Avril";
		break;
		case 5:
			cout << "Mai";
		break;
		case 6:
			cout << "Juin";
		break;
		case 7:
			cout << "Juillet";
		break;
		case 8:
			cout << "Aout";
		break;
		case 9:
			cout << "Septembre";
		break;
		case 10:
			cout << "Octobre";
		break;
		case 11:
			cout << "Novembre";
		break;
		case 12:
			cout << "Décembre";
		break;
	}
	cout << aujourdhui.annee << endl;
}
