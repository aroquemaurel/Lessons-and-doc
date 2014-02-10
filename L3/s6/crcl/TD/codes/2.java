public abstract class Tache {
	public abstract String toString();
}

public final class TacheCodage extends Tache {
	private final String spec;
	public TacheCodage(final String spec) {
		this.spec = spec;
	}

	public String getSpec() {
		return spec;
	}

	public String toString() {
		return "Code "+spec;
	}
}

public final class TacheTelephone extends Tache {
	private final String nom;
	private final String numero;

	public TacheTelephone(final String nom, final String numero) {
		this.nom = nom;
		this.numero = numero;
	}

	public String getNom() {
		return nom;
	}
	pulic String getNumero() {
		return numero;
	}

	public String toString() {
		return "Telephone "+nom;
	}
}
