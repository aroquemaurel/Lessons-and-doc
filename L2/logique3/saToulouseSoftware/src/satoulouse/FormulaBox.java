/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */






/*
 * FormulaBox.java
 *
 * Created on 14 sept. 2010, 01:34:15
 * 
 */

package satoulouse;

import java.util.regex.Matcher;




/**
 * représente un widget pour entrer une formule logique
 * @author François Schwarzentruber
 */
public class FormulaBox extends javax.swing.JPanel {

    /**
     * vaut le FormulaBox qui détient le focus
     */
    private static FormulaBox focusOwnerformulaBox = null;


/**
 *
 * @return le formuleBox qui a le focus (où on écrit avec le clavier)
 */
    static FormulaBox getFocusOwnerFormulaBox()
    {
        return focusOwnerformulaBox;
    }


    /**
     *
     * @param formula
     * @return le code LaTEX correspondant à la formule
     * @throws Exception (l'analyse peut rater)
     */
    static public String formulaSchemeStringToLatexCode(String formula) throws Exception
    {
        return formulaSchemeToLatexCode(new Formula(formula, false));
    }


    /**
     *
     * @param formula
     * @return le code LaTEX correspondant à la formule
     * @throws Exception (l'analyse peut rater)
     */
    static private String formulaSchemeToLatexCode(Formula formula) throws Exception
    {
        if(formula.getString().startsWith("<"))
        {
            return "?";
        }
        else
        if(!formula.getString().startsWith("("))
        {
            return formula.getString();
        }
        else 
        if(formula.getString().equals("top"))
            return "\\top";
        else
         if(formula.getString().equals("bottom"))
            return "\\bot";
        else
        if(formula.getSubFormula(0).getString().equals("not"))
        {
            return "\\neg " + formulaSchemeToLatexCode(formula.getSubFormula(1));
        }
        else
        if(formula.getSubFormula(0).getString().equals("bigand"))
        {
            if(formula.getNbSubFormulas() == 4)
            return "\\bigwedge_{" + formula.getSubFormula(1).getString() +
                    "\\in " + remplacerParenthesesParAccolades(formula.getSubFormula(2).getString())
                    + "}" + formulaSchemeToLatexCode(formula.getSubFormula(3));
            else
                return "\\bigwedge_{" + formula.getSubFormula(1).getString() +
                    "\\in " + remplacerParenthesesParAccolades(formula.getSubFormula(2).getString()) +
                    " | " + conditionToLatexCode(formula.getSubFormula(3).getString()) +
                     "}" + formulaSchemeToLatexCode(formula.getSubFormula(4));
        }
        if(formula.getSubFormula(0).getString().equals("bigor"))
        {
            if(formula.getNbSubFormulas() == 4)
            return "\\bigvee_{" + formula.getSubFormula(1).getString() +
                    "\\in " + remplacerParenthesesParAccolades(formula.getSubFormula(2).getString())
                    + "}" + formulaSchemeToLatexCode(formula.getSubFormula(3));
            else
                return "\\bigvee_{" + formula.getSubFormula(1).getString() +
                    "\\in " + remplacerParenthesesParAccolades(formula.getSubFormula(2).getString()) +
                    " | " + conditionToLatexCode(formula.getSubFormula(3).getString()) +
                     "}" + formulaSchemeToLatexCode(formula.getSubFormula(4));
        }
        else
        if(formula.getSubFormula(0).getString().equals("bigxor"))
        {
            if(formula.getNbSubFormulas() == 4)
            return "\\bigoplus_{" + formula.getSubFormula(1).getString() +
                    "\\in " + remplacerParenthesesParAccolades(formula.getSubFormula(2).getString())
                    + "}" + formulaSchemeToLatexCode(formula.getSubFormula(3));
            else
                return "\\bigoplus_{" + formula.getSubFormula(1).getString() +
                    "\\in " + remplacerParenthesesParAccolades(formula.getSubFormula(2).getString()) +
                    " | " + conditionToLatexCode(formula.getSubFormula(3).getString()) +
                     "}" + formulaSchemeToLatexCode(formula.getSubFormula(4));
        }
        else
        if(formula.getSubFormula(1).getString().equals("and"))
        {
            if(formula.getNbSubFormulas() % 2 == 0)
                throw new Exception("Il manque au moins une sous-formule dans cette conjonction");
            
            String s = "\\left(" + formulaSchemeToLatexCode(formula.getSubFormula(0));

            for(int i = 1; i < formula.getNbSubFormulas(); i+=2)
            {
                if(!formula.getSubFormula(i).toString().equals("and"))
                    throw new Exception("J'attends un 'and'");
                
                s += " \\wedge " + formulaSchemeToLatexCode(formula.getSubFormula(i+1));
            }
            s += "\\right)";
            return s;
        }
        if(formula.getSubFormula(1).getString().equals("or"))
        {
            if(formula.getNbSubFormulas() % 2 == 0)
                throw new Exception("Il manque au moins une sous-formule dans cette conjonction");

            String s = "\\left(" + formulaSchemeToLatexCode(formula.getSubFormula(0));

            for(int i = 1; i < formula.getNbSubFormulas(); i+=2)
            {
                if(!formula.getSubFormula(i).toString().equals("or"))
                    throw new Exception("J'attends un 'or'");

                s += " \\vee " + formulaSchemeToLatexCode(formula.getSubFormula(i+1));
            }
            s += "\\right)";
            return s;
        }
        if(formula.getSubFormula(1).getString().equals("imply"))
        {
            return "\\left(" + formulaSchemeToLatexCode(formula.getSubFormula(0))
                    + " \\rightarrow " + formulaSchemeToLatexCode(formula.getSubFormula(2)) + "\\right)";
        }
        if(formula.getSubFormula(1).getString().equals("equiv"))
        {
            return "\\left(" + formulaSchemeToLatexCode(formula.getSubFormula(0))
                    + " \\leftrightarrow " + formulaSchemeToLatexCode(formula.getSubFormula(2)) + "\\right)";
        }
        


        else
            //propositions
        {
            if(formula.getNbSubFormulas() <= 1)
                throw new Exception("Bizarre... il y a trop de parenthèses");
            
            String s = formula.getSubFormula(0).getString() + "_{";
            
            for(int i = 1; i < formula.getNbSubFormulas()-1; i++)
            {
                s = s + formula.getSubFormula(i) + ", ";
            }

            
            s = s + formula.getSubFormula(formula.getNbSubFormulas()-1);

            s = s + "}";
            return s;
        }


    }


