/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package satoulouse;

/**
 * Cette classe "statique" permet de mesurer le temps d'exécution d'un bloc
 * d'instructions
 * utilisation :
 * - Chronometre.tickDebut()
 * -...  code dont on veut mesurer le temps
 * - Chronometre.printDuree()
 * @author François Schwarzentruber
 */
public class Chronometre {

    /*stocke le temps de début*/
    static long start = 0;


    /**
     * imprime dans la console le temps depuis tickDebut
     */
    public static void printDuree() {
        System.out.println(getTempsMilliSecondes() + " ms!");
    }


    /**
     * débute le chronomètre
     */
    public static void tickDebut()
    {
        start =  System.currentTimeMillis();
    }

/**
 *
 * @return le temps en ms depuis le début du chronomètre
 */
    public static long getTempsMilliSecondes()
    {
        return System.currentTimeMillis() - start ;
    }

}
