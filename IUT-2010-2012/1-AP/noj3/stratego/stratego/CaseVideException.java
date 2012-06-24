package stratego;

/**
 * exception liee a une case ne contenant aucune piece
 */
public class CaseVideException extends StrategoException {
    private static final long serialVersionUID = 1L;

    public CaseVideException() {
        super("Il n'y a aucune piece sur la case");
    }
}
