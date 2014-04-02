public class LudotqueDistribuee {
	private List<Membre> _membres;

	public LudothequeDistribuee() {
		_membres = new ArrayList<Membre>();
	}
	public Membre ajouterMembre(String prenom, String nom) {
		Membre ret = new Membre(prenom, nom);
		_memres.add(ret);	
		
		return ret;
	}

	public boolean retirerMembre(Membre m) {
		return _membres.remove(m); 
	}

	public List<Membre> membresPossedantJeu(Jeu j) {
		List<Membre> ret = new ArrayList<Membre>();

		for(Membre m : _membres) {
			if(m.possedeJeu(j)) {
				ret.add(m);
			}
		}

		return ret;
	}

	public Set<Jeu> listeJeux() {
		Set<Jeu> ret = new HashSet<Jeu>();	
		for(Membre m : _membres) {
			ret.addAll(m.getJeux());
		}

		return ret;
	}

	public double cotisationMembre() {
		double ret;


		return ret;
	}
}
