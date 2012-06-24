package stratego;

import java.util.Hashtable;
import java.util.List;
import java.util.Map;

/**
 * classe permettant la creation et la manipulation d'un plateau de jeu de
 * stratego
 */
public class Plateau {
    /**
     * taille maximum du plateau
     */
    static final int NB_LIG_COL = 10;
    /**
     * map des pieces mobiles
     */
    private Map<Position, PieceMobile> piecesMobiles;
    /**
     * liste des pieces immobiles
     */
    private Map<Position, PieceImmobile> piecesImmobiles;

    /**
     * construit un plateau vide
     */
    public Plateau() {
    	this.piecesImmobiles = new Hashtable<Position, PieceImmobile>();
    	this.piecesMobiles = new Hashtable<Position, PieceMobile>();
    }

    /**
     * accede a une piece a partir de sa position
     * 
     * @param p_position
     *            position de la piece a acceder
     * @return la piece ou null s'il n'y a pas de piece a cette position
     */
    public Piece getPiece(Position p_position) {
    	Piece retour = null;
    	if (this.piecesImmobiles.keySet().contains(p_position))
    		retour = this.piecesImmobiles.get(p_position);
    	else {
    		if (this.piecesMobiles.keySet().contains(p_position))
    			retour = this.piecesMobiles.get(p_position);
    	}
		return retour;
    }

    /**
     * verifie si une position correspond a une case du plateau accessible par
     * une piece (ne doit pas correspondre a un lac)
     * 
     * @param position
     *            position a verifier
     * @return vrai si la position est valide
     */
    public boolean estPositionValide(Position position) {
        int x = position.getX();
        int y = position.getY();

        boolean resultat = (x < 0 || x >= Plateau.NB_LIG_COL || y < 0 || y >= Plateau.NB_LIG_COL);

        for (int i = 4; i < 6; i++) {
            for (int j = 0; j < 2; j++) {
                resultat = resultat
                        || (position.equals(new Position(i, j + 2)))
                        || (position.equals(new Position(i, j + 6)));
            }
        }
        return (!resultat);
    }

    /**
     * verifie si une case du plateau est vide
     * 
     * @param p_position
     *            position de la case sur le plateau
     * @return vrai si la case est vide
     */
    public boolean estCaseVide(Position p_position) {
    	return(!this.piecesImmobiles.containsKey(p_position) && !this.piecesMobiles.containsKey(p_position));
    }

    /**
     * affiche le plateau de jeu
     */
    public String toString() {
        System.out.println("nombre de pièces mobiles "
                + this.piecesMobiles.size());
        System.out.println("nombre de pièces immobiles "
                + this.piecesImmobiles.size());
        System.out.println(this.piecesMobiles);
        System.out.println(this.piecesImmobiles);

        String res = "";
        char c;

        res = res + "     0    1    2    3    4    5    6    7    8    9\n";
        res = res + "   ---------------------------------------------------\n";
        for (int i = 0; i < NB_LIG_COL; i++) {
            c = (char) (i + (int) '0');
            res = res + " " + c + " |";
            for (int j = 0; j < NB_LIG_COL; j++) {
                Position position = new Position(i, j);
                if (this.estPositionValide(position)) {
                    Piece p = this.getPiece(position);
                    if (p != null) {
                        res = res + p;
                    } else {
                        res = res + "    ";
                    }
                } else {
                    res = res + "~~~~";
                }
                res = res + "|";
            }
            res = res + "\n";
            res = res
                    + "   ---------------------------------------------------\n";
        }
        return res;
    }

    /**
     * positionne une piece mobile sur le plateau
     * 
     * @param p_position
     *            position ou la piece doit etre positionnee
     * @param p_pieceMobile
     *            piece a positionner
     * @exception PositionInvalideException
     *                si la position n'existe pas
     * @exception CaseNonVideException
     *                s'il y a deja une piece sur la case
     */
    public void setPiece(Position p_position, PieceMobile p_pieceMobile)
            throws PositionInvalideException, CaseNonVideException {
    	if (!this.estPositionValide(p_position)) {
    		 throw(new PositionInvalideException());
    	}
    	
    	if (!this.estCaseVide(p_position)) {
    		throw(new CaseNonVideException());
    	}
    	
    	p_pieceMobile.setPosition(p_position);
    	this.piecesMobiles.put(p_position, p_pieceMobile);
    }

    /**
     * positionne une piece immobile sur le plateau
     * 
     * @param p_position
     *            position ou la piece doit etre positionnee
     * @param p_pieceImmobile
     *            piece a positionner
     * @exception PositionInvalideException
     *                si la position n'existe
     * @exception CaseNonVideException
     *                s'il y a deja une piece sur la case
     */
    public void setPiece(Position p_position, PieceImmobile p_pieceImmobile)
            throws PositionInvalideException, CaseNonVideException {
    	if (!this.estPositionValide(p_position)) {
    		throw(new PositionInvalideException());
    	}
   	
    	if (!this.estCaseVide(p_position)) {
    		throw(new CaseNonVideException());
    	}
   	
    	p_pieceImmobile.setPosition(p_position);
    	this.piecesImmobiles.put(p_position, p_pieceImmobile);
    }

    /**
     * calcule et affiche tous les déplacements possibles d'une piece mobile et
     * indique pour chaque déplacement s'il y a eu une attaque et son resultat
     * (reussie, perdue ou nulle)
     * 
     * @param p_position
     *            piece mobile dont on veut calculer les deplacements possibles
     */
    public void calculerEtAfficherDeplacements(Position p_position) throws PieceImmobileException, CaseVideException {
    	List<Position> deplacementsPossibles;
    	if (this.estCaseVide(p_position)) {
    		throw new CaseVideException();
    	}
    	
    	if(this.getPiece(p_position) instanceof PieceImmobile){
    		throw (new PieceImmobileException());
    	}
    	
    	try {
			deplacementsPossibles = ((PieceMobile) this.getPiece(p_position)).positionsAccessibles(this);
		    this.afficherDeplacements(deplacementsPossibles, p_position);
		} catch (PositionInvalideException exception) {
			exception.printStackTrace();
		}
    }
    
	/**
	 * Affiche une liste de déplacements pour une position donnée
	 * @param p_deplacements Liste de déplacements à afficher
	 * @param p_position Position de départ des déplacements
	 */
	private void afficherDeplacements(List<Position> p_deplacements, Position p_position) {
		if (p_deplacements.size() == 0) {
			System.out.println("Aucun déplacement possible pour " + this.getPiece(p_position).getNom()
								+ " " + this.getPiece(p_position).getCouleur());
		} else {
	    	System.out.println("Positions accessibles par " + this.getPiece(p_position).getNom()
	    						+ " " + this.getPiece(p_position).getCouleur());
		}
		
		for (Position it : p_deplacements) {
			System.out.print("position " + it);
			
			if (!this.estCaseVide(it)) {
				System.out.print(" L'attaque contre " + this.getPiece(it).getNom()
							+ " " + this.getPiece(it).getCouleur() + " est "
							+ ((PieceMobile) this.getPiece(p_position)).resultatAttaque(this.getPiece(it)));
			}
			
			System.out.println();
		}
	}
}