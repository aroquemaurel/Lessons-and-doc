package stratego;

/**
 * classe permettant la creation et la manipulation d'un general du jeu de
 * stratego.
 */
class General extends PieceMobile {
    /**
     * construit un general
     * 
     * @param p_couleur
     *            Couleur de la piece
     */
    public General(Couleur p_couleur) {
    	super("general", 9, p_couleur);
    }
}
