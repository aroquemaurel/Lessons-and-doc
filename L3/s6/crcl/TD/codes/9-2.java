public class OrdonnanceurTaches {
	private final int DUREE_PLANNING_EN_JOUR = 365;

	private List<FileTachesPrioritaires> planning;
	private int jourCourant;

	public OrdonnanceurTaches() {
		jourCourant = 0;
		planning  = new ArrayList<>();
		for(int i = 0 ; i < DUREE_PLANNING_EN_JOUR ; ++i) {
			planning.add(new FileTachesPrioritaires());
		}
	}

	public void ajouterTache(TachesAvecPriorite tache, int jour) {
		if(jour < 0 || jour > DUREE_PLANNING_EN_JOUR) {
			throw new IllegalArgumentException("jour hors planning");
		}

		FileTachesPrioritaires fileTachesDuJour = planning.get(jour);

		if(!fileTachesDuJour.ajouterTache(tache)) {
			throw new IllegalArgumentException("impossible d'ajouter la tache"+tache);
		}
	}

	public TachesAvecPriorite obtenirTache() {
		return planning.get(jourCourant).obtenirTache();
	}

	public void renouveler() {
		Collectino<TachesAvecPriorite> tacheRstantes = planning.get(jourCourant).arreter();
		planning.remove(jourCourant);
		FileTachesPrioritaires premierJour = planning.get(jourCourant);
		for(TachesAvecPriorite tache : tacheRstantes) {
			tache.incrementerPriorite();
			premierJour.ajouterTache(tache);
		}

		FileTachesPrioritaires dernierJour = new FileTachesPrioritaires();
		planning.add(jourCourant, dernierJour);
		jourCourant = (jourCourant+1) % DUREE_PLANNING_EN_JOUR;
}

public ListIterator<FileTachesPrioritaires> obtenirSousPlanning(int premierJour, int dernierJour) {
	return planning.subList(premierJour, dernierJour).listIterator();
}
