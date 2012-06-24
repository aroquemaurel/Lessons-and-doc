package stratego;

import java.util.ArrayList;
import java.util.List;

/**
 * classe permettant la creation et la manipulation d'un eclaireur du jeu de
 * stratego.
 */
class Eclaireur extends PieceMobile {
    /**
     * construit un eclaireur
     * 
     * @param p_couleur
     *            couleur de la piece
     */
    public Eclaireur(Couleur p_couleur) {
    	super("eclaireur", 2, p_couleur);
    }
    
    public List<Position> positionsAccessibles(Plateau p_plateau) throws PositionInvalideException {
    	boolean estAccessible;
    	Position buff = new Position();
    	
        List<Position> vecteursDeplacementsPossibles = new ArrayList<Position>();
        vecteursDeplacementsPossibles.add(new Position(1, 0));
        vecteursDeplacementsPossibles.add(new Position(0, 1));
        vecteursDeplacementsPossibles.add(new Position(-1, 0));
        vecteursDeplacementsPossibles.add(new Position(0, -1));

        List<Position> positionsAccessibles = new ArrayList<Position>();
        for(Position iterateur : vecteursDeplacementsPossibles) {
        	buff.setX(this.getPosition().getX() + iterateur.getX());
			buff.setY(this.getPosition().getY() + iterateur.getY());
        	estAccessible = true;
        	while (estAccessible) {
            	if (p_plateau.estPositionValide(buff) &&
                	(p_plateau.estCaseVide(buff) || !this.getCouleur().equals(p_plateau.getPiece(buff).getCouleur()))) {
                		if (!p_plateau.estCaseVide(buff))
                			estAccessible = false;
                		
                		positionsAccessibles.add(new Position(buff.getX(), buff.getY()));
                    	buff.setX(buff.getX() + iterateur.getX());
        				buff.setY(buff.getY() + iterateur.getY());
                } else {
            		estAccessible = false;
            	}
        	}
        }
		return positionsAccessibles;
    }
}