void rechercherOccurrence(const TabEntiers tab, const int n, const int ele, Booleen * trouve, int * rang)
{
	Booleen fini ;
	int i ;

	i = 0 ;
	fini = FAUX ;

	while (! fini)
	{
		if (i < n)
		{
			if (ele == tab[i])
			{
				*trouve = VRAI ;
				*rang = i ;
				fini = VRAI ;
			}
			else
			{
				i++ ;
			}
		}
		else
		{
			* trouve = FAUX ;
			fini = VRAI ;
		}
	}
}

