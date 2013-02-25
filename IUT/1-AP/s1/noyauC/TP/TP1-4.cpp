#include <iostream>

int main (void)
{
	int n;
	
	printf ("Entrer un chiffre : ");
	
	while (scanf ("%d", &n) != 1)  {
		printf("On a dit un chiffre abruti !\n") ;	
		while(getchar()!='\n')  ;
		printf ("Entrer un chiffre : ");
	} 
	
	printf ("Le chiffre est %d\n", n);
	
	
	return (0);
}
