package ex3;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.Timer;

/**
 *
 * @author aroquemaurel
 */
public class AustriaTrafficLight extends javax.swing.JFrame {
    private enum States {INIT, RED, ORANGE, RED_ORANGE, GREEN, ONPANNE, OFFPANNE, GREEN_BLINK_OFF, GREEN_BLINK_ON};
    
    /**
     * Creates new form AustriaTrafficLight
     */
    public AustriaTrafficLight() {
        initComponents();
        initRedTimer();
        initOrangeTimer();
        initGreenBlinkOnTimer();
        initRedOrangeTimer();
        initOffPaneTimer();
        initOnPanneTimer();
        initGreenBlinkOffTimer();
        initGreenTimer();
        init();
    }

    private void init() {
        turnOffAll();
        state = States.INIT;
        initActivation();
    }
    
    private void turnOnOrange() {
        turnOffAll();
        orangeTrafficLight.turnOnOrange();
    }
    
    private void turnOnGreen() {
        turnOffAll();
        greenTrafficLight.turnOnGreen();
    }
    
    private void turnOnRed() {
        turnOffAll();
        redTrafficLight.turnOnRed();
    }
    
    private void turnOnRedOrange() {
        turnOffAll();
        redTrafficLight.turnOnRed();
        orangeTrafficLight.turnOnOrange();
    }
    
    private void turnOffAll() {
        redTrafficLight.turnOff();
        orangeTrafficLight.turnOff();
        greenTrafficLight.turnOff();
    }
    
    private void initActivation() {
        onButton.setEnabled(true);
        offButton.setEnabled(false);
        panneButton.setEnabled(false);
        redTimer.stop();
        greenOnBlinkTimer.stop();
        orangeTimer.stop();
        onPanneTimer.stop();
        offPanneTimer.stop();
        redOrangeTimer.stop();
    }
    
    private void redActivation() {
        onButton.setEnabled(false);
        offButton.setEnabled(true);
        panneButton.setEnabled(true);        
        redTimer.start();
        orangeTimer.stop();
        greenOnBlinkTimer.stop();
        greenOffBlinkTimer.stop();
        onPanneTimer.stop();
        offPanneTimer.stop();
        redOrangeTimer.stop();
    }
    
    private void greenBlinkOnActivation() {
        onButton.setEnabled(false);
        offButton.setEnabled(true);
        panneButton.setEnabled(true);               
        redTimer.stop();
        greenOnBlinkTimer.start();
        greenOffBlinkTimer.stop();
        orangeTimer.stop();
        onPanneTimer.stop();
        offPanneTimer.stop();
        redOrangeTimer.stop();
        greenTimer.stop();
        
    }
    private void greenBlinkOffActivation() {
        onButton.setEnabled(false);
        offButton.setEnabled(true);
        panneButton.setEnabled(true);               
        redTimer.stop();
        greenOnBlinkTimer.stop();
        greenOffBlinkTimer.start();
        orangeTimer.stop();
        onPanneTimer.stop();
        offPanneTimer.stop();
        redOrangeTimer.stop();
        greenTimer.stop();
    }    
    
    private void orangeActivation() {
        onButton.setEnabled(false);
        offButton.setEnabled(true);
        panneButton.setEnabled(true);        
        redTimer.stop();
        greenOnBlinkTimer.stop();
        greenOffBlinkTimer.stop();
        orangeTimer.start();
        onPanneTimer.stop();
        offPanneTimer.stop();
        redOrangeTimer.stop();
        greenTimer.stop();
    }
    
    private void redOrangeActivation() {
        onButton.setEnabled(false);
        offButton.setEnabled(true);
        panneButton.setEnabled(true);        
        redTimer.stop();
        greenOnBlinkTimer.stop();
        greenOffBlinkTimer.stop();
        orangeTimer.stop();
        onPanneTimer.stop();
        offPanneTimer.stop();
        redOrangeTimer.start();
        greenTimer.stop();
    }
    
    private void onPanneActivation() {
        onButton.setEnabled(true);
        offButton.setEnabled(true);
        panneButton.setEnabled(false);      
        onPanneTimer.start();
        offPanneTimer.stop();
        redTimer.stop();
        greenOnBlinkTimer.stop();
        greenOffBlinkTimer.stop();
        orangeTimer.stop();
        redOrangeTimer.stop();
        greenTimer.stop();
    }
    