    /**
     * Traduit une condition en LaTEX
     * Exemple "(i diff 1)" en "(i \neq 1)"
     * @param conditionText
     * @return le code LaTEX de la condition
     */
    private static String conditionToLatexCode(String conditionText) {
        return conditionText.replaceAll(" diff ",
                     Matcher.quoteReplacement(" \\neq "));
    }


    private FormulaForSAT4J formulaForSAT4J = null;
    private boolean formulaForSAT4Jupdated = false;



    /** Creates new form FormulaBox */
    public FormulaBox() {
        initComponents();
        lblError.setVisible(false);
        lblAffichage.setText("");

    }




    

    /** This method is called from within the constructor to
     * initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is
     * always regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        txtFormula = new satoulouse.SchemeFormulaTextField();
        lblError = new javax.swing.JLabel();
        lblAffichage = new javax.swing.JLabel();
        jLabel1 = new javax.swing.JLabel();

        setName("Form"); // NOI18N
        addFocusListener(new java.awt.event.FocusAdapter() {
            public void focusGained(java.awt.event.FocusEvent evt) {
                formFocusGained(evt);
            }
        });
        setLayout(new javax.swing.BoxLayout(this, javax.swing.BoxLayout.Y_AXIS));

        org.jdesktop.application.ResourceMap resourceMap = org.jdesktop.application.Application.getInstance(satoulouse.SatoulouseApp.class).getContext().getResourceMap(FormulaBox.class);
        txtFormula.setText(resourceMap.getString("txtFormula.text")); // NOI18N
        txtFormula.setAlignmentX(0.0F);
        txtFormula.setFont(resourceMap.getFont("txtFormula.font")); // NOI18N
        txtFormula.setMaximumSize(new java.awt.Dimension(2147483647, 28));
        txtFormula.setName("txtFormula"); // NOI18N
        txtFormula.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                txtFormulaMouseClicked(evt);
            }
        });
        txtFormula.addFocusListener(new java.awt.event.FocusAdapter() {
            public void focusGained(java.awt.event.FocusEvent evt) {
                txtFormulaFocusGained(evt);
            }
            public void focusLost(java.awt.event.FocusEvent evt) {
                txtFormulaFocusLost(evt);
            }
        });
        txtFormula.addKeyListener(new java.awt.event.KeyAdapter() {
            public void keyReleased(java.awt.event.KeyEvent evt) {
                txtFormulaKeyReleased(evt);
            }
        });
        add(txtFormula);

        lblError.setBackground(resourceMap.getColor("lblError.background")); // NOI18N
        lblError.setFont(resourceMap.getFont("lblError.font")); // NOI18N
        lblError.setForeground(resourceMap.getColor("lblError.foreground")); // NOI18N
        lblError.setText(resourceMap.getString("lblError.text")); // NOI18N
        lblError.setName("lblError"); // NOI18N
        add(lblError);

        lblAffichage.setText(resourceMap.getString("lblAffichage.text")); // NOI18N
        lblAffichage.setName("lblAffichage"); // NOI18N
        lblAffichage.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                lblAffichageMouseClicked(evt);
            }
        });
        add(lblAffichage);

        jLabel1.setText(resourceMap.getString("jLabel1.text")); // NOI18N
        jLabel1.setMaximumSize(new java.awt.Dimension(33, 22));
        jLabel1.setMinimumSize(new java.awt.Dimension(33, 22));
        jLabel1.setName("jLabel1"); // NOI18N
        jLabel1.setPreferredSize(new java.awt.Dimension(33, 22));
        add(jLabel1);
    }// </editor-fold>//GEN-END:initComponents

    private void txtFormulaKeyReleased(java.awt.event.KeyEvent evt) {//GEN-FIRST:event_txtFormulaKeyReleased
        txtFormula.doRepaint();
        miseAJour();
    }//GEN-LAST:event_txtFormulaKeyReleased

    private void txtFormulaMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_txtFormulaMouseClicked
        txtFormula.doRepaint();
        miseAJour();
    }//GEN-LAST:event_txtFormulaMouseClicked

    private void lblAffichageMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_lblAffichageMouseClicked
        /**
         * afficher la formule "expandée" dans une fenêtre
         */

