class Chemise extends Article
{
	private int taille;
	private Couleur coloris;

	//constructeur de la classe Chemise
	public Chemise (String d, float p, int t, Couleur c){
		super (d, p);
		taille = t;
		coloris = c;
	}
}

