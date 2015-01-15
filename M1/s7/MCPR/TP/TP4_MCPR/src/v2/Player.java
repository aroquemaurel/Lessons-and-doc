package v2;

import java.util.logging.Level;
import java.util.logging.Logger;

public class Player extends Thread {
    private final int type;
    private final int number;
    private final MoniteurTable table;

    public Player(int playerType, int playerNumber, MoniteurTable playerTable) {
        type = playerType;
        number = playerNumber;
        table = playerTable;
        System.out.println("Joueur " + type + " numéro " + number);
    }

    @Override
    public void run() {
        int i;
        for (i = 0; i < 10; i++) {
            try {
                table.accessToTable(type);
            } catch (InterruptedException ex) {
                Logger.getLogger(Player.class.getName()).log(Level.SEVERE, null, ex);
            }
            System.out.println("Joueur " + number + " : " + (type == 1 ? "PING" : "PONG"));
            table.freeTable();
        }
    }
}