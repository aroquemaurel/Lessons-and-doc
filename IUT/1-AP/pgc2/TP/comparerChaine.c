/* procedure comparerChaine */

#include "chaine.h"
int comparerChaine(const ChaineDyn ch1, const ChaineDyn ch2)
{

	int lgMin, result, cpt;
	PointeurCar p1;
	PointeurCar p2;
	Bool fini;

	if(ch1.nbCar <= ch2.nbCar)
	{
		lgMin = ch1.nbCar;
	}
	else
	{
		lgMin = ch2.nbCar;
	}
	cpt = lgMin;
	p1 = ch1.ptrCar;
	p2 = ch2.ptrCar;
	fini = FALSE;
	
	while(!fini)
	{
		if(cpt > 0)
		{
			if(*p1 == *p2)
			{
				p1++;
				p2++;
				cpt--;
			}
			else
			{
				fini = TRUE;
			}
		}
		else
		{
			fini = TRUE;
		}
	}
	if(cpt != 0) 
	{
		if(*p1 > *p2)
			result = 1;
		else
			result = -1;
		
	}
	else
	{
		if(ch1.nbCar == ch2.nbCar)
			result = 0;
		else
		{
			if(ch1.nbCar > ch2.nbCar)
				result = 1;
			else
				result = -1;
		}
	}
	return(result);	
}	
