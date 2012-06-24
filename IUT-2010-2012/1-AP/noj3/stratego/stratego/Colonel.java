package stratego;

/**
 * classe permettant la creation et la manipulation d'un colonel du jeu de
 * stratego.
 */
class Colonel extends PieceMobile {
    /**
     * construit un colonel
     * 
     * @param p_couleur
     *            Couleur de la piece
     */
    public Colonel(Couleur p_couleur) {
    	super("colonel", 8, p_couleur);
    }
}