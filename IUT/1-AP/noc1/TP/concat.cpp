------------------------------------------
TP : ASCII
------------------------------------------
#include "/usr/local/public/BIBLIOC++/entreeSortie.h"
#include "/usr/local/public/BIBLIOC++/chaine.h"

#include <iostream>

int main() {
	int x;
	char y;
	
	ecrire (uneChaine("Ecrire une lettre : "));
	lire (y);
	printf ("%d", y);
	
	ecrire (uneChaine("Ecrire un chiffre : "));
	lire (x);
	putchar (x);
	ecrire (uneChaine("\n"));
	return 0 ;
}
------------------------------------------
TP : figures
------------------------------------------
#include "/usr/local/public/BIBLIOC++/entreeSortie.h"
#include "/usr/local/public/BIBLIOC++/chaine.h"

int main ()
{
	int iNombre;
	int cpt=0;
	int cpt2 = 0;
	int u = iNombre;

	ecrire(uneChaine("Entrer le nombre d'étoile sur la premiere ligne : "));
	lire (iNombre);
	ecrire(uneChaine("\n"));
	
		for (int i = 0 ; i < iNombre ; i++) {
			for (int j = 0 ; j < i+1 ; j++) {
			ecrire(uneChaine("*")) ;		
			}
			ecrireNL() ;
		}
}

------------------------------------------
TP : frequente
------------------------------------------
#include "/usr/local/public/BIBLIOC++/entreeSortie.h"
#include "/usr/local/public/BIBLIOC++/chaine.h"

int main ()
{
	Chaine x;
	char caractereActuel ;
	int iMax  = 0 ;
	int iCompteur = 0 ;
	int iRang = 0 ;
	
	
	ecrire (uneChaine("entrer une chaine de caractere : "));
	lire (x);

	for (int i = 0 ; i < longueur (x) ; i++)
	{
		caractereActuel = ieme(x, i) ;
		iCompteur = 0 ;

		for (int j = i ; j < longueur(x) ; j++) {
			if (ieme(x, j) == caractereActuel)  {
				iCompteur ++ ;
			}
		}
		
		if (iCompteur > iMax) {
			iMax = iCompteur ;
			iRang = i ;
		}
	}

	ecrire(uneChaine("Le caractere le plus récurrent est : ")) ;
	ecrireNL(ieme(x, iRang)) ;
	ecrire(uneChaine("Il apparait ")) ;
	ecrire(iMax) ;
	ecrireNL(uneChaine(" fois.")) ;
	

}
------------------------------------------
TP : gele
------------------------------------------
#include "/usr/local/public/BIBLIOC++/entreeSortie.h"
#include "/usr/local/public/BIBLIOC++/chaine.h"

int iTemp; // Température

int main ()
{
	ecrire (uneChaine("Voici la liste des liquides : \n- eau \n- fuel\n- super\n- ordinaire \n- eau salée\n\n"));
	ecrire (uneChaine("Saisir une température : "));
	lire (iTemp);
	switch (iTemp)
	{
		case (-23) : ecrireNL(uneChaine("Le super gèle"));
		case (-13) : ecrireNL(uneChaine("L'ordinaire gèle"));
		case (-5) : ecrireNL(uneChaine("Le fuel gèle"));
		case (0) : ecrireNL(uneChaine("L'eau gèlee"));
					break;
		default : ecrireNL(uneChaine("Aucun des liquides ne gèlent à cette température"));
	}
}
------------------------------------------
TP : Intervalles
------------------------------------------
#include "/usr/local/public/BIBLIOC++/entreeSortie.h"
#include "/usr/local/public/BIBLIOC++/chaine.h"

// Enregistrement d'un intervalle

struct Intervalle
{
	int inf;
	int sup;
};


// Procédure chargée de la saisie d'un intervalle

void saisirIntervalle (Intervalle &i)
{
	int iBuffer ;

	ecrire (uneChaine("Borne inf ?"));
	lire(iBuffer) ;
	i.inf = iBuffer;
	ecrire (uneChaine("Borne sup ?"));
	lire(iBuffer) ;
	i.sup = iBuffer;
}


// Procédure chargée d'afficher un intervalle 

void afficherIntervalle (const Intervalle intervalle1)
{
	ecrire (uneChaine("["));
	ecrire (intervalle1.inf);
	ecrire (uneChaine(","));
	ecrire (intervalle1.sup);
	ecrire (uneChaine("]"));
}

// Fonction intersection renvoyant l'intersection de deux intervalles

Intervalle intersection (Intervalle intervalle1, Intervalle intervalle2)
{
	Intervalle inter = {0,0} ; 

	if (intervalle1.sup < intervalle2.inf) {
		ecrire(uneChaine("Ensemble vide")) ;
	} else {
		if(intervalle1.inf > intervalle2.sup) {
			ecrire(uneChaine("Ensemble vide"));
		} else {
			inter.inf = intervalle2.inf ;
			inter.sup = intervalle1.sup ;
		}
	}


	return inter ;

}

// Programme

