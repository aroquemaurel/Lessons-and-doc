/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package satoulouse;

import java.awt.Color;
import java.awt.Dimension;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Insets;
import java.awt.Point;
import java.awt.RenderingHints;
import java.util.ArrayList;
import javax.swing.JTextField;

/**
 * représente un champ où on peut écrire une formule de la logique propositionelle au format Scheme
 * format Scheme ça veut dire : des parenthèses !
 * Comme "(p or (q and (not e)))"
 * @author François Schwarzentruber
 */
public class SchemeFormulaTextField extends JTextField {


    /**
     * liste des mots clefs coloriés en bleu
     */
    private ArrayList<String> motsClefs = new ArrayList<String>();


    /**
     * spécifie là où il y a une erreur dans la formule
     * plageError.x = début
     * plageError.y = fin
     */
    private Point plageError = null;


    public SchemeFormulaTextField() {
        motsClefs.add("or");
        motsClefs.add("sees");
        motsClefs.add("and");
        motsClefs.add("bigand");
        motsClefs.add("bigor");
        motsClefs.add("bigxor");
        motsClefs.add("xor");
        motsClefs.add("not");
        motsClefs.add("imply");
        motsClefs.add("equiv");

        setFont(new Font("", Font.BOLD, 14));

    }



    @Override
	public Insets getInsets() {
		Insets i=super.getInsets();
		try{
		
                    return new Insets(0,i.left,i.bottom,i.right);
		} catch (NullPointerException npe) {return i;}
	}


    public void selectionnerChampSiBesoin()
    {
        selectionnerChampSiBesoinSub('<', '>');
    }


public void selectionnerChampSousFormule()
    {
        selectionnerChampSiBesoinSub('(', ')');
    }





    public Point coordonneesParenthesesSousFormuleCourante()
    {
        char debut = '(';
        char fin = ')';


        String s = getText();

        if(s.equals(""))
            return null;

        int i =  getSelectionStart()-1;

        if(i > s.length() - 1)
            i = s.length() - 1;

        if(i < 0)
            i = 0;
        
        int jdebut = -1;
        int jfin = -1;
        int c = 0;
        for(int j = i; j>=0;j--)
        {

            if(s.charAt(j)==debut && (c <= 0))
            {
                jdebut = j;
                break;
            }
            else
            if(s.charAt(j)==debut)
            {
                c--;
            }
            if(s.charAt(j)==fin)
                c++;
        }


        i =  getSelectionStart();
        if(i > s.length() - 1)
            i = s.length() - 1;
        
        c = 0;
        for(int j = i; j<s.length();j++)
        {
            if((s.charAt(j)==fin) && (c <= 0))
            {
                jfin = j;
                break;
            }
            else
            if(s.charAt(j)==fin)
                c--;
            else
            if(s.charAt(j)==10)
            {
                break;
            }
            if(s.charAt(j)==debut)
                c++;
        }

        if((jdebut != -1) && (jfin != -1))
        {
             return new Point(jdebut, jfin);
        }
        else
            return null;






    }





        /**
     * select the field if there is a field between charBegin and fin
     * usually charBegin = '<' and charFin = '>'
     * @param charBegin
     * @param charFin
     */
    public void selectionnerChampSiBesoinSub(char charBegin, char charFin)
    {

        String text = getText();

        if(text.equals(""))
            return;



        int jdebut = text.lastIndexOf(charBegin, getSelectionStart());
        int jfin = text.indexOf(charFin, getSelectionEnd()-1);

        if((jdebut == -1) || (jfin == -1))
            return;

        /**
         * fieldName = phi if the field is <phi>
         */
        String fieldName = text.substring(jdebut+1, jfin);

        if(fieldName.indexOf("<") != -1)
            return;

        if(fieldName.indexOf(">") != -1)
            return;

         setSelectionStart(jdebut);
         setSelectionEnd(jfin+1);

    }


    /**
     * write texte in the textbox
     * positionTexte = 0 means "start of the text"
     * @param g
     * @param s
     * @param positionTexte
     */
    private void drawStringOverlap(Graphics g, String s, int i)
    {
        
        int x = getX(g, i);
        g.drawString(s,
                     x,
                     g.getFontMetrics().getHeight()-3);//+2*(18-g.getFont().getSize())/3);

        
    }


/**
 *
 * @param g
 * @param numeroCharacter
 * @return abscisse en pixel du caractère numero numeroCharacter (g = le graphique utilisé pour afficher le texte)
 */
    private int getX(Graphics g, int numeroCharacter)
    {
        return (int) (getColumnWidth()*0.2+
                g.getFontMetrics().getStringBounds(getText().substring(0, numeroCharacter), g).getMaxX()
                      -getScrollOffset());
    }



    private int getTextWidth()
    {
        if(getGraphics() == null)
            return 0;
        else
            return (int) (getColumnWidth()*0.2+
                getGraphics().getFontMetrics().getStringBounds(getText(), getGraphics()).getMaxX());
    }

