public class Client {
	private String _name;

	public Client(String name) {
		_name = name;
	}

	public String getNom() {
		return name;
	}

	@Override
	public String toString() {
		return _name;
	}

	public void facturer(Tache t) {
		System.out.println("Le client "+nom" recoit la facture concernant "+
				"la tache "+t);
}
