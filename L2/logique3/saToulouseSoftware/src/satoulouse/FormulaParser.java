/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package satoulouse;

import java.io.FileNotFoundException;
import java.io.IOException;
import jscheme.JScheme;
/**
 *
 * @author Ancmin
 */
public class FormulaParser {
        final static SchemeWithKawa scheme = new SchemeWithKawa();
        final static JScheme jscheme = new JScheme();



        
      static void putExpandedFormula(String var, String compactFormula)
        {
            scheme.eval("(set! " + var + schemeCodeToExpandFormula(compactFormula) + ")");
        }



      static String schemeCodeToExpandFormula(String compactFormula)
      {
          return " (formula-expand '" + compactFormula + ")";
         // return "'" + compactFormula;
      }

      static Object getExpandedFormula(String compactFormula)
        {
          //  return jscheme.eval("(formula-expand '" + compactFormula + ")");
            return jscheme.eval("'" + scheme.eval(schemeCodeToExpandFormula(compactFormula)));
        }

    static Object getRawFormula(String compactFormula) {
        return jscheme.eval("'" + compactFormula + ")");
    }
}
