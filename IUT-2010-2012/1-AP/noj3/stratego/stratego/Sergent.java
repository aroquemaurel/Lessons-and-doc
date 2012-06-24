package stratego;

/**
 * classe permettant la creation et la manipulation d'un sergent du jeu de
 * stratego.
 */
class Sergent extends PieceMobile {
    /**
     * construit un sergent
     * 
     * @param p_couleur
     *            Couleur de la piece
     **/
    public Sergent(Couleur p_couleur) {
    	super("sergent", 4, p_couleur);
    }
}