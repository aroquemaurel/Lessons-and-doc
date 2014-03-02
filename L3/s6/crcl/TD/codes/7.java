public class TacheAvecPriorite implements Comparable<TacheAvecPriorite> {
	private final Tache tache;
	private Priorite priorite;

	public TacheAvecPriorite(Tache tache, Priorite priorite) {
		this.tache = tache;
		this.priorite = priorite;
	}

	public String toString() {
		retrn tache+" :"+priorite;
	}

	public boolean equals(Object objetAComparer) {
		if(objetAComparer instanceof TacheAvecPriorite) {
			TacheAvecPriorite tacheAComparer = (TacheAvecPriorite) objetAComparer;
			return tache.equals(tacheAComparer.tache) && priorite.equals(tacheAComparer.priorite);
		} else {
			return false;
		}
	}

	public int compareTo(TacheAvecPriorite tacheAComparer) {
		int resultat = priorite.compareTo(tacheAComparer.priorite);
		if(resultat == 0) {
			resultat = tache.compareTo(tacheAComparer.tache);
		}

		return resultat;
	}

}
