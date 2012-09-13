class Article 
{
	// ...
	
	// Calcule le prix de vente avec livraison d'un article
	public float prixAvecLivraison(){
		return(this.prixDeVente() + this.coutLIvraison());
	}
}