        System.out.println(getFormula().getString());
    }//GEN-LAST:event_lblAffichageMouseClicked

    private void txtFormulaFocusLost(java.awt.event.FocusEvent evt) {//GEN-FIRST:event_txtFormulaFocusLost
        txtFormula.repaint();
    }//GEN-LAST:event_txtFormulaFocusLost

    private void formFocusGained(java.awt.event.FocusEvent evt) {//GEN-FIRST:event_formFocusGained
        focusOwnerformulaBox = this;
    }//GEN-LAST:event_formFocusGained

    private void txtFormulaFocusGained(java.awt.event.FocusEvent evt) {//GEN-FIRST:event_txtFormulaFocusGained
        focusOwnerformulaBox = this;
    }//GEN-LAST:event_txtFormulaFocusGained



/**
 *
 * @return la chaîne de caractère à sélectionner et à remplacer.
 * Exemple : "<agt>" etc.
 */
    private String aCompleter()
    {
        String s = getText();

        int a = s.indexOf("<");

        if(a < 0)
            return null;


        int b = s.indexOf(">", a);

        return s.substring(a, b+1);
    }
    /**
     *
     * @return renvoie l'indice dans le texte où il y a un problème de parenthèse fermante en trop
     * si renvoie -2 c'est qu'on conditionText'appercoit à la fin qu'il y a trop de parenthèse ouverte
     * si renvoie -1 alors c'est bon.
     *
     */
    private int indiceAvecErreurParenthese()
    {
        String s = getText();

        int compteur = 0;
        for(int i = 0; i < s.length(); i++)
        {
            if(s.charAt(i) == '(')
                compteur += 1;

            if(s.charAt(i) == ')')
                compteur -= 1;

            if(compteur < 0)
                return i;
        }

        if(compteur > 0)
            return -2;
        
        return -1;
    }



    /**
     * met à jour l'affichage LaTEX.
     * En cas d'erreur, affiche un message d'erreur
     */
    private void mettreAJourAffichageLatex()
    {
        lblError.setVisible(false);
        txtFormula.noError();
        lblAffichage.setText("");

        int i = indiceAvecErreurParenthese();
        if(i >= 0)
        {
            afficherMessageErreur("parenthèse fermante en trop au caractère n°" + i);
            txtFormula.error(i);
            return;
        }
        else if (i == -2)
        {
            afficherMessageErreur("parenthèse ouvrante en trop mais je ne sais pas où");
            return;
        }



        String s = aCompleter();

        if(s != null)
        {
            afficherMessageConseil("Remplace " + s + " par quelquechose !");
        }
        
        try
        {
            if(!txtFormula.getText().isEmpty())
            {
                 Formula formula = (new Formula("(" + txtFormula.getText() + ")", false));

                 if(formula.getNbSubFormulas() > 1)
                 {
                     txtFormula.errorAll();
                     throw new Exception("Tu dois mettre des parenthèses autour tout ça ! Là, je lis '"
                              + formula.getSubFormula(0).toString() + "' puis '"
                              + formula.getSubFormula(1).toString() + "' et je ne comprends pas");
                 }
                 lblAffichage.setIcon(LaTEX.latexCodeToImageIcon(formulaSchemeToLatexCode(formula.getSubFormula(0))));
                 lblAffichage.setVisible(true);
            }
            else
            {
                lblAffichage.setIcon(null);
            }
        }
        catch(Exception e)
        {
            afficherMessageErreur(e.getMessage());

        }
        
    }



