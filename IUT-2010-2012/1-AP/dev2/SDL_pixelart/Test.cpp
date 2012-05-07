#include "BaseSDL.h"

ecran ec;
/*tracé d'un triangle à l'ordonnée placeSapinY (10px)*/
void tracerTriangle(ecran ec, int positionX, int &positionY, int &hauteur, int largeur, char couleur)
{
	int longueurTraitCourant = 0;
	int curseurTraitY = 0;
	int x;
	longueurTraitCourant = largeur;
	curseurTraitY = positionY; //on place le curseur a l'emplacement du haut du triangle

	for (int i = largeur; i <= hauteur; i++)//on trace tous les traits
	{
		x = (hauteur - longueurTraitCourant) / 2;
		for(int j = 0; j < longueurTraitCourant; j++) //on trace le trait courant
		{
			afficherPixel(ec, positionX+x+j, curseurTraitY, 'V');
		}

	/* Trait suivant + long et + bas */
		longueurTraitCourant++; 
		curseurTraitY++;
	}
	positionY= positionY+ (hauteur-largeur);

}
void tracerRectangle(ecran ec, int positionX, int &positionY, int hauteur, int largeur, char couleur)
{
	for(int i= 0; i <= hauteur; i++)
	{
		for(int j=0; j <= largeur; j++)
		{
			afficherPixel(ec, positionX+j, positionY+i, 'J');
		}
	}

}
int main(int argc, char** argv)
{
	int vl1,vl2,vl3,vl4,vl5,vl6,vl7,vl8,vl9,vl10,vl12,vl13 ;
	int vl14,vl15,vl16,vl17,vl18,vl25;
	int vl28,vl29,vl30,vl31,vl32,vl33,vl34,vl35,vl36,vl37,vl38,vl39 ;

	int placeSapinY = 0;
	int placeSapinX = 0;
	int largeurTriangle = 0;
	int hauteurTriangle = 0;

	int placeTroncX = 0;
	int hauteurTronc = 0;
	int largeurTronc = 0;

	ec = creerEcran();


		/*######### Premier sapin ######### */
	largeurTriangle= 1;
	placeSapinY= 10;
	hauteurTriangle = 70;	
	for (int i= 0; i< 2; i++) //on parcourt la boucle autant de fois qu'il y a de triangle
	{
		/* On trace un triangle, puis on augmente la largeur du triangle pour le suivant*/	
		tracerTriangle(ec, 550, placeSapinY, hauteurTriangle, largeurTriangle, 'V');
		largeurTriangle = largeurTriangle + 10; 

	}
	/* on positionne le tronc du 1er et on le trace*/
	placeTroncX = 550+(hauteurTriangle-15)/2;
	tracerRectangle(ec, placeTroncX, placeSapinY, 60, 15, 'J');


	
		/*######### Second sapin ######### */
	largeurTriangle = 1;
	placeSapinY = 150; // =)
	hauteurTriangle= 50; // =)
	for (int i= 0; i < 4; i++) 
	{		
		/* On trace un triangle, puis on augmente la largeur du triangle pour le suivant*/	
		tracerTriangle(ec, 450, placeSapinY, hauteurTriangle, largeurTriangle, 'V');
		largeurTriangle = largeurTriangle + 10; 
	}
	/* on positionne le tron du 2nd et on le trace */
	placeTroncX = 450+(hauteurTriangle-20)/2;
	tracerRectangle(ec, placeTroncX, placeSapinY, 50, 20, 'J');


	vl10 = 0;
	vl39 = 1;
	vl31 = 350;	
	for (vl32 = 0; vl32 < 3; vl32++)
	{		
		vl33 = 0;
		vl34 = vl39;
		vl35 = vl31;
		for (vl36=vl39; vl36<=20; vl36++)
		{
			vl33 = (20-vl34) / 2;				vl37 = 0;
			while (vl37 <vl34)
			{
				afficherPixel(ec, 100+vl33+vl37, vl35, 'V');
				vl37=vl37+1 ;
			}
			vl34 += 1;
			vl35++;
		}
		vl31 += (20-vl39);
		vl39 += 10;
	}
	vl38 = 100+(20-5)/2;
	vl30=0;
	while (vl30 < 15)
	{
		vl37=0 ;
		while (vl37 < 5)		
		{
			afficherPixel(ec, vl38+vl37, vl31+vl30, 'J');
			vl37=vl37+1 ;
		}
		vl30=vl30+1 ;
	}
	vl12 = 0;	vl13 = 200;
	vl14 = 250;

	for (vl15=200; vl15<=300; vl15++)
	{
		vl12 = (300-vl13) / 2;
		vl7 = 0;
		while (vl7 <vl13)
		{
			afficherPixel(ec, 150+vl12+vl7, vl14, 'B');
			vl7=vl7+1 ;
		}
		vl13 += 1;
		vl14++;
	}
	vl1=0;
	for (vl1 = 0; vl1 < 200; vl1++)
	{
		vl2 = 0;
		for (vl2 = 0; vl2<300; vl2++)
		{
			afficherPixel(ec, 150+vl2, 350+vl1, 'R');
		}
	}
	actualiser(ec);
	attendre();
	return EXIT_SUCCESS;
}



