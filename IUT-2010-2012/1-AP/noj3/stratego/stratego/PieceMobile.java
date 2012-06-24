package stratego;

import java.util.ArrayList;
import java.util.List;

/**
 * classe permettant la creation et la manipulation d'une piece mobile du jeu de
 * stratego.
 */
public abstract class PieceMobile extends Piece {
    /**
     * construit une piece mobile
     * @param p_nom
     *            Nom de la piece
     * @param p_grade
     *            Grade de la piece
     * @param p_couleur
     *            Couleur de la piece
     */
    public PieceMobile(String p_nom, int p_grade, Couleur p_couleur) {
    	super(p_nom, p_grade, p_couleur);
    }

    /**
     * renvoie le resultat de l'attaque d'une piece
     * 
     * @param p_piece
     *            Piece attaquee par la piece
     * @return REUSSIE si la piece mobile a gagne l'attaque, NULLE si les deux
     *         pieces se neutralisent ou PERDUE si la piece mobile a perdu
     *         l'attaque
     */
    public Attaque resultatAttaque(Piece p_piece) {
    	Attaque resultat;
        if(this.getGrade() > p_piece.getGrade()) {
        	resultat = Attaque.REUSSIE;
        } else if (this.getGrade() == p_piece.getGrade()) {
        	resultat = Attaque.NULLE;
        } else {
        	resultat = Attaque.PERDUE;
        }
        
        return(resultat);
    }

    /**
     * convertit une piece mobile en chaîne de caracteres
     * 
     * @return version unicode d'une piece mobile
     */
    public String toString() {
        Couleur ch = this.getCouleur();
        int g = this.getGrade();
        String res;
        res = " " + ch.toString().substring(0, 1);
        if (g < 10) {
            char c = (char) (g + (int) '0');
            res = res + c + " ";
        } else {
            char c = (char) ((g - 10) + (int) '0');
            res = res + "1" + c;
        }
        return res;
    }

    /**
     * recherche de toute les positions accessibles par la piece
     * 
     * @param p_plateau
     *            Plateau des pieces du jeu
     * @return liste des positions accessibles par la piece
     * @throws PositionInvalideException 
     */
    public List<Position> positionsAccessibles(Plateau p_plateau) throws PositionInvalideException {
        List<Position> vecteursDeplacementsPossibles = new ArrayList<Position>();
        vecteursDeplacementsPossibles.add(new Position(-1, 0));
        vecteursDeplacementsPossibles.add(new Position(0, -1));
        vecteursDeplacementsPossibles.add(new Position(1, 0));
        vecteursDeplacementsPossibles.add(new Position(0, 1));

        List<Position> positionsAccessibles = new ArrayList<Position>();
        for(Position iterateur : vecteursDeplacementsPossibles) {
        	Position buff = new Position(this.getPosition().getX() + iterateur.getX(),
        								 this.getPosition().getY() + iterateur.getY());
        	if (p_plateau.estPositionValide(buff) &&
        		(p_plateau.estCaseVide(buff) ||
        		 !p_plateau.getPiece(buff).getCouleur().equals(this.getCouleur()))) {
        		positionsAccessibles.add(buff);
        	}
        }
		return positionsAccessibles;
    }
}