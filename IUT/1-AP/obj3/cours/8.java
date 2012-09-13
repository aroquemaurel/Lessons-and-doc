class ChaineHifi
{
	private Tuner t;
	private LecteurCD l;
	private Tableau <Enceinte> e;

	// Constructeur
	public ChaineHifi (int nb) {
		t = new Tuner();
		l = new LecteurCD();
		e = new Tableau<Enceinte> (nb);
	}
}

interface Tableau <T>
{
	Tableau <T>(int n);
	int longueur();
	T getIeme (int i);
	void setIeme(int i, T x);

}
