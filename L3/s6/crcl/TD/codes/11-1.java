public int hashcode() {
	return titre.hashcode() * annee * realisateur.hashcode();
}


public boolean equals(Objct o) {
	if(o instanceof Video) {
		Video videoToCmpare = (Video) o;
		return (titre.equals(videoToCmpare.getTitre()) && 
					realisateur.equals(videoToCompare.getRealisateur()) &&
					annee == videoToCmpare.annee);
	} else {
		return false
	}
}

