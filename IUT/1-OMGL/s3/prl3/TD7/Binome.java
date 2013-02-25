public class Binome {
	private Map<String, Activite> activites;
	private String nomBinome;

	public Binome(EspaceDeTravail p_espaceDeTravail){
		this.setEspaceDeTravail(p_espaceDeTravail);
	}

	public void setEspaceDeTravail(EspaceDeTravail p_espaceDeTravail){
		this.repertoire = p_espaceDeTravail;
	}

	public String getNomBinome(){
		return nomBinome;
	}

	public addActivites(Activite p_activite) throws Exception{
		Activite aux;
		if(p_activite == null){
			throw new Exception("Le paramètre ne peut être null");
		}
		aux = this.activite.put(p_activite.getNumActivite() p_activite);
		if(this != p_activite.getBinome(this.nomBinome)){
			a.addActivites(this);
		}
	}

	public Activite getActivites(String nomActivite){
		return this.activites.get(nomActivite);
	}

	public String getNomBinome(){
		return this.nomBinome;
	}
}
