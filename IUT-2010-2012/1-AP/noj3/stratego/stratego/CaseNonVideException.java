package stratego;

/**
 * exception liee a une case deja occupee par une piece
 */
public class CaseNonVideException extends StrategoException {
    private static final long serialVersionUID = 1L;

    public CaseNonVideException() {
        super("Il y a une piece sur la case");
    }
}
