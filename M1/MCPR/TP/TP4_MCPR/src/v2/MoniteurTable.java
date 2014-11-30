/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package v2;

/**
 *
 * @author
 */
import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.ReentrantLock;

public class MoniteurTable {
    private final ReentrantLock locker;
    private final Condition[] canPlay;
    private int lastPlayer = 0; 
    private boolean busy = false;

    public MoniteurTable() {
        locker = new ReentrantLock();
        canPlay = new Condition[2];
        canPlay[0] = locker.newCondition();
        canPlay[1] = locker.newCondition();
    }

    public void accessToTable(int playerType) throws InterruptedException {
        locker.lock();
        try {
            while ((playerType == lastPlayer) || busy) {
                canPlay[playerType].await();
            }
            busy = true;
            lastPlayer = playerType;
        } finally {
            locker.unlock();
        }
    }

    public void freeTable() {
        locker.lock();
        try {
            canPlay[(lastPlayer + 1) % 2].signal();
            busy = false;
        } finally {
            locker.unlock();
        }
    }
}