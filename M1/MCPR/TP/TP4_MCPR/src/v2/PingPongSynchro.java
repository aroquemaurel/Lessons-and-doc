package v2;

public class PingPongSynchro {
    public static void main(String[] args)  {
        int nbPlayerPing = 2;
        int nbPlayerPong = 2;

        MoniteurTable table = new MoniteurTable();
        Player[] players = new Player[nbPlayerPing + nbPlayerPong];

        for (int i = 0; i < nbPlayerPing; i++){
            players[i] = new Player(0, i, table);
            players[i].start();
        }

        for (int i = nbPlayerPing; i < nbPlayerPing+nbPlayerPong; i++){
            players[i] = new Player(1, i, table);
            players[i].start();
        }
    }
}
