package stratego;

/**
 * classe permettant la creation et la manipulation d'une bombe du jeu de
 * stratego.
 */
class Bombe extends PieceImmobile {
    /**
     * construit une bombe
     * 
     * @param p_couleur
     *            Couleur de la piece
     */
    public Bombe(Couleur p_couleur) {
    	super("bombe", 11, p_couleur);
    }

    /**
     * convertit une bombe en chaine de caracteres
     * 
     * @return version unicode d'une bombe
     */
    public String toString() {
        return(new String(" " + this.getCouleur().toString().substring(0, 1) + "* "));
    }
}