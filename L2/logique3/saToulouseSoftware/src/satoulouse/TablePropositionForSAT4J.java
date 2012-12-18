/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package satoulouse;

import java.util.HashMap;
import java.util.Map;

/**
 * Cette classe représente une association Proposition en texte <---> entier.
 * C'est utile pour SAT4J.
 * @author François Schwarzentruber
 */
public class TablePropositionForSAT4J {


    private int entierSuivantNonAttribue = 1;

    /**
     * table qui à chaque nom de proposition associe un entier
     */
    private Map<String, Integer> vartoint = new HashMap<String, Integer>();

    /**
     * table inverse qui à chaque entier associe le nom de la proposition associée
     */
    private Map<Integer, String> inttovar = new HashMap<Integer, String>();


/**
 * ajoute une proposition
 *
 * exemple :
 * put("p")
 * put("hiver")
 * put("(p 1 2 3)")
 * etc.
 * @param proposition
 */
    void put(String proposition)
    {
        entierSuivantNonAttribue++;
        vartoint.put(proposition, entierSuivantNonAttribue);
        inttovar.put(entierSuivantNonAttribue, proposition);
    }


/**
 *
 * @param proposition
 * @return le numéro de la proposition. Si la proposition n'est pas enregistré dans
 * la table cette fonction rajoute la proposition dans la table et lui affecte
 * un nouveau numéro
 */
    public int getIntegerProposition(String proposition)
    {
        Integer i = vartoint.get(proposition);
        //if(numero == null)
        //    System.out.println("proposition " + proposition + " non trouvé");
        if(i == null)
        {
            put(proposition);
            return entierSuivantNonAttribue;
        }
        else
            return i;
    }


    /**
     *
     * @param litteral
     * @return le numéro du litteral.
     * Si le litteral est positif, c'est le nombre positif qui représente la proposition en question
     * Si le littéral est négatif (ie de la forme "(not ....)", c'est l'opposé du nombre qui représente la proposition en question
     * Si jamais la proposition présente dans le littéral n'est pas présente dans la table
     * cette fonction rajoute la proposition dans la table et lui affecte un numéro
     */
    public int getIntegerLitteral(String litteral)
    {
        Integer i;
        if(litteral.startsWith("(not "))
            return - getIntegerProposition(litteral.substring(5, litteral.length() - 1));
        else
            return getIntegerProposition(litteral);

        
    }

/**
 *
 * @param numero
 * @return donne la proposition dont le numéro est numero
 * Si jamais le numéro ne correspond à aucune proposition,
 * la fonction affiche un message d'erreur dans la console et fait un message
 * d'erreur
 */
    public String getProposition(int numero)
    {
        String proposition = inttovar.get(numero);
        if(proposition == null)
            System.out.println("proposition n°" + numero + " non trouvé");
        return inttovar.get(numero);
    }


    /**
     *
     * @return le nombre de propositions enregistrées dans la table
     */
    int getNbPropositions() {
        return vartoint.size();
    }

}
