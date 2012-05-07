/*
|________________________________________________________________
|				TP2 Comment realiser un beau dessin !!							
|________________________________________________________________
|	dev2 - Developpement en C++													
|	Realise par Fabrice Valleix et Antoine de Roquemaurel (groupe 1F)							
|																				
|	Dessine pixel par pixel une maison et des sapins grace a la librairie SDL	
|________________________________________________________________*/

#include "BaseSDL.h"

enum Figure {triangle,rectangle,trapeze};


/*
|____________________________________________________________________________________
|								Tracer une figure a l'ecran 
|____________________________________________________________________________________
|
| typeFigure(Figure):	peut prendre triangle, trapeze ou rectangle, 
							si il y a un autre parametre, la procedure ne fera rien
| ec(ecran):			la variable contenant l'endroit ou l'on va dessiner
| positionX	(int):		la position en abscisse de la figure
| positionY(int):		la position en ordonnee de la figure, 
							est en mode mis-a-jour permet de savoir ou sera dessine le tronc si 
							c'est pour un sapin, dans les autres cas, maj inutile
| hauteur(int):			hauteur de la figure
| largeur(int):			largeur de la figure
| couleur(char):		couleur de la figure, peut prendre 
						J(Jaune), N(Noir), R(Rouge), V(Vert) 
						la couleur sera Blanc dans tous les autres cas
|
| Necessite positionX, positionY, hauteur, largeur >= 0
|____________________________________________________________________________________*/
void tracerFigure(Figure typeFigure,//Type de la figure, (triangle, rectangle, trapeze)
				  ecran ec, //variable contenant le lieu ou il faut dessiner 
				  int positionX, //position en abscisse de la figure 
				  int &positionY, //position en ordonnee de la figure 
				  int hauteur, //hauteur de la figure 
				  int largeur, //largeur de la figure 
				  char couleur); //couleur de la figure (Blanc, Vert, Rouge, Jaune, Noir)

/*
|____________________________________________________________________________________
|									Tracer un sapin a l'ecran
|	procedure se servant de la procedure tracerFigure tracer le tronc et les branches 
|____________________________________________________________________________________
| ec(ecran):			La variable contenant l'endroit ou l'on va dessiner
| positionX	(int):		La position en abscisse du sapin
| &positionY(int):		La position en ordonnee du sapin
| hauteurSapin(int):	Hauteur du sapin
| largeurTronc(int):	Largeur du tronc du sapin
| hauteurTronc(int):	Hauteurdu tronc du sapin
| nbBranche(int):		Nombre de branche qu'aura le sapin
|
| Necessite positionY, positionX, largeurTronc, hauteurTronc, hauteurSapin, nbBranche >= 0
|____________________________________________________________________________________*/
void tracerSapin(ecran ec,
				 int positionX, //position en abscisse du sapin 
				 int positionY, //position en ordonnee du sapin 
				 int hauteurSapin, //hauteur du sapin
				 int largeurTronc, //largeur du tronc du sapin
				 int hauteurTronc, //hauteur du tronc du sapin
				 int nbBranche); //nombre de branches du sapin

int main(void)
{
	ecran ec;
	int positionY;

 //on creer la fenêtre on l'on pourra dessiner, la variable est necessaire pour tracerFigure
	ec = creerEcran();

		/* on trace tous les sapins  */
	tracerSapin(ec, 550, 10, 70, 15, 60, 2);
	tracerSapin(ec, 450, 150, 50, 15, 50, 4);
	tracerSapin(ec, 100, 350, 20, 5, 15, 2);
	tracerSapin(ec, 500, 100, 50, 20, 50, 4);
	tracerSapin(ec, 100, 200, 20, 5, 15, 3);
	tracerSapin(ec, 130, 100, 70, 15, 60, 2);


		/* on trace le corps de la maison */
	positionY = 350;
	tracerFigure(rectangle, ec, 150, positionY, 200, 300, 'R');
	positionY = 250;
	tracerFigure(trapeze, ec, 150, positionY, 300, 200, 'B');


		/* on dessine la porte, puis les deux fenetres*/
	positionY = 480;
	tracerFigure(rectangle, ec, 275, positionY, 70, 50, 'J');
	positionY = 400;
	tracerFigure(rectangle, ec, 180, positionY, 50, 50, 'J');
	positionY = 400;
	tracerFigure(rectangle, ec, 370, positionY, 50, 50, 'J');


	actualiser(ec); //actualise l'ecran avec les figures
	attendre(); //attend un evenement
	return EXIT_SUCCESS;
}


/* fonction qui se sert de tracerFigure pour tracer un sapin de nbBranche*/
void tracerSapin(ecran ec, int positionX, int positionY, 
					int hauteurSapin, int largeurTronc, int hauteurTronc, int nbBranche)
{
	int placeTroncX;
	int largeurTriangle = 1;

	for (int i = 0; i < nbBranche; i++) //on parcourt la boucle autant de fois qu'il y a de branches 
	{
		/* On trace un triangle, puis on augmente la largeur du triangle pour le suivant*/	
		tracerFigure(triangle, ec, positionX, positionY, hauteurSapin, largeurTriangle);
		largeurTriangle += 10; 

	}

	/* on positionne le tronc et on le trace*/
	placeTroncX = positionX + (hauteurSapin - largeurTronc) / 2;
	tracerFigure(rectangle, ec, placeTroncX, positionY, hauteurTronc, largeurTronc);
}


/* fonction qui trace une figure, triangle, rectangle ou trapeze*/
void tracerFigure(Figure typeFigure, ecran ec, int positionX, 
					int &positionY, int hauteur, int largeur, char couleur)
{
	int longueurTraitCourant = 0;
	int curseurTraitY = 0;
	int posXTraitCourant;

		/* les triangles et les trapezes se dessinent de la même maniere*/
	if(typeFigure == triangle || typeFigure == trapeze)
	{
		 //si c'est un triangle, cette valeure sera egale a un, pour une pointe, 
		//sinon on commence avec la largeur du trapeze: un trapeze n'est qu'un triangle sans la pointe
		longueurTraitCourant = largeur;
		curseurTraitY = positionY; //on place le curseur a l'emplacement du haut du triangle/trapeze
	
		for (int i= largeur; i<= hauteur; i++)
		{
			posXTraitCourant = (hauteur - longueurTraitCourant) / 2;
			for(int j = 0; j < longueurTraitCourant; j++) //on trace le trait courant
			{
				afficherPixel(ec, positionX+posXTraitCourant+j, curseurTraitY, couleur);
			}

		/* Trait suivant + long et + bas */
			longueurTraitCourant++; 
			curseurTraitY++;
		}
		positionY= positionY+ (hauteur-largeur);
	}	
	else if(typeFigure == rectangle)
	{
		for(int i= 0; i <= hauteur; i++)
		{
			for(int j=0; j <= largeur; j++)
			{
				afficherPixel(ec, positionX+j, positionY+i, couleur);
			}
		}
	}
}

