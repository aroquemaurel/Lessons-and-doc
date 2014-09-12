/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package controle;

import individu.classe.Guerrier;
import java.rmi.RemoteException;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;
import static org.junit.Assert.*;

/**
 *
 * @author aroquemaurel
 */
public class ConsoleTest {
    IConsole _console;
    @Before
    public void setUp() throws RemoteException {
        _console = new Console(new Guerrier("truc"), 0, 0);
    }
    
    @After
    public void tearDown() {
    }


    /**
     * Test of seDirigerVers method, of class Console.
     */
    @Test
    public void testSeDirigerVers() {
        System.out.println("seDirigerVers");
        int ref = 0;
        Console instance = null;
        instance.seDirigerVers(ref);
        // TODO review the generated test code and remove the default call to fail.
        fail("The test case is a prototype.");
    }

    /**
     * Test of ramasserObjet method, of class Console.
     */
    @Test
    public void testRamasserObjet() throws Exception {
        System.out.println("ramasserObjet");
        IConsole objet = null;
        Console instance = null;
        instance.ramasserObjet(objet);
        // TODO review the generated test code and remove the default call to fail.
        fail("The test case is a prototype.");
    }

    
}
