package stratego;

/**
 * Classe permettant la creation et la manipulation d'un drapeau du jeu de
 * stratego.
 */
class Drapeau extends PieceImmobile {
    /**
     * construit un drapeau
     * 
     * @param p_couleur
     *            Couleur de la piece
     */
    public Drapeau(Couleur p_couleur) {
    	super("drapeau", 0, p_couleur);
    }

    /**
     * convertit un drapeau en chaine de caracteres
     * 
     * @return version unicode d'un drapeau
     */
    public String toString() {
        return(new String(" " + this.getCouleur().toString().substring(0, 1) + "D "));
    }
}