    private void greenActivation() {
       onButton.setEnabled(false);
        offButton.setEnabled(true);
        panneButton.setEnabled(true);        
        redTimer.stop();
        greenOnBlinkTimer.start();
        greenOffBlinkTimer.stop();
        orangeTimer.stop();
        onPanneTimer.stop();
        offPanneTimer.stop();
        redOrangeTimer.stop();
        greenTimer.start();
    }
    
    private void offPanneActivation() {
        onButton.setEnabled(true);
        offButton.setEnabled(true);
        panneButton.setEnabled(false);                
        onPanneTimer.stop();
        offPanneTimer.start();
        redTimer.stop();
        greenOnBlinkTimer.stop();
        greenOffBlinkTimer.stop();        
        orangeTimer.stop();
        redOrangeTimer.stop();
    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jPanel2 = new javax.swing.JPanel();
        redTrafficLight = new tricolors.TrafficLight();
        orangeTrafficLight = new tricolors.TrafficLight();
        greenTrafficLight = new tricolors.TrafficLight();
        jPanel1 = new javax.swing.JPanel();
        onButton = new javax.swing.JButton();
        panneButton = new javax.swing.JButton();
        offButton = new javax.swing.JButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setMinimumSize(new java.awt.Dimension(250, 480));

        jPanel2.setMinimumSize(new java.awt.Dimension(150, 200));
        jPanel2.setLayout(new java.awt.GridLayout(3, 1));

        javax.swing.GroupLayout redTrafficLightLayout = new javax.swing.GroupLayout(redTrafficLight);
        redTrafficLight.setLayout(redTrafficLightLayout);
        redTrafficLightLayout.setHorizontalGroup(
            redTrafficLightLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 400, Short.MAX_VALUE)
        );
        redTrafficLightLayout.setVerticalGroup(
            redTrafficLightLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 166, Short.MAX_VALUE)
        );

        jPanel2.add(redTrafficLight);

        javax.swing.GroupLayout orangeTrafficLightLayout = new javax.swing.GroupLayout(orangeTrafficLight);
        orangeTrafficLight.setLayout(orangeTrafficLightLayout);
        orangeTrafficLightLayout.setHorizontalGroup(
            orangeTrafficLightLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 400, Short.MAX_VALUE)
        );
        orangeTrafficLightLayout.setVerticalGroup(
            orangeTrafficLightLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 166, Short.MAX_VALUE)
        );

        jPanel2.add(orangeTrafficLight);

        javax.swing.GroupLayout greenTrafficLightLayout = new javax.swing.GroupLayout(greenTrafficLight);
        greenTrafficLight.setLayout(greenTrafficLightLayout);
        greenTrafficLightLayout.setHorizontalGroup(
            greenTrafficLightLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 400, Short.MAX_VALUE)
        );
        greenTrafficLightLayout.setVerticalGroup(
            greenTrafficLightLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 166, Short.MAX_VALUE)
        );

        jPanel2.add(greenTrafficLight);

        getContentPane().add(jPanel2, java.awt.BorderLayout.CENTER);

        jPanel1.setLayout(new javax.swing.BoxLayout(jPanel1, javax.swing.BoxLayout.PAGE_AXIS));

        onButton.setText("Marche");
        onButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                onButtonActionPerformed(evt);
            }
        });
        jPanel1.add(onButton);

        panneButton.setText("Panne");
        panneButton.setMaximumSize(new java.awt.Dimension(86, 25));
        panneButton.setMinimumSize(new java.awt.Dimension(86, 25));
        panneButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                panneButtonActionPerformed(evt);
            }
        });
        jPanel1.add(panneButton);

        offButton.setText("Arrêt");
        offButton.setMaximumSize(new java.awt.Dimension(86, 25));
        offButton.setMinimumSize(new java.awt.Dimension(86, 25));
        offButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                offButtonActionPerformed(evt);
            }
        });
        jPanel1.add(offButton);

        getContentPane().add(jPanel1, java.awt.BorderLayout.EAST);

        pack();
    }// </editor-fold>//GEN-END:initComponents
    private void redTimerActionPerformed() {
        switch(state) {
            case RED:
                state = States.RED_ORANGE;
                turnOnRedOrange();
                redOrangeActivation();
                break;
            case ONPANNE:
            case OFFPANNE:
            case ORANGE:
            case GREEN_BLINK_OFF:
            case GREEN_BLINK_ON:
            case GREEN:
            case INIT:
            case RED_ORANGE:                
                throw new RuntimeException("bad state");                                
        }
    }

    private void greenBlinkOnTimerActionPerformed() {
        switch(state) {
            case GREEN_BLINK_ON:
                if(nbTics < 4) {
                    state = States.GREEN_BLINK_OFF;    
                    turnOffAll();    
                    greenBlinkOffActivation();
                } else {
                    state = States.ORANGE;
                    turnOnOrange();;
                    orangeActivation();
                }
                break;
            case ONPANNE:
            case OFFPANNE:
            case RED:
            case ORANGE:
            case INIT:
            case RED_ORANGE:
            case GREEN_BLINK_OFF:
            case GREEN:
                throw new RuntimeException("bad state");                                
        }

    }

    private void orangeTimerActionPerformed() {
        switch(state) {
            case ORANGE:
                state = States.RED;
                turnOnRed();
                redActivation();
                break;
            case ONPANNE:
            case OFFPANNE:
            case RED:
            case GREEN_BLINK_OFF:
            case GREEN_BLINK_ON:
            case GREEN:
            case INIT:
            case RED_ORANGE:
                throw new RuntimeException("bad state");                
        }
    }                
    
    private void redOrangeTimerActionPerformed() {
        switch(state) {
            case RED_ORANGE:
                state = States.GREEN;
                turnOnGreen();
                greenActivation();
                break;
            case ORANGE:
            case ONPANNE:
            case OFFPANNE:
            case RED:
            case GREEN_BLINK_OFF:
            case GREEN_BLINK_ON:
            case GREEN:
            case INIT:
                throw new RuntimeException("bad state");                
        }

    }

    private void offPanneTimerActionPerformed() {
        switch(state) {
            case OFFPANNE:
                state = States.ONPANNE;
                turnOnOrange();
                onPanneActivation();
                break;
            case ORANGE:
            case ONPANNE:
            case RED:
            case GREEN_BLINK_OFF:
            case GREEN_BLINK_ON:
            case GREEN:
            case INIT:
                throw new RuntimeException("bad state");
        }
    }
    private void greenBlinkOffTimerActionPerformed() {
      switch(state) {
            case GREEN_BLINK_OFF:
                state = States.GREEN_BLINK_ON;
                ++nbTics;
                turnOnGreen();
                greenBlinkOnActivation();
                break;
            case GREEN_BLINK_ON:
            case GREEN:
            case ONPANNE:
            case ORANGE:
            case OFFPANNE:
            case RED:
            case INIT:
                throw new RuntimeException("bad state");
      }
    }
    
    private void onPanneTimerActionPerformed() {
        switch(state) {
            case ONPANNE:
                state = States.OFFPANNE;
                turnOffAll();
                offPanneActivation();
                break;
            case ORANGE:
            case OFFPANNE:
            case RED:
            case GREEN:
            case GREEN_BLINK_OFF:
            case GREEN_BLINK_ON:
            case INIT:
                throw new RuntimeException("bad state");
        }
    }
    
    private void onButtonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_onButtonActionPerformed
        switch(state) {
            case INIT:
            case ONPANNE:
            case OFFPANNE:
                state = States.RED;
                turnOnRed();
                redActivation();
                break;
            case ORANGE:
            case RED:
            case GREEN:
            case GREEN_BLINK_OFF:
            case GREEN_BLINK_ON:
                throw new RuntimeException("Bad state !");
        }
    }//GEN-LAST:event_onButtonActionPerformed
        
    private void panneButtonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_panneButtonActionPerformed
        switch(state) {
            case ORANGE:
            case RED:
            case GREEN:
            case GREEN_BLINK_OFF:
            case GREEN_BLINK_ON:
                state = States.ONPANNE;
                turnOnOrange();                
                onPanneActivation();
                break;            
            case ONPANNE:
            case OFFPANNE:
            case INIT:
                throw new RuntimeException("Bad state !");            
        }
    }//GEN-LAST:event_panneButtonActionPerformed
    
    private void offButtonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_offButtonActionPerformed
        switch(state) {
            case INIT:
                throw new RuntimeException("Bad state !");            
            case ORANGE:
            case RED:
            case GREEN_BLINK_OFF:
            case GREEN_BLINK_ON:
            case GREEN:
            case ONPANNE:
            case OFFPANNE:
                state = States.INIT;
                turnOffAll();
                initActivation();
        }
    }//GEN-LAST:event_offButtonActionPerformed

    private void greenTimerActionPerformed() {
        switch(state) {
            case GREEN:
                state = States.GREEN_BLINK_OFF;
                nbTics = 0;
                turnOffAll();
                greenBlinkOffActivation();
                break;
            case INIT:
            case ONPANNE:
            case OFFPANNE:
            case ORANGE:
            case RED:
            case GREEN_BLINK_OFF:
            case GREEN_BLINK_ON:
                throw new RuntimeException("Bad state !");
        }
    }
    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        /* Set the Nimbus look and feel */
        //<editor-fold defaultstate="collapsed" desc=" Look and feel setting code (optional) ">
        /* If Nimbus (introduced in Java SE 6) is not available, stay with the default look and feel.
         * For details see http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html 
         */
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(AustriaTrafficLight.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(AustriaTrafficLight.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(AustriaTrafficLight.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(AustriaTrafficLight.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>
        //</editor-fold>
        //</editor-fold>
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new AustriaTrafficLight().setVisible(true);
            }
        });
    }
    
    
    private void initRedTimer() {
            redTimer = new Timer(RED_TIME, new ActionListener() {
 
            @Override
            public void actionPerformed(ActionEvent e) {
                redTimerActionPerformed();
            }          
        });
    
    }
    
    private void initOrangeTimer() {
        orangeTimer = new Timer(ORANGE_TIME, new ActionListener() {
 
            @Override
            public void actionPerformed(ActionEvent e) {
                orangeTimerActionPerformed();
            }          
             
        });
    }
    private void initRedOrangeTimer() {
        redOrangeTimer = new Timer(RED_ORANGE_TIME, new ActionListener() {
 
            @Override
            public void actionPerformed(ActionEvent e) {
                redOrangeTimerActionPerformed();
            }          
             
        });
    }
    private void initGreenBlinkOnTimer() {
            greenOnBlinkTimer = new Timer(GREEN_BLINK_ON_TIME, new ActionListener() {
 
            @Override
            public void actionPerformed(ActionEvent e) {
                greenBlinkOnTimerActionPerformed();
            }          
             
        });
    }
    private void initGreenBlinkOffTimer() {
            greenOffBlinkTimer = new Timer(GREEN_BLINK_OFF_TIME, new ActionListener() {
 
            @Override
            public void actionPerformed(ActionEvent e) {
                greenBlinkOffTimerActionPerformed();
            }          
             
        });
    }
    private void initOnPanneTimer() {
        onPanneTimer = new Timer(PANNE_ON_TIME, new ActionListener() {
 
            @Override
            public void actionPerformed(ActionEvent e) {
                onPanneTimerActionPerformed();
            }          
             
        });
    }
    private void initGreenTimer() {
        greenTimer = new Timer(GREEN_TIME, new ActionListener() {
 
            @Override
            public void actionPerformed(ActionEvent e) {
                greenTimerActionPerformed();
            }          
             
        });
    }    
    private void initOffPaneTimer() {
        offPanneTimer = new Timer(PANNE_OFF_TIME, new ActionListener() {
 
            @Override
            public void actionPerformed(ActionEvent e) {
                offPanneTimerActionPerformed();
            }          
             
        });
    }
    private States state;
    private Timer redTimer;
    private Timer orangeTimer;
    private Timer greenOnBlinkTimer;
    private Timer onPanneTimer;
    private Timer offPanneTimer;
    private Timer redOrangeTimer;
    private Timer greenOffBlinkTimer;
    private Timer greenTimer;
    
    private final int RED_TIME = 2000;
    private final int ORANGE_TIME = 500;
    private final int GREEN_BLINK_OFF_TIME = 500;
    private final int RED_ORANGE_TIME = 1000;
    private final int GREEN_BLINK_ON_TIME = 500;
    private final int GREEN_TIME = 1500;
    private final int PANNE_ON_TIME = 600;
    private final int PANNE_OFF_TIME = 400;
    
    private int nbTics;
    
    // Variables declaration - do not modify//GEN-BEGIN:variables
    private tricolors.TrafficLight greenTrafficLight;
    private javax.swing.JPanel jPanel1;
    private javax.swing.JPanel jPanel2;
    private javax.swing.JButton offButton;
    private javax.swing.JButton onButton;
    private tricolors.TrafficLight orangeTrafficLight;
    private javax.swing.JButton panneButton;
    private tricolors.TrafficLight redTrafficLight;
    // End of variables declaration//GEN-END:variables
}
