/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package httpserver;

import java.io.IOException;
import java.net.Socket;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author aroquemaurel
 */
public class HttpThreadServer implements Runnable {
    private Thread _thread;
    private final Socket _socket;

    HttpThreadServer(Socket s) {
        _socket = s;
        
        // FIXME → Provoque problème lors du put… ?
        //_thread = new Thread(this);
        //_thread.start();
  }

    @Override
    public void run() {
        try {
            HttpRequest request = new HttpRequest(_socket);
            request.process();
        } catch (Exception ex) {
            Logger.getLogger(HttpThreadServer.class.getName()).log(Level.SEVERE, null, ex);
        } finally {
            try {
                _socket.close();
            } catch (IOException ex) {
                Logger.getLogger(HttpThreadServer.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
    }
    
}
