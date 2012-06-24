package stratego;

/**
 * classe permettant la creation et la manipulation d'une piece du jeu de
 * stratego.
 */
abstract class Piece {
    /**
     * nom de la piece
     */
    private String nom;
    /**
     * couleur de la piece
     */
    private Couleur couleur;
    /**
     * grade de la piece
     **/
    private int grade;
    /**
     * position de la piece sur le plateau
     */
    private Position position;

    /**
     * construit une piece
     * 
     * @param p_nom
     *            Nom de la piece
     * @param p_grade
     *            Grade de la piece
     * @param p_couleur
     *            Couleur de la piece
     */
    public Piece(String p_nom, int p_grade, Couleur p_couleur) {
    	this.nom = p_nom;
    	this.grade = p_grade;
    	this.couleur = p_couleur;
    }

    /**
     * renvoie le grade de la piece
     * 
     * @return le grade de la piece
     */
    public int getGrade() {
    	return(this.grade);
    }

    /**
     * renvoie la position de la piece
     * 
     * @return la position de la piece
     */
    public Position getPosition() {
        return(this.position);
    }

    /**
     * place la piece a une position donnee
     * 
     * @param p_position
     *            endroit ou positionner la piece
     **/
    public void setPosition(Position p_position) {
        this.position = p_position;
    }

    /**
     * renvoie le nom de la piece
     * 
     * @return le nom de la piece
     */
    public String getNom() {
        return(this.nom);
    }

    /**
     * renvoie la couleur de la piece
     * 
     * @return la couleur de la piece
     **/
    public Couleur getCouleur() {
        return(this.couleur);
    }
}