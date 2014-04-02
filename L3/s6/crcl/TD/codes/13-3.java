public class Membre extends Personne {
	private Map<Jeu, Integer> _jeux;

	public Membre(String firstname, String lastname) {
		super(firstname, lastname);
		_jeux = new HashMap<Jeu, Integer>();
	}
	
	public void ajouterJeu(final Jeu jeu) {
		_jeux.put(jeu, (_jeux.get(jeu) != null ? _jeux.get(jeu)+1 : 1));
	}

	public void supprimerJeu(final Jeu jeu) {
		if(_jeux.get(jeu) > 1) {
			_jeux.put(jeu, (_jeux.get(jeu))-1);
		} else {
			_jeux.remove(jeu);
		}
	}

	public void possedeJeu(final Jeu jeu) {
		return _jeux.get(jeu) != null;
	}

	public Jeu chercherJeu(final String nom) {
		Jeu ret = new Jeu(nom);
		boolean found = false;
		if(!possedeJeu(ret)) {
			return null;
		}

		Jeu j;
		for(Iterator it = _jeux.keySet().iterator() ; it.hasNext() && !found ; 
				j = ((Jeu)it.next())) {
			if(j.equals(ret)) {
				ret = j;
				found = true;
			}
		}

		return (found) ? ret : null;
	}

	public Set<Jeux> getJeux() {
		return _jeux.keySet();
	}

}
