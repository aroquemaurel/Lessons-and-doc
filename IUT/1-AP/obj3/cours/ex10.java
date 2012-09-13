class ChaineHifi extends Article
{
	private float coutGarantie;

	public float prixDeVente() {
		return (super.prixDeVente() + this.coutGarantie());
	}

	//Autres méthodes
}
