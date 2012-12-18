/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package satoulouse;

/**
 * this class represents a formula directly translated for SAT4J
 * @author Ancmin
 */
public class FormulaForSAT4J {

    private final static TablePropositionForSAT4J tableProposition = new TablePropositionForSAT4J();
    private final static SchemeWithKawa scheme = new SchemeWithKawa();
    private final int NBCLAUSES;
    private final int [][] clausesTab;

    public static TablePropositionForSAT4J getTableProposition() {
        return tableProposition;
    }





    //private final Formula formula;
    
    FormulaForSAT4J(final Formula formulaNotExpanded)
    {
        FormulaParser.putExpandedFormula("phi", formulaNotExpanded.getString());
      //  this.formula = new Formula(formulaNotExpanded.getString(), true);
        System.out.println("--------------------");
        System.out.println("On calcule la cnf de " + formulaNotExpanded);
        Chronometre.tickDebut();
       // scheme.eval("(set! cnftemp (formulatocnf '" + formula + "))");
       scheme.eval("(set! cnftemp (formulatocnf phi))");
        Chronometre.printDuree();
        Chronometre.tickDebut();
        System.out.println("On calcule la table des propositions et la cnf format DIMACS");
      //  scheme.eval("(set! tabletemp (getvartable cnftemp))");


        Formula cnf = (new Formula(scheme.eval("cnftemp"), false));
        
        Chronometre.printDuree();
        Chronometre.tickDebut();

        NBCLAUSES = cnf.getNbSubFormulas();
        clausesTab = new int[NBCLAUSES][];
        for (int i=0;i<NBCLAUSES;i++) {
            Formula clause = cnf.getSubFormula(i);

          clausesTab[i] = new int[clause.getNbSubFormulas()];

          for(int j = 0; j < clause.getNbSubFormulas(); j++ )
              clausesTab[i][j] = tableProposition.getIntegerLitteral(clause.getSubFormula(j).toString());

        }






        
    }

    public int getNbClauses() {
        return NBCLAUSES;
    }


    public int[] getClauseArrayInt(int i)
    {
        return clausesTab[i];
    }
}
