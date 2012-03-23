--init fen
HLitPremier(course)
si HTrouve(course) alors
	fichierVersEcran(FEN_FICHEPARCOURS_course)
fin

--clic sur bouton appliquer
si gsEtatDeLaCourse = creationCourse alors
	HAjouté(ourse)
	gsEtatDeLaCourse = inscription ; GDEtatDeLaCourse(gsEtatDeLaCourse)
sinon
	HModifie(course)
fin
Ferme

--clic sur bouton annulé
Ferme
	
