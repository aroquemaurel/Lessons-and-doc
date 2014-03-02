public abstract class Tache implements Comparable<Tache> {
	public abstract toString();
	public boolean equals(Object objetAComparer) {
		if(objetAComparer instanceof Tache) {
			Tache tacheAComparer = (Tache)objetAComparer;
			return toString().equals(tacheAComparer.toString());
		} else {
			return false;
		}
	}

	public int compareTo(Tache tacheAComparer) {
		return toString().compareTo(tacheAComparer.toString());
	}
}
