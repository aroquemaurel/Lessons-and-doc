/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package satoulouse;

import gnu.mapping.Environment;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.logging.Level;
import java.util.logging.Logger;
import kawa.standard.Scheme;

/**
 *Cette classe permet d'appeler l'interpréteur Scheme (ici, Kawa) depuis Java.
 * @author François Schwarzentruber
 */
public class SchemeWithKawa {
    private static boolean cnfTransformation = true;

    public static void setCNFTransformation(boolean b)
    {
        cnfTransformation = b;
        restart();
    }



    private static kawa.standard.Scheme scheme = null;


    /**
     * redémarre l'interpréteur (en cas de plantage)
     */
    static void restart() {
        scheme = new kawa.standard.Scheme();

            Scheme.registerEnvironment();

            Environment.setCurrent(new Scheme().getEnvironment());
            lotrec_load();
    }
    
    public SchemeWithKawa() {
        if(scheme == null)
        {
            restart();
        }
    }
    
    public String evalDefine(String schemeCode)
    {
        try {
            return Scheme.eval(schemeCode, Environment.current()).toString();
           // StringWriter w = new StringWriter();
           // scheme.eval("(schemeCode, w);
          //  return w.toString();
        } catch (Throwable ex) {
            System.out.print(ex);
            return null;
        }
    }
    public String eval(String schemeCode)
    {
     //   try {
            return Scheme.eval("(format \"~a\" " + schemeCode + ")", Environment.current()).toString();
           // StringWriter w = new StringWriter();
           // scheme.eval("(schemeCode, w);
          //  return w.toString();
       // } catch (Throwable ex) {
      //      ex.printStackTrace();
      //      return null;
      //  }
    }
    
    
    static private void evalAndDoNotCareAboutTheResult(String schemeCode)
    {
        try {
            Scheme.eval(schemeCode, Environment.current()).toString();
           // StringWriter w = new StringWriter();
           // scheme.eval("(schemeCode, w);
          //  return w.toString();
        } catch (Throwable ex) {
            ex.printStackTrace();
            return;
        }
    }
    
    static private void lotrec_load() {
       // fileLoad("C:/lotrecmzjava/tout.scm");
        ressourcescheme_charger("match.scm");
        ressourcescheme_charger("formula-expander.scm");
        ressourcescheme_charger("vartablewithlists.scm");
      //  ressourcescheme_charger("vartable.scm");
       //ressourcescheme_charger("vartablehashtablesrfi.scm");
        if(cnfTransformation)
             ressourcescheme_charger("tocnfforsat4j.scm");
        else
            ressourcescheme_charger("tocnfforsat4jancien.scm");
      //  ressourcescheme_charger("tocnfforsat4jancien.scm");
     //   ressourcescheme_charger("program/sets.scm");
     //   ressourcescheme_charger("program/machinestate.scm");
      //  ressourcescheme_charger("program/nondeterminism.scm");
     //   ressourcescheme_charger("program/element-generator.scm");
     //   ressourcescheme_charger("program/rule.scm");
     //   ressourcescheme_charger("program/unification.scm");
     //   ressourcescheme_charger("program/lotreclight.scm");
        // ressourcescheme_charger("program/parser.scm");
      //  ressourcescheme_charger("program/compiler.scm");
    //    ressourcescheme_charger("program/functions.scm");
      //  ressourcescheme_charger("program/logicCPL-definition.scm");
     //   ressourcescheme_charger("program/tableaucpl.scm");
    }
    
    
    public void fileLoad(String fileName)
    {
        fileName = fileName.replace("\\", "/");
        evalAndDoNotCareAboutTheResult("(load \"" + fileName + "\")");
    }
    
    @SuppressWarnings("static-access")
    static private void ressourcescheme_charger(String filename)
    {   
        String s = null;
        
            
            try {
                s = TextFile.lire_dans_une_ressource_sans_les_load_descheme("resources/" + filename);
            } catch (FileNotFoundException ex) {
                Logger.getLogger(Scheme.class.getName()).log(Level.SEVERE, null, ex);
            } catch (IOException ex) {
                Logger.getLogger(Scheme.class.getName()).log(Level.SEVERE, null, ex);
            }
        
            evalAndDoNotCareAboutTheResult(s);
//            interpreter.interpret(
//            interpreter.compile( interpreter.read(s) )); marche pas

        
    }
    
}
