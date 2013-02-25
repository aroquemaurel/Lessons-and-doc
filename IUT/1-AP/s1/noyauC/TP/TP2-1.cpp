------------------------------------------
TP : TP2
------------------------------------------
#include "/usr/local/public/BIBLIOC++/entreeSortie.h"
#include "/usr/local/public/BIBLIOC++/chaine.h"

const int NBMAX = 1000;
typedef bool TabBool [NBMAX]; //type tableau de booleens

void main()
{		
	int x;	
	int y;	
	int resul;
	char op	;	
	bool correct;	//indicateur d'ecriture correcte
	
	ecrireNL( uneChaine ( "CALCULS sur des NOMBRES ENTIERS") ) ;
	ecrireNL( uneChaine ("entrez un calcul sous la forme operande1 operateur operande2 "));
	lire(x);
	lire (op);
	lire (y);
	correct = true;
	switch (op)		
	{	
		case '+' : 	resul= x+y;				
		case '-' : 	resul= y-x; 
		case '*' : 	resul= x*y; 
		case '/' : 	resul= x%y;	
		case '%' : 	resul= x/y;
		default  : 	correct=false;	
	}
	if(correct)
	{
		ecrire ( uneChaine ( "Le resultat est "));ecrireNL ( resul );
	}
	else 
		ecrireNL( uneChaine(  "operateur invalide" )) ;
}

