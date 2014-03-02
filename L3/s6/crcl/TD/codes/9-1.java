public class FileTachesPrioritaires {
	private Queue<TacheAvecPriorite> fileDeTaches;
	private boolean estArrete = false;

	public FileTachesPrioritaires() {
		fileDeTaches = new PriorityQueue<>();
	}

	public boolean ajouterTache(TacheAvecPriorite tache) {
		if(estArrete) {
			return false;
		} else {
			fileDeTaches.offer(tache);
			return true;
		}
	}

	public TacheAvecPriorite obtenirTache() {
		return fileDeTaches.poll();
	}

	public Collection(TacheAvecPriorite> arreter() {
		estArrete  = true;
		retunr fileDeTaches;
	}

	public String toString() {
		String file = "";
		int tailleFile = fileDeTaches.size();
		int i = 1;

		for (TacheAvecPriorite tache : fileDeTaches) {
			file += tache;
			if (i < tailleFile) {
				file += ", ";
			}
			++i;
		}

		return file;
	}
	
}
