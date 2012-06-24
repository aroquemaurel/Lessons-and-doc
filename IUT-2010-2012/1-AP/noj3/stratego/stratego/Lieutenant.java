package stratego;

/**
 * classe permettant la creation et la manipulation d'un lieutenant du jeu de
 * stratego.
 */
class Lieutenant extends PieceMobile {
    /**
     * construit un lieutenant
     * 
     * @param p_couleur
     *            Couleur de la piece
     */
    public Lieutenant(Couleur p_couleur) {
    	super("lieutenant", 5, p_couleur);
    }
}