int main (void)
{
	Intervalle i1, i2 ;
	
	saisirIntervalle(i1) ;
	saisirIntervalle(i2) ;

	afficherIntervalle(i1) ;
	afficherIntervalle(i2) ;

	afficherIntervalle(intersection(i1,i2)) ;

	
	return 0;
}
------------------------------------------
TP : MAJ
------------------------------------------
#include "/usr/local/public/BIBLIOC++/entreeSortie.h"
#include "/usr/local/public/BIBLIOC++/chaine.h"

bool estMinuscule (char a)
{
	return (a >='a' && a <= 'z');
}

bool estMajuscule (char a)
{
	return (a >='A' && a <= 'Z');
}

bool estUnChiffre (int a)
{
	return (a >= 0 && a <= 9);
}

int main ()
{
	char a;

	ecrire (uneChaine("Saisir un caractère : "));
	lire (a);

	if (estMinuscule (a))
	{	
		ecrire (uneChaine("le caractere entré est une minuscule \n"));
	} else if (estMajuscule (a)) { 
		ecrire (uneChaine("le caractere entré est une majsucule\n"));
    } else {
		ecrire (uneChaine ("est un chiffre\n"));
	}
	
	return 0;
}
		
------------------------------------------
TP : MAJ2
------------------------------------------
#include "/usr/local/public/BIBLIOC++/entreeSortie.h"
#include "/usr/local/public/BIBLIOC++/chaine.h"

bool estMinuscule (char a)
{
	return (a >='a' && a <= 'z');
}

bool estMajuscule (char a)
{
	return (a >='A' && a <= 'Z');
}

bool estUnChiffre (char a)
{
	return (a >= '0' && a <= '9');
}

int main ()
{
	char a;

	ecrire (uneChaine("Saisir une suite de caractère terminée par '.' : "));
	do
	{
	lire (a);
	}	
	while (a != '.') ;
/* if (estMinuscule (a))
	{	
		ecrire (uneChaine("le caractere entré est une minuscule \n"));
	} else if (estMajuscule (a)) { 
		ecrire (uneChaine("le caractere entré est une majsucule\n"));
    } else {
		ecrire (uneChaine ("est un chiffre\n"));
	}
*/	
	return 0;
}
		
------------------------------------------
TP : Menu
------------------------------------------
#include "/usr/local/public/BIBLIOC++/entreeSortie.h"
#include "/usr/local/public/BIBLIOC++/chaine.h"

int iMenu ;     //Choix du menu

int main ()
{
	ecrire (uneChaine("Voici la liste du menu : \n- Choix 1 : Se suicider\n- Choix 2 : Sauter par la fenetre\n- Choix 3 : Se tirer une balle\n- Choix 4 : rester en vie"));
	ecrire (uneChaine("Saisir un choix en entrant le numero du choix : "));
		lire (iMenu);
	ecrire(uneChaine("\n"));
	while (iMenu < 1 || iMenu > 4) 
	{
		ecrireNL(uneChaine("Erreure - Saisir un choix en entrant le numero du choix compris entre 1 et 4 : "));
		lire (iMenu);
	} 

	switch (iMenu)
	{	
		case (1): 
			ecrireNL(uneChaine("Vous avez choisi de vous suicider"));
		break;
		case (2):
			 ecrireNL(uneChaine("Vous avez choisi de sauter par la fenetre"));
		break;
		case (3): 
				ecrireNL(uneChaine("Vous avez choisi de vous tirer une balle"));
		break;
		case (4): 
			ecrireNL(uneChaine("Vous avez choisi de rester en vie"));
		break;
	}
}
------------------------------------------
TP : minToMaj
------------------------------------------
#include "/usr/local/public/BIBLIOC++/entreeSortie.h"
#include "/usr/local/public/BIBLIOC++/chaine.h"

bool estMinuscule (char a)
{
	return (a >='a' && a<= 'z');
}

bool estMajuscule (char a)
{
	return (a >='A' && a<= 'Z');
}

int main ()
{
	Chaine x;

	ecrire (uneChaine("entrer une chaine de caractere : "));
	lire (x);
	
	for (int i = 0 ; i < longueur(x) ; i++)
	{
		if (estMinuscule (x.chaine[i]))
		{	
			x.chaine[i] = 'A' + (x.chaine[i] - 'a') ;
		}
		else if (estMajuscule (x.chaine[i]))
		{
			x.chaine[i] = 'a' + (x.chaine[i] - 'A') ;
		}	

	}

	ecrireNL (x) ;

	return 0 ;
}


------------------------------------------
TP : moyenne
------------------------------------------
#include "/usr/local/public/BIBLIOC++/entreeSortie.h"
#include "/usr/local/public/BIBLIOC++/chaine.h"

int main ()
{
	int entier;
	int moyenne = 0;
	
	ecrire (uneChaine("Entrer une note : "));
	lire (entier);
	moyenne = (moyenne + entier);

	ecrire (uneChaine("Entrer une note : "));
	lire (entier);
	moyenne = (moyenne + entier);

	ecrire (uneChaine("Entrer une note : "));
	lire (entier);
	moyenne = (moyenne + entier);

	ecrire (uneChaine("Entrer une note : "));
	lire (entier);
	moyenne = (moyenne + entier);

	ecrire (uneChaine("Entrer une note : "));
	lire (entier);
	moyenne = ((moyenne + entier)/5);

	ecrire (uneChaine("La moyenne de l'élève est de "));
	ecrireNL (moyenne);
}
------------------------------------------
TP : Perimetre
------------------------------------------
#include "/usr/local/public/BIBLIOC++/entreeSortie.h"
#include "/usr/local/public/BIBLIOC++/chaine.h"

