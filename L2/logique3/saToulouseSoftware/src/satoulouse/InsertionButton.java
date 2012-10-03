/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * SATResults.java
 *
 * Created on 26 sept. 2010, 02:57:12
 */

package satoulouse;


import java.util.ArrayList;

/**
 * Cette classe représente un bouton qui permet d'insérer du texteScheme
 * dans un champ Scheme
 * Par exemple, le bouton pour insérer "(<phi> and <psi>)"
 * @author François Schwarzentruber
 */
public class InsertionButton extends javax.swing.JButton  {

    /**
     * the text the button inserts when we clicked
     */
    private final String schemeCodeToInsert;

    /**
     * the set of FormulaBoxes that are looked and if one
     * of them is under focus, the text will be inserted in it.
     */
    private final ArrayList<FormulaBox> formulaBoxes;


    

    /**
     * 
     * @param formulaBoxes
     * @param texteScheme
     */
    public InsertionButton(ArrayList<FormulaBox> formulaBoxes, String texteScheme) {
        this.formulaBoxes = formulaBoxes;
        this.schemeCodeToInsert = texteScheme;
        try
        {
            this.setIcon(LaTEX.latexCodeToImageIcon(FormulaBox.formulaSchemeStringToLatexCode(texteScheme)));
        }
        catch(Exception e)
        {
            System.out.println("Erreur d'insertion de bouton dans la palette : problème avec le code latex de "+ texteScheme);
        }
         addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                inserer(schemeCodeToInsert);
            }
        });
        this.setFocusable(false);
        this.setHorizontalTextPosition(javax.swing.SwingConstants.CENTER);
        //this.setName("bigor"); // NOI18N
        this.setVerticalTextPosition(javax.swing.SwingConstants.BOTTOM);
       // this.setMaximumSize(new Dimension(this.getIcon().getIconWidth(),this.getIcon().getIconHeight()));
     //   this.setPreferredSize(new Dimension(this.getIcon().getIconWidth(),this.getIcon().getIconHeight()));
    }



    /**
     * insère le texteScheme texteScheme dans le champ Scheme sélectionné
     * @param texteScheme
     */
    private void inserer(String texte)
    {
        for(FormulaBox fb : formulaBoxes)
        {
            if(fb.isFocusOwner())
                fb.insert(texte);
        }

    }

    /**
     *
     * @param formulaBoxes
     * @param texteScheme
     * @param aide
     */
    public InsertionButton(ArrayList<FormulaBox> formulaBoxes, String texteScheme, String aide) {
        this(formulaBoxes, texteScheme);
        setToolTipText(aide);
        
    }








}