/**
 *
 * @return true ssi la formule écrite est compréhensible !
 */
    public boolean isOK()
    {
        return !lblError.isVisible();
    }

/**
 * affiche le message d'erreur pour signaler, souvent, une erreur de syntaxe
 * @param s
 */
    private void afficherMessageErreur(String s)
    {
        lblAffichage.setVisible(false);
        lblError.setVisible(true);
        lblError.setText("Error: " + s);
    }


    /**
     * affiche un conseil
     * @param s
     */
    private void afficherMessageConseil(String s)
    {
        lblError.setVisible(true);
        lblError.setText("Conseil : " + s);
    }

    /**
     *
     * @return le texte écrit par l'utilisateur
     */
    public String getText()
    {
        return txtFormula.getText();
    }

    /**
     *
     * @return la formule (non expandée)
     *         null si le champ est vide
     */
    public Formula getFormulaNotExpanded()
    {
        if(getText().isEmpty())
            return null;
        else
            return new Formula(getText().replaceAll("\\+", " \\+ "), false);
    }

    /**
     *
     * @return la formule (expandée)
     *         null si le champ est vide
     */
    public Formula getFormula()
    {
        if(getText().isEmpty())
            return null;
        else
            return new Formula(getText().replaceAll("+", " + "));
    }

    


    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel lblAffichage;
    private javax.swing.JLabel lblError;
    private satoulouse.SchemeFormulaTextField txtFormula;
    // End of variables declaration//GEN-END:variables

    void setText(String string) {
        txtFormula.setText(string);
        miseAJour();
    }

    private boolean isChampAvecRien() {
        if(txtFormula.getSelectedText() != null)
        if(txtFormula.getSelectedText().startsWith("<"))
            return true;

        txtFormula.selectionnerChampSousFormule();

        if(txtFormula.getSelectedText() == null)
            return true;

        return false;
    }


    /**
     * mange une expression Scheme, comme "(a (b c))" et enlève les parenthèses
     * extérieures pour les remplacer par des accolades, qu'on voit sous LaTEX.
     * Ie. renvoie "\{a (b c)\}"
     * @param string
     * @return
     */
    static private String remplacerParenthesesParAccolades(String string) {
        return "\\{" + (string.substring(1, string.length()-1).replaceAll(" ", ", ")) + "\\}";
    }

    /**
     * insère le texte à la position du curseur courant
     * @param texte
     */
    void insert(String texte) {
        txtFormula.replaceSelection(texte);
        miseAJour();
    }

    @Override
    public boolean isFocusOwner() {
        return super.isFocusOwner() || txtFormula.isFocusOwner();
    }

    boolean isEmpty() {
        return getText().isEmpty();
    }



    public FormulaForSAT4J getFormulaForSAT4J()
    {
        if(formulaForSAT4Jupdated)
            return formulaForSAT4J;
        else
        {
            formulaForSAT4J = new FormulaForSAT4J(getFormulaNotExpanded());
            formulaForSAT4Jupdated = true;
            return formulaForSAT4J;
        }
    }






    private void miseAJour()
    {
        mettreAJourAffichageLatex();
        formulaForSAT4Jupdated = false;
       // formulaForSAT4J = new FormulaForSAT4J(getFormulaNotExpanded());
    }
}
