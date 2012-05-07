public class Activite {
	private Map<String, Binome> binome;
	private String nomActivite;

	public Activite(){
		this.binome = new Hastable<String, Binome> ();
		this.nomActivite = n;
		this.addBinomes(p_binome);
		// ...
	}

	public void addBinomes(Binome p_binome) throws Exception; {
		Binome aux;

		if(p_binome == NULL){
			throw new Exception ("le paramètre ne peut être null");
		}

		aux = this.binomes.put(p_binome.getNomBinome(), p_binome);

		if(this != p_binome.getActivite(this.nomActivite)){
			p_binome.addActivite(this);
		}
			
	
	}

	public Binome getBinome(String p_nomBinome){
		return this.binomes.get(p_nomBinome)
	}

	public String getNomActivite(){
		return this.nomActivite;
	}
}

