package httpserver;

import java.io.File;
import java.net.ServerSocket;

class HttpServer 
{
    public static void main(String args[]) throws Exception {
        ServerSocket soc = new ServerSocket(5217);
        HttpThreadServer serv;
        File f = new File("./www-data");
        f.mkdir(); // Si www-data n'existe pas, on le créé !
        
        while(true) {
            serv = new HttpThreadServer(soc.accept());
            
            // FIXME Problèmes threads, provoque problème lors du put, lancement manuel du handler
            serv.run();
        }
    }
}
