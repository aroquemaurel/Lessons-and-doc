/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package satoulouse;

/**
 *
 * @author proprietaire
 */
public class Help {
    static public void show(String what)
    {
        DialogHelp dh = new DialogHelp(null, true);
        dh.page_show(what);
        dh.setVisible(true);
    }
}
