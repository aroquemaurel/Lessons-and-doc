public abstract class Valeur {
	public abstract String toString();
	public abstract boolean egale(Valeur valeur);
}

public class Nombre extends Valeur {
	private int nombre;
	public Nombre(int nombre) {
		this.nombre = nombre;
	}

	public int getNombre() {
		return nombre;
	}

	public String toString() {
		return "" + nombre;
	}

	public boolean egale(Valeur valeur) {
		return ((Nombre)valeur).getNombre() == nombre;
	}
}

public enum Image { ROI, DAME, VALET, AS };

public class Figure extends Valeur {
	private Image image;
	private String nom;

	public Figure(Image image) {
		this.image = image;
		this.nom = (image.toString().toLowerCase();
	}

	public Image getImage() {
		return image;
	}
	public String toString() {
		return nom;
	}

	public boolean egale(Valeur valeur) {
		return ((Figure)valeur).getImage() == image;
}

public Carte extends Pair<Valeur,Couleur> {
	public Carte(Valeur valeur, Couleur couleur) {
		super(valeur, couleur);
	}
}

abstract public class Genre {
	private List<Valeur> liste;

	public Genre(List pValeurs) {
		valeurs = pValeurs;
	}

	private int positionCarte(Valeur val) {
		int pos = 0;
		for(Valeur v : liste) {
			if(val.equals(v)) {
				break;
			}
			++pos;
		}

		return pos;
	}
}

public class HorsAtout extends Genre {
	public Atout(List l) {
		super(Arrays.asList(
					new Figure(Image.AS), new Nombre(10), new Figure(Image.ROI), new Figure(Image.VALET), new Figure(Image.DAME), 
					new Nombre(9), new Nombre(8), new Nombre (7)
					);
	}
}

public class Atout extends Genre {
	public HorsAtout() {
		super(Arrays.asList(
					new Figure(Image.VALET), new Nombre(9), new Figure(Image.AS), new Nombre(10), new Figure(Image.ROI), 
					new Figure(Image.DAME), new Nombre(8), new Nombre (7)
					);
	}
}

public class Jeu {
	private Couleur atout;
	private int calculGagnant(Carte c1, Carte c2) {

	}

	public int levee(Couleur atout, Pair<Carte,Carte> equipeMain, Paire<Carte,Carte< equipe) {
		this.atout = atout;
		int numVainqueurEquipeMain = calculGagnant(equipeMain.getFirst(), equipeMain.getSecond());
		Carte joueurEquipeMain;
		// TODO
	}
	static class ClassInterne<G extends Genre> {
		G genre;

		public classInterne(G genre) {
			this.genre = genre;
		}
	}
}

public class Test {
	public static void main(String[]s) {
		Carte asCarreau = new Carte(new Figure(Image.AS, Couleur.CARREAU));
		Carte roiPiqe = new Carte(new Figure(Image.ROI, Couleur.PIQUE));
	}
}
