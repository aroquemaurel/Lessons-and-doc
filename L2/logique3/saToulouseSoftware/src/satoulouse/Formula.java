/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package satoulouse;

import java.util.ArrayList;
import jscheme.SchemePair;

/**
 *
 * @author François Schwarzentruber
 */
public class Formula {


    static private String getLitteral(int n)
    {
        if(n < 0)
            return "(not (p " + (-n) + "))";
        else
            return "(p " + n + ")";
    }

    static private String createClauseFromCNFFileLine(String line)
    {
        int i = 0;

        String clause = "";
        boolean auplusunlitteral = true;

        while(line.indexOf(" ", i) >= 0)
        {
            int i2 = line.indexOf(" ", i);
            if(i2 > i)
            {
                int n = Integer.parseInt(line.substring(i, i2));

                String litteral = getLitteral(n);

                if(clause.equals(""))
                {
                    clause = litteral;
                }
                else if(auplusunlitteral)
                {
                    clause = "(" + clause + " or " + litteral;
                    auplusunlitteral = false;
                }
                else
                {
                    clause = clause + " or " + litteral;
                }
            }

            i = i2 + 1;
        }

        if(!auplusunlitteral)
            clause = clause + ")";
        
        return clause;
    }




    public static ArrayList<String> createListFormulaFromCNFFile(ArrayList<String> T)
    {

        ArrayList<String> formulas = new ArrayList<String>();

        for(String l : T)
        {
            if(!(l.startsWith("c") || l.startsWith("p")))
            {
               String clause = createClauseFromCNFFileLine(l);

               if(!clause.isEmpty())
               {
                   formulas.add(clause);
               }


            }

        }


        return formulas;
    }

    
    public static String createFormulaFromCNFFile(ArrayList<String> T)
    {

        String formula = "";
        boolean auplusuneclause = true;
        

        for(String l : T)
        {
            if(!(l.startsWith("c") || l.startsWith("p")))
            {
               String clause = createClauseFromCNFFileLine(l);

               if(!clause.isEmpty())
               {
                   if(formula.equals(""))
                       formula = clause;
                   else if(auplusuneclause)
                   {
                       formula = "(" + formula + " and " + clause;
                        auplusuneclause = false;
                   }
                   else
                   {
                       formula = formula + " and " + clause;
                   }
               }

                
            }

        }

        if(!auplusuneclause)
            formula = formula + ")";
        
        return formula;
    }





    static Formula createAnd(Formula f1, Formula f2) {
        String s1, s2;

        if(f1 == null)
            return f2;
        else
            s1 = f1.getString();

        if(f2 == null)
            return f1;
        else
            s2 = f2.getString();


        if(s1.isEmpty())
            s1 = "top";

        if(s2.isEmpty())
            s2 = "top";

        return new Formula("(" + s1 + " and " + s2 +")");
    }




    final FormulaParser parser = new FormulaParser();
    final Object schemeFormula;

    public Formula(String text) {
        schemeFormula = FormulaParser.getExpandedFormula(text);

    }


    public Formula(String text, boolean expanded) {
        if(expanded)
             schemeFormula = FormulaParser.getExpandedFormula(text);
        else
            schemeFormula = FormulaParser.getRawFormula(text);

    }
    

    private Formula(Object obj) {
        schemeFormula = obj;

    }


    Formula getSubFormula(int i)
    {
        return new Formula(((SchemePair) ((SchemePair) schemeFormula).listTail(i)).first());
        
    }


    int getNbSubFormulas()
    {
        return ((SchemePair) schemeFormula).length();
    }



    String getString()
    {
        return schemeFormula.toString();
    }

    @Override
    public boolean equals(Object obj) {
        if(obj instanceof Formula)
              return getString().equals(((Formula) obj).getString());
        else
            return false;
    }

    @Override
    public int hashCode() {
        int hash = 7;
        hash = 37 * hash + (this.schemeFormula != null ? this.schemeFormula.hashCode() : 0);
        return hash;
    }

    @Override
    public String toString() {
        return getString();
    }





}
