class Perroquet extends Oiseau {
	private Proprietaire proprietaire;

	public Perroquet(String p_nom, int p_age, Proprietaire p_proprietaire){
		super(p_nom, p_age);
		this.proprietaire = p_proprietaire;
	}
	public void parler () {
	}

	public Proprietaire getProprietaire(){
		return (this.proprietaire);
	}

	public void setProprietaire(Proprietaire p_proprietaire){
		this.proprietaire = p_proprietaire;
	}
}

