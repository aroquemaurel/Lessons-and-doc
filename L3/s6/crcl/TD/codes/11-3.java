
public boolean equals(Objct o) {
	if(o instanceof VideoAppreciation) {
		VideoAppreciation videoToCmpare = (VideoAppreciation) o;
		return (titre.equals(videoToCmpare.getVideo().getTitre()) && 
					realisateur.equals(videoToCompare.getVideo().getRealisateur()) &&
					annee == videoToCmpare.getVideo().annee);
	if(o instanceof Video) {
		Video videoToCmpare = (Video) o;
		return (titre.equals(videoToCmpare.getTitre()) && 
					realisateur.equals(videoToCompare.getRealisateur()) &&
					annee == videoToCmpare.annee);
	} else {
		return false
	}
}

