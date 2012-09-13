#include <stdio.h>
#include <stdlib.h>

void afficherMenu(void);
void saisirChoix(int *n);
void t1(void);
void t2(void);
void t3(void);

int main(void)
{
	int choix;
	afficherMenu();
	saisirChoix(&choix);
	while(choix != 9) //on veut quitter
	{
		switch(choix)
		{
			case 1:
				t1();
			break;
			case 2:
				t2();	
			break;
			case 3:
				t3();	
			break;
			case 9:
				printf("Ciao tutti!!\n");
			break;
			default;
				printf("Essaie encore \n");
		}
		afficherMenu();
		saisirChoix(&choix);
	}
	
}

void afficherMenu(void)
{


}

void saisirChoix(int *n)
{


}

void t1(void)
{

}

void t2(void)
{

}

void t3(void)
{

}
