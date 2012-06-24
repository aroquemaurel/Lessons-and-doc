package stratego;

/**
 * classe permettant la creation et la manipulation d'un capitaine du jeu de
 * stratego
 */
class Capitaine extends PieceMobile {
    /**
     * construit un capitaine
     * 
     * @param p_couleur
     *            Couleur de la piece
     */
    public Capitaine(Couleur p_couleur) {
    	super("capitaine", 6, p_couleur);
    }
}