int perimetre (int a, int b);
int surface (int a, int b);

int main ()
{
	int l;        // largeur
	int L;        // Longeur

	ecrire (uneChaine ("Donnez la valeur de la largeur : "));
	lire (l);
	ecrire (uneChaine ("Donnez la valeur de la longueur : "));
	lire (L);
	ecrire (uneChaine ("Le perimetre est de "));
	ecrireNL (perimetre (l,L));
	ecrire (uneChaine ("La surface est de "));
	ecrireNL (surface (l,L));
	return 0 ;
}

int perimetre (int a,int b)
{
	return (a+b)*2;
}

int surface (int a, int b)
{
	return (a*b);
}	
------------------------------------------
TP : script.sh
------------------------------------------
------------------------------------------
TP : somme
------------------------------------------
#include "/usr/local/public/BIBLIOC++/entreeSortie.h"
#include "/usr/local/public/BIBLIOC++/chaine.h"

void calculerSomme (int a, int b, int &resultat)
{
	resultat =  a + b;
}

int main ()
{
	int entier1;
	int entier2;
	int somme = 0;
	ecrire (uneChaine("Ecrire 1 : "));
	lire (entier1);
	ecrire (uneChaine ("Ecrire 2 : "));
	lire (entier2);
	calculerSomme (entier1, entier2, somme);
	ecrire (somme);

	return 0;
}
------------------------------------------
TP : Tableau_ex1
------------------------------------------
#include "/usr/local/public/BIBLIOC++/entreeSortie.h"
#include "/usr/local/public/BIBLIOC++/chaine.h"

/********* ENREGISTREMENT DE TYPE DATE *********/
struct Date 
{
	int jour;
	int mois;
	int annee;
};

Chaine  mois[12] = { "Janvier", "Fevrier", "Mars", "Avril", "Mai", "Juin", "Juillet" , "Aout" , "Septembre" , "Octobre" , "Novembre" , "Decembre" };

/********* PROCEDURE DE SAISIE D'UNE DATE *********/
 void saisirDate (Date &date1)
{
	ecrire(uneChaine("Veuillez saisir un jour[1-31] "));
	lire (date1.jour);
	ecrire(uneChaine("Veuillez saisir un mois[1-12] "));
	lire (date1.mois);
	ecrire(uneChaine("Veuillez saisir une année[AAAA] "));
	lire (date1.annee);
}


/********* AFFICHAGE D'UNE DATE *********/
 void afficherDate (Date &date1)
{
	ecrire(date1.jour);
	ecrire(uneChaine(" ")) ;
	ecrire(mois[date1.mois-1]);
	ecrire(uneChaine(" ")) ;
	ecrireNL(date1.annee);
}


/********* PROGRAMME *********/
int main (void)
{
	Date date;

	saisirDate (date);
	afficherDate (date);
	
	return 0 ;
}

------------------------------------------
TP : TP1
------------------------------------------
#include "/usr/local/public/BIBLIOC++/entreeSortie.h"
#include "/usr/local/public/BIBLIOC++/chaine.h"

// Ce programme ne sert à rien !

int main (void)
{
    int v ;
    int r ;

    ecrire (uneChaine ("entrer une valeur entiere : ")) ;
    lire (v) ;
    r = 1 ;

    while (v > 1)
    {
        r*=(v--) ;
    }

    ecrireNL (r);

}

#include "/usr/local/public/BIBLIOC++/entreeSortie.h"
#include "/usr/local/public/BIBLIOC++/chaine.h"

int fonction (const int n) ;
int main ()
{
    int n ;
    int f ;
    ecrire (uneChaine ("entrer une valeur entiere : ")) ;
    lire (n) ;
    f = fonction (n) ;
    ecrireNL (f) ;
}
int fonction (const int n)
{
    int v ;
    int r ;
    v = n ;
    r = 1 ;
    while (v > 1)
    {
        r = r*v ;
        v = v-1 ;
    }
    return (r) ;
}

#include "/usr/local/public/BIBLIOC++/entreeSortie.h"
#include "/usr/local/public/BIBLIOC++/chaine.h"
int main ()
{
  try
  {
    Chaine ch ;
    ecrire (uneChaine ("entrer une chaine : ")) ;
    lire (ch) ;
    ecrireNL (ieme (ch, 6)) ;
  }
  catch (const Chaine message)
  {
  ecrireNL (message);
  }
}

int main ()
{
    int a, b ;
    a = 1024 ;
    b = a*a*a-1 ;
    a = 2*b ;
    b = a+1 ;
    a = b+1 ;
    b = 4*b ;
    a = 2*a ;
    b = b/a ;
}

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
	
]	
