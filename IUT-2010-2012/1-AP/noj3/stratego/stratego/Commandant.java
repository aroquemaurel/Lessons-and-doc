package stratego;

/**
 * classe permettant la creation et la manipulation d'un commandant du jeu de
 * stratego.
 */
class Commandant extends PieceMobile {
    /**
     * construit un commandant
     * 
     * @param p_couleur
     *            Couleur de la piece
     */
    public Commandant(Couleur p_couleur) {
    	super("commandant", 7, p_couleur);
    }
}