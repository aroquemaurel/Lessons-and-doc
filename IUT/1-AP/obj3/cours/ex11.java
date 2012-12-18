class ProduitLaitier
{
	private Conditionnement emballage;

	public ProduitLaitier(Conditionnement c) {
		this.emballage = c;
	}

	public void condtionner (){
		this.emballage condtionner(this);
	}

	// autre méthodes
}	

class Conditionnement
{
	public void conditionner (ProduitLaitier p){
		//...
	}

	// autre méthodes

}

