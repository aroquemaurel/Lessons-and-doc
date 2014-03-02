public class Video extends Comparable<Video> {
	private int annee;
	private String realiateur;
	private String titre;

	public Video(String ptitre, String prealisateur, int pannee) {
		annee = pannee;
		realiateur = prealisateur;
		titre = ptitre;
	}

	public String getTitre() {
		return titre;
	}

	public int getAnnee() {
		return annee;
	}

	public String getRealisateur() {
		return realiateur;
	}

	public String toString() {
		return titre.toString() + " " + 
			realiateur.toString() + " "+annee.toString();
	}

	public int compareTo(Video v) {
		int compairaison = titre.compareTo(v.getTitre());

		if(compairaison != 0) {
			return compairaison;
		}
		compairaison = realiateur.compareTo(v.getRealisateur());

		if(compairaison != 0) {
			return compairaison;
		}

		return (new Integer(annee)).compareTo(new Integer(v.getAnnee()));
	}

	public boolean equals(Object o) {
		if(!o instanceof Video) {
			return false;
		}

		Video v = (Video)o;
		return (titre.equals(v.getTitre()) && 
				realiateur.equals(v.getRealisateur) &&
				annee.equals(o.getAnnee());
	}


}
