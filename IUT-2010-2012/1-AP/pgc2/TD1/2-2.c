void rechercherSousTableau (const PtrEntier adeb, const PtrEntier afin, const int ele, Booleen * trouve,PtrEntier * arang)
{
	Booleen fini ;
	PtrEntier acour ;

	acour = adeb ;
	fini = FAUX ;

	while (! fini)
	{
		if (acour <= afin)
		{
			if (ele == * acour)
			{
				*trouve = VRAI ;
				*arang = acour ;
				fini = VRAI ;
			}
			else
			{
				acour++ ;
			}
		}
		else
		{
			*trouve = FAUX ;
			fini = VRAI ;
		}
	}
}

