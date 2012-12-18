public void endormirAnimaux(Ensemble <Animal> p_leZoo){
	// déclancher un objet Iterateur
	Iterateur <Animal> visite = new Iterateur <Animal>(p_leZoo);
	// parcours séquentiel de l'ensemble leZoo
	// et endormissement de chacun des animaux
	
	for(visite.premier() ; visite.termine() ; visite.suivant()) {
		visite.valeur().dormir();
	}
}
