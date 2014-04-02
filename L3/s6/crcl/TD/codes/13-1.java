public class Jeu {
	private String _name;

	public Jeu(String name) {
		_name  = name;
	}

	@Override
	public boolean equals(Object o) {
		return o instanceof Jeu && ((Jeu)o.getName()).equals(_name);
	}

	@Override
	public int hashCode() {
		return _name.hashCode();
	}
}
