class EauGazeuse extends Article
{
	// Constructeur de la classe EauGazeuse
	public EauGazeuse (String d, float p){
		super(d,p);
	}
	// redéfinition du calcul du prix de vente de la classe Article
	// TVA = 5.5%
	public float prixDeVente() {
		return(getPrixHT() * 1.055);
	}
}

