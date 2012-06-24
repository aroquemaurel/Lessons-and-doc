package stratego;

/**
 * classe permettant la création et la manipulation d'une piece immobile du jeu
 * de stratego.
 */
class PieceImmobile extends Piece {
    /**
     * construit une piece immobile
     * 
     * @param p_nom
     *            Nom de la piece
     * @param p_grade
     *            Grade de la piece
     * @param p_couleur
     *            Couleur de la piece
     **/
    public PieceImmobile(String p_nom, int p_grade, Couleur p_couleur) {
    	super(p_nom, p_grade, p_couleur);
    }

}
