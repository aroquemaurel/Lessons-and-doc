class Article
{
	private String designation ;
	private float prixHT;


	public float prixDeVent() {
		return (prixHT * 1.196);
	}

	public float coutLivraison() {
		return(prixHT * 0.05);
	}

	public String getDesignation(){
		return (designation);
	}

	public float getPrixHT(){
		return (prixHT);
	}

	public void setPrixHT (float p){
		prixHT = p;
	}
}
