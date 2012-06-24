package stratego;

/**
 * classe gerant une partie de stratego
 */
public class Stratego {
    /**
     * plateau du jeu de stratego
     */
    private Plateau plateau;

    /**
     * construit une partie de Stratego
     */
    public Stratego() {
        this.plateau = new Plateau();
        this.remplirPlateau();
    }

    /**
     * positionne les pieces sur le plateau
     */
    private void remplirPlateau() {
        try {
			this.plateau.setPiece(new Position(0, 0), new Demineur(Couleur.BLEU));
			this.plateau.setPiece(new Position(0, 1), new Eclaireur(Couleur.BLEU));
			this.plateau.setPiece(new Position(0, 2), new Demineur(Couleur.BLEU));
			this.plateau.setPiece(new Position(0, 3), new Eclaireur(Couleur.BLEU));
			this.plateau.setPiece(new Position(0, 4), new Demineur(Couleur.BLEU));
			this.plateau.setPiece(new Position(0, 5), new Bombe(Couleur.BLEU));
			this.plateau.setPiece(new Position(0, 6), new Drapeau(Couleur.BLEU));
			this.plateau.setPiece(new Position(0, 7), new Bombe(Couleur.BLEU));
			this.plateau.setPiece(new Position(0, 8), new Capitaine(Couleur.BLEU));
			this.plateau.setPiece(new Position(0, 9), new Demineur(Couleur.BLEU));
			this.plateau.setPiece(new Position(1, 0), new Bombe(Couleur.BLEU));
			this.plateau.setPiece(new Position(1, 1), new Colonel(Couleur.BLEU));
			this.plateau.setPiece(new Position(1, 2), new Bombe(Couleur.BLEU));
			this.plateau.setPiece(new Position(1, 3), new Espion(Couleur.BLEU));
			this.plateau.setPiece(new Position(1, 4), new Lieutenant(Couleur.BLEU));
			this.plateau.setPiece(new Position(1, 5), new Sergent(Couleur.BLEU));
			this.plateau.setPiece(new Position(1, 6), new Bombe(Couleur.BLEU));
			this.plateau.setPiece(new Position(1, 7), new Demineur(Couleur.BLEU));
			this.plateau.setPiece(new Position(1, 8), new Colonel(Couleur.BLEU));
			this.plateau.setPiece(new Position(1, 9), new Bombe(Couleur.BLEU));
			this.plateau.setPiece(new Position(2, 0), new Eclaireur(Couleur.BLEU));
			this.plateau.setPiece(new Position(2, 1), new Sergent(Couleur.BLEU));
			this.plateau.setPiece(new Position(2, 2), new Commandant(Couleur.BLEU));
			this.plateau.setPiece(new Position(2, 3), new General(Couleur.BLEU));
			this.plateau.setPiece(new Position(2, 4), new Eclaireur(Couleur.BLEU));
			this.plateau.setPiece(new Position(2, 5), new Sergent(Couleur.BLEU));
			this.plateau.setPiece(new Position(2, 6), new Marechal(Couleur.BLEU));
			this.plateau.setPiece(new Position(2, 7), new Commandant(Couleur.BLEU));
			this.plateau.setPiece(new Position(2, 8), new Lieutenant(Couleur.BLEU));
			this.plateau.setPiece(new Position(2, 9), new Commandant(Couleur.BLEU));
			this.plateau.setPiece(new Position(3, 0), new Sergent(Couleur.BLEU));
			this.plateau.setPiece(new Position(3, 1), new Eclaireur(Couleur.BLEU));
			this.plateau.setPiece(new Position(3, 2), new Eclaireur(Couleur.BLEU));
			this.plateau.setPiece(new Position(3, 3), new Capitaine(Couleur.BLEU));
			this.plateau.setPiece(new Position(3, 4), new Lieutenant(Couleur.BLEU));
			this.plateau.setPiece(new Position(3, 5), new Eclaireur(Couleur.BLEU));
			this.plateau.setPiece(new Position(3, 6), new Capitaine(Couleur.BLEU));
			this.plateau.setPiece(new Position(3, 7), new Sergent(Couleur.BLEU));
			this.plateau.setPiece(new Position(3, 8), new Eclaireur(Couleur.BLEU));
			this.plateau.setPiece(new Position(3, 9), new Lieutenant(Couleur.BLEU));
	
			this.plateau.setPiece(new Position(6, 0), new Lieutenant(Couleur.ROUGE));
			this.plateau.setPiece(new Position(6, 1), new Eclaireur(Couleur.ROUGE));
			this.plateau.setPiece(new Position(6, 2), new Sergent(Couleur.ROUGE));
			this.plateau.setPiece(new Position(6, 3), new Capitaine(Couleur.ROUGE));
			this.plateau.setPiece(new Position(6, 4), new Eclaireur(Couleur.ROUGE));
			this.plateau.setPiece(new Position(6, 5), new Lieutenant(Couleur.ROUGE));
			this.plateau.setPiece(new Position(6, 6), new Capitaine(Couleur.ROUGE));
			this.plateau.setPiece(new Position(6, 7), new Eclaireur(Couleur.ROUGE));
			this.plateau.setPiece(new Position(6, 8), new Eclaireur(Couleur.ROUGE));
			this.plateau.setPiece(new Position(6, 9), new Sergent(Couleur.ROUGE));
			this.plateau.setPiece(new Position(7, 0), new Commandant(Couleur.ROUGE));
			this.plateau.setPiece(new Position(7, 1), new Lieutenant(Couleur.ROUGE));
			this.plateau.setPiece(new Position(7, 2), new Commandant(Couleur.ROUGE));
			this.plateau.setPiece(new Position(7, 3), new Marechal(Couleur.ROUGE));
			this.plateau.setPiece(new Position(7, 4), new Sergent(Couleur.ROUGE));
			this.plateau.setPiece(new Position(7, 5), new Eclaireur(Couleur.ROUGE));
			this.plateau.setPiece(new Position(7, 6), new General(Couleur.ROUGE));
			this.plateau.setPiece(new Position(7, 7), new Commandant(Couleur.ROUGE));
			this.plateau.setPiece(new Position(7, 8), new Sergent(Couleur.ROUGE));
			this.plateau.setPiece(new Position(7, 9), new Eclaireur(Couleur.ROUGE));
			this.plateau.setPiece(new Position(8, 0), new Bombe(Couleur.ROUGE));
			this.plateau.setPiece(new Position(8, 1), new Colonel(Couleur.ROUGE));
			this.plateau.setPiece(new Position(8, 2), new Demineur(Couleur.ROUGE));
			this.plateau.setPiece(new Position(8, 3), new Bombe(Couleur.ROUGE));
			this.plateau.setPiece(new Position(8, 4), new Lieutenant(Couleur.ROUGE));
			this.plateau.setPiece(new Position(8, 5), new Capitaine(Couleur.ROUGE));
			this.plateau.setPiece(new Position(8, 6), new Espion(Couleur.ROUGE));
			this.plateau.setPiece(new Position(8, 7), new Bombe(Couleur.ROUGE));
			this.plateau.setPiece(new Position(8, 8), new Colonel(Couleur.ROUGE));
			this.plateau.setPiece(new Position(8, 9), new Bombe(Couleur.ROUGE));
			this.plateau.setPiece(new Position(9, 0), new Demineur(Couleur.ROUGE));
			this.plateau.setPiece(new Position(9, 1), new Capitaine(Couleur.ROUGE));
			this.plateau.setPiece(new Position(9, 2), new Bombe(Couleur.ROUGE));
			this.plateau.setPiece(new Position(9, 3), new Capitaine(Couleur.ROUGE));
			this.plateau.setPiece(new Position(9, 4), new Bombe(Couleur.ROUGE));
			this.plateau.setPiece(new Position(9, 5), new Demineur(Couleur.ROUGE));
			this.plateau.setPiece(new Position(9, 6), new Eclaireur(Couleur.ROUGE));
			this.plateau.setPiece(new Position(9, 7), new Demineur(Couleur.ROUGE));
			this.plateau.setPiece(new Position(9, 8), new Eclaireur(Couleur.ROUGE));
			this.plateau.setPiece(new Position(9, 9), new Demineur(Couleur.ROUGE));
        } catch (Exception ex) {
            System.out.println(ex);
            System.exit(1);
        }
    }

    /**
     * Retourne le plateau de jeu
     * @return Le plateau de jeu
     */
    public Plateau getPlateau() {
		return plateau;
	}

	/**
     * calcule les deplacements d'une piece situee sur le plateau
     * 
     * @param p_pos
     *            Position de la piece sur le plateau
     * @exception PositionInvalideException
     *                si la position pos ne correspond pas a une case accessible
     *                du plateau
     * @exception CaseVideException
     *                si la case situee en position pos ne contient pas de piece
     * @exception PieceImmobileException
     *                si la piece situee en position pos n'est pas une piece
     *                mobile
     */
    public void calculerEtAfficherDeplacements(Position p_pos)
            throws PositionInvalideException, CaseVideException,
            PieceImmobileException {
    	if (this.plateau.estPositionValide(p_pos) &&
    			!this.plateau.estCaseVide(p_pos)) {
    		this.plateau.calculerEtAfficherDeplacements(p_pos);
    	}
    }

    /**
     * retourne une chaine de caracteres representant le plateau
     * 
     * @return la chaine de caracteres
     */
    public String toString() {
        return (this.plateau.toString());
    }
}