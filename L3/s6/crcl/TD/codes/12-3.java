public abstract class Tache {
	@Override
	public boolean equals(Object o) {
		if(o instanceof Tache) {
			return toString().equals(o.toString());
		} else {
			return false;
		}
	}

	@Override
	public int hashCode() {
		return toString().hashCode();
	}

	@Override
	public String toString();
}
