package stratego;

/**
 * exception liee a une position qui ne fait pas partie du plateau ou qui
 * correspond a un lac
 */
public class PositionInvalideException extends StrategoException {
    private static final long serialVersionUID = 1L;

    public PositionInvalideException() {
        super("la position n'est pas valide");
    }
}
