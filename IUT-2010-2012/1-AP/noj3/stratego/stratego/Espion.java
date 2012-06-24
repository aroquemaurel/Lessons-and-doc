package stratego;

/**
 * classe permettant la creation et la manipulation d'un espion du jeu de
 * stratego.
 */
class Espion extends PieceMobile {
    /**
     * construit un espion
     * 
     * @param p_couleur
     *            Couleur de la piece
     */
    public Espion(Couleur p_couleur) {
    	super("espion", 1, p_couleur);
    }

    /**
     * renvoie le resultat de l'attaque d'un espion
     * 
     * @param p_piece
     *            Piece attaquee par la piece
     * @return REUSSIE si la piece mobile a gagne l'attaque, NULLE si les deux
     *         pieces se neutralisent ou PERDUE si la piece mobile a perdu
     *         l'attaque
     */
    public Attaque resultatAttaque(Piece p_piece) {
    	Attaque resultatAttaque;
    	if (p_piece.getGrade() == 10) {
    		resultatAttaque = Attaque.REUSSIE;
    	} else if (p_piece.getGrade() == super.getGrade()) {
    		resultatAttaque = Attaque.NULLE;
    	} else {
    		resultatAttaque = Attaque.PERDUE;
    	}
    	return resultatAttaque;
    }
}
