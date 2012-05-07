/*
  ________________________________________________
 |
 |     Programme: TP5 nombres romains 
 |     Langage: C++
 |     Auteur: Antoine de Roquemaurel & Fabrice Valleix
 |
 |     Fichier: convRomainEntier.cpp
 |     Date de modification: 17/05/11
 |
 |________________________________________________
*/

#ifndef __convRomainEntier
#define __convRomainEntier


#define I 1
#define V 5
#define X 10
#define L 50
#define C 100
#define D 500
#define M 1000

/* *fonction convertirRomainEntier retourne int*
	   convertit un nombre romain en nombre entier
   |romain entrée (string) */
int convertirRomainEntier(const std::string romain); 


/* *fonction valeur retourne int*
		retourne la valeur d'un caractère romain
   |romain entrée (char) */
int valeur(const char romain); 


/* *fonction except_nbRepet *
		compte le nombre de répétitions des différents chiffre du nb Romain
   |nbRomain entrée (string) 
   |&moins3M sortie (bool) 
   |&moins3C sortie (bool) 
   |&moins3X sortie (bool) 
   |&moins3I sortie (bool) 
   |&nbD	 sortie (int) 
   |&nbL	 sortie (int) 
   |&nbV	 sortie (int) */
void except_nbRepet(const std::string nbRomain, 
		bool &moins3M, bool &moins3C, bool &moins3X, 
		bool &moins3I, int &nbD, int &nbL, int &nbV);


/* *fonction except_prefix*
		regarde si la règle des préfix est respécté
   |nbRomain entrée (string) 
   |prefix		entrée (char) 
   |suffix1		entrée (char) 
   |suffix2		entrée (char) 
   |valMaxApres	entrée (int) 
   |&prefix1	sortie (bool) 
   |&prefix2	sortie (bool) 
   |&valApresOk sortie (bool) */
void except_prefix(const std::string nbRomain, 
		const char prefix, const char suffix1, const char suffix2, 
		const int valMaxApres, bool &prefix1, bool &prefix2, 
		bool &valApresOk) ;


/* *fonction except_caracAccept*
		regarde si le nombre entré ne contient pas des caractères non prévus
   |nbRomain	entrée (string)*/ 
bool except_caracAccept(std::string nbRomain);

/* *fonction except_prefix*
		regarde si la règle des préfix est respécté
   |nbRomain	entrée (string) 
   [déclenche caractereNonAccepté, plus3Mconsécutifs, plus3Cconsécutifs, 
	[plus3Xconsécutifs, plus3Iconsécutifs, plus1D, plus1L, plus1V
	[plus1CpréfixeunM, plus1DpréfixeunD, chiffresapresM>99, chiffresApresD>99,
	[plus1XpréfixeunC, plusunXpréfixeunL, chiffresApresC>99, 
	[chiffresApresL>99,*/
void except_prefix(const std::string nbRomain, 
		const char prefix, const char suffix1, const char suffix2, 
		const int valMaxApres, bool &suffix1Ok, bool &suffix2Ok, 
		bool &valApresSuf1, bool &valApresSuf2) ;


/* *fonction testerNbRomain*
		test si le nombre romain est correctement agencé
   |nbRomain	entrée (string)*/ 
void testerNbRomain(std::string nbRomain);

#endif
