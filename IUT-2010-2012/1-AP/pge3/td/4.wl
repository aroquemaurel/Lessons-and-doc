PROCEDURE generationHeureDepart

	// génération des numéros de dossard
	numDossard est un entier = 1
	HlitDernier(coureur_course, points)

	TANTQUE pas Hendehors(coureur_course)
		coureur_course.numDossard = numDossard
		HModifie(coureur_course)
		numDossard++
		HlitPrecedent(coureur_course)
	FIN 	

	//génération des heures de départ
	heureDepartCoureur est une Heure
	HlitPremier(course, date)
	heureDepartCourse = course.HeureDepart
	HlitPremier(coureur_course, points)

	TANTQUE pas Hendehors(coureur_course) 
		coureur_course.heuredepart = heureDepartCourse
		HModifie(coureur_course)
		HlitSuivant(coureur_course, points)

		heureDepartCoureur = EntierVersHeure(HeureVersEntier(heureDepartCoureur)+HeureVersEntier( ))

