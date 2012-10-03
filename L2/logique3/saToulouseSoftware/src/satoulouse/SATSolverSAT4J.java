/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package satoulouse;

import java.util.ArrayList;
import java.util.logging.Level;
import java.util.logging.Logger;
import org.sat4j.core.VecInt;
import org.sat4j.minisat.SolverFactory;
import org.sat4j.specs.ContradictionException;
import org.sat4j.specs.IProblem;
import org.sat4j.specs.ISolver;
import org.sat4j.specs.TimeoutException;

/**
 *
 * @author Ancmin
 */
public class SATSolverSAT4J {

    private final ISolver solver;
    private boolean alReadyUnSatisfiable = false;


    SATSolverSAT4J()
    {
        solver = SolverFactory.newDefault();
        TablePropositionForSAT4J tableProposition = FormulaForSAT4J.getTableProposition();
        int NBVAR = tableProposition.getNbPropositions();
        solver.newVar(NBVAR);
        
    }




    public void addFormula(FormulaForSAT4J formulaForSAT4J)
    {
        for(int j = 0; j < formulaForSAT4J.getNbClauses(); j++ )
        {
            int[] clauseTab = formulaForSAT4J.getClauseArrayInt(j);

            try {
                // the clause should not contain a 0, only integer (positive or negative)
                // with absolute values less or equal to MAXVAR
                // e.g. int [] clause = {1, -3, 7}; is fine
                // adapt Array to IVecInt
                solver.addClause(new VecInt(clauseTab)); // adapt Array to IVecInt
            } catch (ContradictionException ex) {

               // Logger.getLogger(SATSolverSAT4J.class.getName()).log(Level.SEVERE, null, ex);
                System.out.println("L'ensemble des formules est insatisfiable... je le vois quasi-directement !");
                alReadyUnSatisfiable = true;
            }
        }
    }

/**
 *
 * @param aucun... la formule qui est vérifiée est enregistré dans la variable "phi" de l'environnement
 * Scheme scheme (SchemeWithKawa)
 * @return null if the formula is unsatisfiable
 * the arraylist of propositions that are true for making the formula true (if sat)
 * @throws Exception
 */
    ArrayList<String> isSATFormulaInSchemeVar() throws Exception
    {
        if(alReadyUnSatisfiable)
             return null;
    
        Chronometre.printDuree();
        Chronometre.tickDebut();
        System.out.println("On appelle le solveur");
        // we are done. Working now on the IProblem interface
        IProblem problem = solver;
        try {
            ArrayList<String> propositions = new ArrayList<String>();
            if (problem.isSatisfiable()) {
                int [] model = problem.model();
                String modelString = "";
                for(int i = 0; i < model.length; i++)
                {
                    if(model[i] > 0)
                    {
                        String proposition = FormulaForSAT4J.getTableProposition().getProposition(model[i]);
                        if(!proposition.startsWith("(temp"))
                             propositions.add(proposition);
                    }
                       
                }
                Chronometre.printDuree();
                return propositions;
            } else {
                return null;
            }
        } catch (TimeoutException ex) {
            Logger.getLogger(SATSolverSAT4J.class.getName()).log(Level.SEVERE, null, ex);
            throw new Exception("time out");
        }

    }




}
