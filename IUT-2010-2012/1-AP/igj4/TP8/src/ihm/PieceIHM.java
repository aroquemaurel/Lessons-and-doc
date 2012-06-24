package ihm;

@SuppressWarnings("serial")
/**
 * Représente graphiquement une Pièce du jeu Stratego
 * @author vnc0102a
 *
 */
public final class PieceIHM extends javax.swing.ImageIcon {
	private boolean _cachee;
	private String  _couleur;
	private String  _nom;
	
	private static final String REPERTOIRE = "./images/";
	private static final String EXTENSION = ".gif";
	
	/**
	 * construit une piece graphique cachee du jeu de stratego Cette piece est une image produite a
partir d'un fichier .gif contenu dans le repertoire images
	 * @param nom le grade de la pièce ["rouge", "bleu"]
	 * @param couleur la couleur du joueur auquel cette pièce appartiens
	 */
	public PieceIHM(String nom,
					String couleur) {
		super(REPERTOIRE + "pion" + couleur +  EXTENSION);
		
		_nom = nom;
		_couleur = couleur;
		_cachee = true;
	}
	
	/**
	 * construit une piece graphique visible du jeu de stratego Cette piece est une image produite a
partir d'un fichier .gif contenu dans le repertoire images
	 * @param nom le grade de la pièce
	 * @param couleur la couleur du joueur auquel cette pièce appartiens ["rouge", "bleu"]
	 * @param active indique si cette pièce est active (liseré bleu) ["", "actif"]
	 */
	public PieceIHM(String nom,
					String couleur,
					String active) {
		super(REPERTOIRE + nom + couleur + active + EXTENSION);
		
		_nom = nom;
		_couleur = couleur;
		_cachee = false;
	}
	
	public boolean estCachee() {
		return _cachee;
	}
	
	public String getCouleur() {
		return _couleur;
	}
	
	public String getNom() {
		return _nom;
	}
}
