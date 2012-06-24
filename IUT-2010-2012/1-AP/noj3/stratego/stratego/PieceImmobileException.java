package stratego;

/**
 * exception liee au fait qu'une piece immobile ne peut pas se deplacer
 */
public class PieceImmobileException extends StrategoException {
    private static final long serialVersionUID = 1L;

    public PieceImmobileException() {
        super("la piece est une piece immobile");
    }
}
