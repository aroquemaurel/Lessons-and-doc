HLitPremier(course)
si pas HTrouve(course) alors
	gsEtatDeLaCourse = creationCourse
sinon
	si dateVersEntier(dateDuJour())+2 < dateVersEntier(course.date) alors
		gsEtatDeLaCourse = inscription
	sinon
		si dateVersEntier() < course.date alors
			gsEtatDeLaCourse = inscriptionFinie
			generationHeureDepart()
		sinon
			gsEtatDeLaCourse = courseLancee	
		fin
	fin
fin
GDEtatDeLaCourse(gsEtatDeLaCourse)
	
