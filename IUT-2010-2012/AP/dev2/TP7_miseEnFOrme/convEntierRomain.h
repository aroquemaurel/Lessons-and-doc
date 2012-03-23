/*
  ________________________________________________
 |
 |     Programme: TP5 nombres romains 
 |     Langage: C++
 |     Auteur: Antoine de Roquemaurel & Fabrice Valleix
 |
 |     Fichier: convEntierRomain.cpp
 |     Date de modification: 20/05/11
 |
 |________________________________________________
*/

#ifndef __convEntierRomain
#define __convEntierRomain

// tableau 2D servant a la conversation 
const std::string conv[10][4] = {"", "", "", "", 
								"I", "X", "C", "M",
								"II", "XX", "CC", "MM",
								"III", "XXX", "CCC", "MMM",
								"IV", "XL", "CD", "",
								"V", "L", "D", "",
								"VI", "LX", "DC", "",
								"VII", "LXX", "DCC", "",
								"VIII", "LXXX", "DCCC", "",
								"IX", "XC", "CM", ""};

/* *fonction nbChiffreNb retourne int*
   retourner le nombre de chiffre présent dans le nombre
   |nombre entrée (tableau de int) */
int nbChiffreNb(const int nombre[]) ;


/* *fonction extraireChiffre* 
		extraire les différents chiffres d'un nombre
   |nombre entrée (int)
   |chiffre sortie (tableau de int) */
void extraireChiffre(const int nombre, int chiffre[]);


/* *fonction convertirEntierRomain retourne string *
	Convertir un entier en nombre romain
   |entier entrée (int)
   [ Déclenche nombreTropGrand*/
std::string convertirEntierRomain(const int entier) throw (std::string);

/* *fonction testerNombre*
		tester si la chaine est un bien un nombre
   |nombre entrée (string)
   [déclenche chaineNonEntier */
void testerNombre(const std::string nombre) throw (std::string);


/* *conversionStringEntier retourne int*
		convertir une chaine contenant des nombres en un entier
   |chaine entrée (string)*/
int conversionStringEntier(const std::string chaine); 


#endif