    private int getTextHeight(Graphics g)
    {
        return g.getFontMetrics().getHeight();
    }

    
    private void drawStringOverlapBackGroundColor(Graphics g, String s, int positionTexte, Color backgroundColor, Color textColor)
    {

        int x = getX(g, positionTexte);
        int w = (int) g.getFontMetrics().getStringBounds(s, g).getMaxX();
        int h = getTextHeight(g);
        g.setColor(backgroundColor);
        g.fillRect(x, 0, w, h);
        g.setColor(textColor);
        g.drawString(s,
                     x,
                     h-3);//+2*(18-g.getFont().getSize())/3);


    }



/**
 * prépare le contexte graphique g2 à afficher des choses jolies
 * (anti-aliasing, qualité superbe)
 * @param g2
 */
    private void Graphics2Dconfigure(Graphics2D g2)
    {
        g2.setRenderingHint(RenderingHints.KEY_ANTIALIASING,
        RenderingHints.VALUE_ANTIALIAS_ON);
        g2.setRenderingHint(RenderingHints.KEY_RENDERING,
        RenderingHints.VALUE_RENDER_QUALITY);
    }

    @Override
    protected void paintComponent(Graphics g) {
       final Color connectorsColor = new Color(0.3f, 0.3f, 1.0f);
       final Color parenthesesColor = new Color(0.0f, 0.8f, 0.0f);
       final Color parenthesesCourantesColor = new Color(0.2f, 0.5f, 0.0f);
       final Color parenthesesCourantesFondColor = new Color(1.0f, 0.8f, 0.0f);
       final Color errorColor = new Color(1.0f, 0.0f, 0.0f);
       

       Graphics2D g2 = (Graphics2D) g;
        Graphics2Dconfigure(g2);

        
        super.paintComponent(g);

        String s = getText();

        if(s.isEmpty() & !isFocusOwner() & isEditable())
        {
            g2.setColor(new Color(0.6f,0.6f,0.6f));
            drawStringOverlap(g2, "écris une formule ici (si tu veux)", 0);
        }

        for(int i = 0; i <= Math.min(200, s.length()); i++)
        {

            String textemotcle = s.substring(i);

            
            for(String motcle : motsClefs)
            {
                if(textemotcle.startsWith(motcle + " "))
                {
                g.setColor(connectorsColor);
                drawStringOverlap(g, motcle, i);
                 }
            }

            if(textemotcle.startsWith("("))
            {
                g.setColor(parenthesesColor);
                drawStringOverlap(g, "(", i);
            }

            if(textemotcle.startsWith(")"))
            {
                g.setColor(parenthesesColor);
                drawStringOverlap(g, ")", i);
            }


        }


        if(hasFocus())
        {
            Point p = coordonneesParenthesesSousFormuleCourante();

            if(p != null)
            {
                drawStringOverlapBackGroundColor(g, "(", p.x, parenthesesCourantesFondColor, parenthesesCourantesColor);
                drawStringOverlapBackGroundColor(g, ")", p.y, parenthesesCourantesFondColor, parenthesesCourantesColor);

            }
        }

        
        if(plageError != null)
        {
            surligner(g2, plageError, errorColor);
        }


    }







 
    public void doRepaint() {
        selectionnerChampSiBesoin();
        super.repaint();

        
    }


    /**
     * dire qu'il n'y a pas d'erreur
     */
    void noError() {
        plageError = null;
    }

    /**
     * l'erreur... c'est toute la formule
     */
    void errorAll() {
        plageError = new Point(0, getText().length() - 1);
    }


    /**
     * Dire qu'il y a une erreur au caractère numéro i
     * @param i
     */
    void error(int i) {
        plageError = new Point(i, i);
    }


/**
 * entame un affiche transparent
 * @param g2
 */
    private void drawTransparent(Graphics2D g2)
    {
        g2.setComposite(java.awt.AlphaComposite.getInstance(
                java.awt.AlphaComposite.SRC_OVER,Math.min(
                    0.5f, //0 transparent à fond,  1 = opaque
                    1.0f ) )) ;
    }


    private void surligner(Graphics2D g2, Point p, Color errorColor) {
        int h = getTextHeight(g2);
        int x1 = getX(g2, p.x);
        int x2 = getX(g2, p.y+1);

        g2.setColor(errorColor);
        drawTransparent(g2);
        g2.fillRect(x1, 0, x2 - x1, h);
    }

    @Override
    public Dimension getPreferredSize() {
        if(getTextWidth() < getWidth())
            return new Dimension(getTextWidth(), super.getPreferredSize().height);
        else
            return super.getPreferredSize();
    }


    @Override
    public Dimension getMinimumSize() {
        if(getTextWidth() < getWidth())
            return new Dimension(getTextWidth(), super.getMinimumSize().height);
        else
            return super.getMinimumSize();
    }












    
}
