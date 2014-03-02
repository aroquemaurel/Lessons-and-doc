final int CONTENANCE_INITIAL = 10;

Comparator<TacheAvecPriorite> cmpPriorite = new Comparator<TacheAvecPriorite>() {
	public int compare(TacheAvecPriorite tache1, 
					  TacheAvecPriorite tache2) {
		return tache1.getPriorite().compareTo(tache2.getPriorite());
	}
};

Queue<TacheAvecPriorite> fileAvecPriorite = new PriorityQueue(TacheAvecPriorite>(CONTENANCE_INITIAL, cmpPriorite);
