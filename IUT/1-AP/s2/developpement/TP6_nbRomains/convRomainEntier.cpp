/*
  ________________________________________________ 
 |
 |     Programme: TP5 nombres romains 
 |     Langage: C++
 |     Auteur: Antoine de Roquemaurel & Fabrice Valleix
 |
 |     Fichier: convRomainEntier.cpp
 |     Date de modification: 21/05/11
 |
 |________________________________________________
*/

#include <iostream>
#include "convRomainEntier.h"

int convertirRomainEntier(const std::string romain){ 
	int entier = 0;

	for(int i=0; i < romain.size(); i++){
		if(valeur(romain[i]) >= valeur(romain[i+1]))
			entier += valeur(romain[i]);
		else
			entier -= valeur(romain[i]);
	}
	return entier;
}

int valeur(const char romain) {
	switch ( romain ) {
		case 'I' :
			return I;
			break;
		case 'V' :
			return V;
			break;
		case 'X':
			return X;
			break;
		case 'M':
			return M;
			break;
		case 'C':
			return C;
			break;
		case 'L':
			return L;
			break;
		case 'D':
			return D;
			break;
	}
}
void except_nbRepet(const std::string nbRomain, 
		bool &moins3M, bool &moins3C, bool &moins3X, bool &moins3I, 
		int &nbD, int &nbL, int &nbV) {
	int nbX=0, nbM=0, nbC=0, nbI=0;
	moins3X = true; moins3M = true; moins3C = true; moins3I = true;
	nbD=0; nbL=0; nbV=0;
	for(int i = 0; i <= nbRomain.size(); i++)
	{
		switch(nbRomain[i]) {
			case 'X':
				nbX++; nbM = 0; nbC = 0; nbI = 0;
				break;
			case 'M':
				nbX = 0; nbM++; nbC = 0; nbI = 0;
				break;
			case 'C':
				nbX = 0; nbM = 0; nbC++; nbI=0;
				break;
			case 'I':
				nbX = 0; nbM = 0; nbC = 0; nbI++ ;
				break;
			case 'D':
				nbD++;
				break;
			case 'L':
				nbL++;
				break;
			case 'V':
				nbV++;
				break;
			default:
				nbX = 0; nbM = 0; nbC = 0; nbI = 0 ;
		}
		if(nbX > 3)
			moins3X = false;
		if(nbM > 3)
			moins3M = false;
		if(nbC > 3)
			moins3C = false;
		if(nbI > 3)
			moins3I = false;
	}
}

void except_prefix(const std::string nbRomain, 
		const char prefix, const char suffix1, const char suffix2, 
		const int valMaxApres, bool &suffix1Ok, bool &suffix2Ok, 
		bool &valApresSuf1, bool &valApresSuf2) {
	int nbPrefix=0, nbSuffix1=0, nbSuffix2=0;
	suffix1Ok=true; suffix2Ok=true; valApresSuf1=true; valApresSuf2=true;
	int pref=0;
	/* on parcrout le nombre romain */
	for(int i = 0; i <= nbRomain.size(); i++){
		/* si c'est un C, on le compte, si c'est un M, on le compte,
		   si il y a eu plusieurs C avant, le M est préfixé de plus de 1 C
		   la variable retournera faux*/
		if(nbRomain[i] == prefix){
			nbPrefix++;
			pref++;
		}
		else if(nbRomain[i] == suffix1){
			nbSuffix1++;
			if(nbPrefix > 1)
				suffix1Ok = false;

			/* si on a trouvé un M, on récupère la sous chaine après le M, 
			   on calcul sa valeure numérique, et on vérifie qu'elle ne dépasse 
			   pas 99*/
			if(valMaxApres == 0){
				if(pref > 0 && nbRomain[(nbRomain.size())-1] != suffix1){
					valApresSuf1 = false;
				}
			}
			else if(convertirRomainEntier(nbRomain.substr(i+1, nbRomain.size()))
					>valMaxApres && pref > 0){
				valApresSuf1 = false;
			}
		}
		else if(nbRomain[i] == suffix2){

			if(nbPrefix > 1)
				suffix2Ok= false;

			/* si on a trouvé un C, on récupère la sous chaine après le M, 
			   on calcul sa valeure numérique, et on vérifie qu'elle ne dépasse 
			   pas 99*/
			if(valMaxApres == 0){
				if(pref > 0 && nbRomain[(nbRomain.size())-1] != suffix2){
					valApresSuf2 = false;
				}
			}
			else if(convertirRomainEntier(nbRomain.substr(i+1, nbRomain.size()))
					> valMaxApres 
					&& pref > 0){
				valApresSuf2 = false;
			}
		}
		/* si on a trouvé une exception, ça sert à rien de continuer
		   à parcourir la boucle */
		if(!valApresSuf1 || !valApresSuf2|| !suffix1Ok || !suffix2Ok)
			break;
	}
}
bool except_caracAccept(std::string nbRomain){
	bool caracAcc = true;
	for(int i=0; i<nbRomain.size();i++){
		if(nbRomain[i] != 'I' &&
		   nbRomain[i] != 'V' &&
		   nbRomain[i] != 'X' &&
		   nbRomain[i] != 'L' &&
		   nbRomain[i] != 'C' &&
		   nbRomain[i] != 'M' &&
		   nbRomain[i] != 'D') {
			caracAcc = false;
			break;	
		}
	}
	return caracAcc;
}

