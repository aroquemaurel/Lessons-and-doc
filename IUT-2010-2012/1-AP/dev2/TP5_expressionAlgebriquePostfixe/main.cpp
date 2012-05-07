/*
	TP5: Evaluation d'une expressoin postfixée 
	Langage: C++

	Fichier: clientAgenda.cpp
	Rôle: Programme Principal

	Réalisé par: Antoine de Roquemaurel et Fabrice Valleix
	Dernière modification le 29/03/2011 à 15:58
*/


#include <iostream>
#include <string>
#include <stack>
#include <map>

float operation(int ope1, int ope2, char signe);
bool estOperation(char a);

using namespace std;

int main(void)
{
	int nbOperande;
	int valeur;
	char caractere = 'a';
	int depil[2];
	int indice = 0;
	map<char,int> mapExp;
	stack<int> pileExpAlg;
	
	cout << "Combien d'opérande voulez vous fixer?" << endl;
	cin >> nbOperande;

	for(int i = 1; i <= nbOperande; i++) {
		cout << caractere << " = ";
		cin >> valeur;
		mapExp.insert(make_pair(caractere, valeur));
		caractere++; //caractere suivant
	}
	cout << ". pour arreter" << endl;
	cin >> caractere;	
	pileExpAlg.push(mapExp[caractere]);
	while(caractere != '.')
	{
		cin >> caractere;	
		if(!estOperation(caractere))
		{
			pileExpAlg.push(mapExp[caractere]);
		}
		else
		{
			depil[0] = pileExpAlg.top();
			pileExpAlg.pop();
			depil[0] += pileExpAlg.top();
			pileExpAlg.pop();
			pileExpAlg.push(depil[0]);
		}
		// on empile la valeur de l'opérande
		// on empile le résultat
		//	pile.push(operation(depil[0], depil[1], caractere));	
	}
	for(int i = 0; i < nbOperande; i++){
		cout << pileExpAlg.top()<< endl;
		pileExpAlg.pop();//on depile
	}
}
bool estOperation(char a)
{
	return(a == '+' || a == '/' || a == '*' || a == '-');
}
float operation(int ope1, int ope2, char signe)
{
	switch(signe)
	{
		case '+':
			return (ope2 + ope1);
			break;
		case '-':
			return (ope2 - ope1);
			break;
		case '*':
			return (ope2 * ope1);
			break;
		case '/':
			return (ope2 / ope1);
			break;
	}
}

