package stratego;

/**
 * classe permettant la creation et la manipulation d'un demineur du jeu de
 * stratego.
 */
class Demineur extends PieceMobile {
    /**
     * Construit un demineur
     * 
     * @param p_couleur
     *            Couleur de la piece
     */
    public Demineur(Couleur p_couleur) {
    	super("demineur", 3, p_couleur);
    }

    /**
     * renvoie le resultat de l'attaque d'un demineur
     * 
     * @param p_piece
     *            Piece attaquee par la piece
     * @return REUSSIE si la piece mobile a gagne l'attaque, NULLE si les deux
     *         pieces se neutralisent ou PERDUE si la piece mobile a perdu
     *         l'attaque
     */
    public Attaque resultatAttaque(Piece p_piece) {
    	Attaque resultatAttaque;
    	if (p_piece.getGrade() == 11) {
    		resultatAttaque = Attaque.REUSSIE;
    	} else {
    		resultatAttaque = super.resultatAttaque(p_piece);
    	}
    	
    	return resultatAttaque;
    }
}