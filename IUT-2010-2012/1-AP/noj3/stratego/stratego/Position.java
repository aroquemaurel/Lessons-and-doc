package stratego;

/**
 * classe permettant la creation et la manipulation des positions des pieces du
 * jeu de stratego.
 */
public class Position {
    /**
     * valeur de la premiere composante (ligne)
     */
    private int x;
    /**
     * valeur de la seconde composante (colonne)
     */
    private int y;

    /**
     * construit une position
     * 
     * @param l
     *            premiere composante de la position
     * @param c
     *            seconde composante de la position
     **/
    public Position(int l, int c) {
        this.x = l;
        this.y = c;
    }

    /**
     * construit une position de composantes nulles
     */
    public Position() {
        this(0, 0);
    }

    /**
     * retourne la valeur de la première composante (ligne)
     * 
     * @return premiere composante de la position
     **/
    public int getX() {
        return (this.x);
    }

    /**
     * Affecte la valeur de la première composante (ligne)
     * @param x nouvelle composante
     */
    public void setX(int x) {
		this.x = x;
	}

    /**
     * retourne la valeur de la deuxieme composante (colonne)
     * 
     * @return seconde composante de la position
     **/
    public int getY() {
        return (this.y);
    }

    /**
     * Affecte la valeur de la deuxieme composante (colonne)
     * @param y nouvelle composante
     */
	public void setY(int y) {
		this.y = y;
	}

	/**
     * teste l'egalite de deux positions
     * 
     * @param p_position
     *            Objet a comparer a la position courante
     * @return VRAI si les deux positions sont identiques
     */
    public boolean equals(Object p_position) {
        boolean resultat;

        if (p_position instanceof Position) {
            Position c = (Position) p_position;
            resultat = ((this.x == c.getX()) && (this.y == c.getY()));
        } else {
            resultat = false;
        }
        return resultat;
    }

    /**
     * retourne le hashCode d'une position
     * 
     * @return le hashCode d'une position
     */
    public int hashCode() {
        return this.x * 100 + this.y;
    }

    /**
     * retourne une version unicode d'une position
     * 
     * @return chaine correspondant a la position
     */
    public String toString() {
        return ("(" + this.x + ", " + this.y + ")");
    }
}