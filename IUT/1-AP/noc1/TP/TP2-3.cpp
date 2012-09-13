#include "/usr/local/public/BIBLIOC++/entreeSortie.h"
#include "/usr/local/public/BIBLIOC++/chaine.h"

const int NBMAX = 1000 ;	
typedef bool TabBool [NBMAX] ;	// tableau de booleens

void main ()
{
	TabBool premiers ;	
	int i ;				
       	int j ;			
	int n ;		
	ecrire ( uneChaine ("Donnez la valeur maximum : ") );
	lire ( n ) ;
	for ( i = 1 ; i <= n ; i++ )
	{
		premiers [ i ] = true ;
	} 
	ecrire ( uneChaine ("Voici la suite des nombres premiers de 2 a ") );
	ecrireNL ( n ) ;
	for ( i = 2 ; i <= n ; i++ )
	{	
		if ( premiers [i])                                                
		{
			ecrire ( i ) ;
			ecrire ( ' ' ) ;
		}
	}			
	for ( j = i + i ; j <= n ; j = j + i ) 
	{
		premiers [ j ] = false ;
	}			
	ecrireNL () ;	
	
}	