void testerNbRomain(std::string nbRomain) {
	int nbD, nbL, nbV;
	bool moins3M, moins3C, moins3X, moins3I;
	bool valApresM, valApresD, valApresC, valApresL, valApresX, valApresV;
	bool cPrefixM, cPrefixD, xPrefixC, xPrefixL, iPrefixX, iPrefixV;
	bool caracAcc;

	except_nbRepet(nbRomain, moins3M, moins3C, moins3X, moins3I, nbD, nbL, nbV);
	except_prefix(nbRomain,'C','M','D',99,
			cPrefixM,cPrefixD,valApresM,valApresD);
	except_prefix(nbRomain,'X','C','L',9,
			xPrefixC,xPrefixL,valApresC,valApresL);
	except_prefix(nbRomain,'I','X','V',0,
			iPrefixX,iPrefixV,valApresX,valApresV);
	
	caracAcc = except_caracAccept(nbRomain);
	/* et on test, test, test, pour gérer ces exceptions qui te plaisent \o/ */
	if(!caracAcc){   throw std::string (
			"Vous avez entré un caractère non accepté\n\n");
	}
	if(!moins3M)    throw std::string ("Il faut au plus 3 M consécutifs\n\n");
	if(!moins3C)    throw std::string ("Il faut au plus 3 C consécutifs\n\n");
	if(!moins3X)    throw std::string ("Il faut au plus 3 X consécutifs\n\n");
	if(!moins3I)    throw std::string ("Il faut au plus 3 I consécutifs\n\n");
	if(nbD > 1)     throw std::string ("Il faut au plus un D\n\n");
	if(nbL > 1)     throw std::string ("Il faut au plus un L\n\n");
	if(nbV > 1)     throw std::string ("Il faut au plus un V\n\n");

	if(!cPrefixM)   throw std::string ("Un seul C peut préfixer un M\n\n");
	if(!cPrefixD)   throw std::string ("Un seul C peut préfixer un D\n\n");
	if(!valApresM){ throw std::string (
			"Les chiffres après M ne doivent pas être supérieurs 99\n\n");
	}
	if(!valApresD){ throw std::string (
			"Les chiffres après D ne doivent pas être supérieurs 99\n\n");
	}
	if(!xPrefixC)   throw std::string ("Un seul X peut préfixer un C\n\n");
	if(!xPrefixL)   throw std::string ("Un seul X peut préfixer un L\n\n");
	if(!valApresC){ throw std::string (
			"Les chiffres après C ne doivent pas être supérieurs 9\n\n");
	}
	if(!valApresL){ throw std::string (
			"Les chiffres après L ne doivent pas être supérieurs 9\n\n");
	}

	if(!iPrefixX)   throw std::string ("Un seul I peut préfixer un X\n\n");
	if(!valApresX){ throw std::string (
			"Le suffix de I(X) doit être en fin de nombre \n\n");
	}
	if(!iPrefixV)   throw std::string ("Un seul I peut préfixer un V\n");
	if(!valApresV){ throw std::string (
			"Le suffix de I(V) doit être en fin de nombre \n\n");
	}
}

