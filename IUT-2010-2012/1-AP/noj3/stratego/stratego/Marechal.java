package stratego;

/**
 * classe permettant la creation et la manipulation d'un marechal du jeu de
 * stratego.
 */
class Marechal extends PieceMobile {
    /**
     * constuit un marechal
     * 
     * @param p_couleur
     *            Couleur de la piece
     */
    public Marechal(Couleur p_couleur) {
    	super("maréchal", 10, p_couleur);
    }
}