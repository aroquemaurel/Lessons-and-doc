#include "/usr/local/public/BIBLIOC++/entreeSortie.h"
#include "/usr/local/public/BIBLIOC++/chaine.h"

const int NBMAX = 1000 ; 
typedef bool TabBool [NBMAX] ;	// type tableau de booleens

int main (void)
{
	TabBool premiers ;	
	int i,j,n ;				
	ecrire ( uneChaine ("Donnez la valeur maximum : ") );
	lire ( n ) ;
	i = 1 ;
	while ( i <= n )
	{
		premiers [ i ] = true ;
		i = i + 1 ;
	} 
	ecrire ( uneChaine ("Voici la suite des nombres premiers de 2 a ") );
	ecrireNL ( n ) ;
	i = 2;
	while ( i <= n )
	{
		if ( premiers [ i ] )
		{
			ecrireNL ( i ) ;	
			j = i + i ;
			while ( j <= n )
			{
				premiers [ j ] = false ;	
				j = j + i ;	
			} 
		} 
		i = i + 1 ;	
	
	}

	return 0 ;
}
