package ex1;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.ImageIcon;
import javax.swing.Timer;

/**
 *
 * @author aroquemaurel
 */
public class Ex1FrenchTricolor extends javax.swing.JFrame {
    private enum States {INIT, RED, GREEN, ORANGE, ONPANNE, OFFPANNE};
    
    /**
     * Creates new form Ex1FrenchTricolor
     */
    public Ex1FrenchTricolor() {
        initComponents();
        initRedTimer();
        initOrangeTimer();
        initGreenTimer();
        initOffPaneTimer();
        initOnPanneTimer();
        init();
    }

    private void init() {
        turnOffAll();
        state = States.INIT;
        initActivation();
    }
    
    private void turnOnOrange() {
        turnOffAll();
        orangeLabel.setIcon(new ImageIcon(getClass().getResource("/ex1/tricolor_orange.png")));        
    }
    
    private void turnOnGreen() {
        turnOffAll();
        greenLabel.setIcon(new ImageIcon(getClass().getResource("/ex1/tricolor_green.png")));        
    }
    
    private void turnOnRed() {
        turnOffAll();
        redLabel.setIcon(new ImageIcon(getClass().getResource("/ex1/tricolor_red.png")));
    }
    
    private void turnOffAll() {
        redLabel.setIcon(new ImageIcon(getClass().getResource("/ex1/tricolor_off.png")));
        greenLabel.setIcon(new ImageIcon(getClass().getResource("/ex1/tricolor_off.png")));
        orangeLabel.setIcon(new ImageIcon(getClass().getResource("/ex1/tricolor_off.png")));
    }
    
    private void initActivation() {
        onButton.setEnabled(true);
        offButton.setEnabled(false);
        panneButton.setEnabled(false);
        redTimer.stop();
        greenTimer.stop();
        orangeTimer.stop();
        onPanneTimer.stop();
        offPanneTimer.stop();
    }
    
    private void redActivation() {
        onButton.setEnabled(false);
        offButton.setEnabled(true);
        panneButton.setEnabled(true);        
        redTimer.start();
        orangeTimer.stop();
        greenTimer.stop();
        onPanneTimer.stop();
        offPanneTimer.stop();
    }
    
    private void greenActivation() {
        onButton.setEnabled(false);
        offButton.setEnabled(true);
        panneButton.setEnabled(true);               
        redTimer.stop();
        greenTimer.start();
        orangeTimer.stop();
        onPanneTimer.stop();
        offPanneTimer.stop();
    }
    
    private void orangeActivation() {
        onButton.setEnabled(false);
        offButton.setEnabled(true);
        panneButton.setEnabled(true);        
        redTimer.stop();
        greenTimer.stop();
        orangeTimer.start();
        onPanneTimer.stop();
        offPanneTimer.stop();
    }
    
    private void onPanneActivation() {
        onButton.setEnabled(false);
        offButton.setEnabled(true);
        panneButton.setEnabled(false);      
        onPanneTimer.start();
        offPanneTimer.stop();
        redTimer.stop();
        greenTimer.stop();
        orangeTimer.stop();
    }
    
    private void offPanneActivation() {
        onButton.setEnabled(false);
        offButton.setEnabled(true);
        panneButton.setEnabled(false);                
        onPanneTimer.stop();
        offPanneTimer.start();
        redTimer.stop();
        greenTimer.stop();
        orangeTimer.stop();

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
        redLabel = new javax.swing.JLabel();
        orangeLabel = new javax.swing.JLabel();
        greenLabel = new javax.swing.JLabel();
        jPanel1 = new javax.swing.JPanel();
        onButton = new javax.swing.JButton();
        panneButton = new javax.swing.JButton();
        offButton = new javax.swing.JButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setMinimumSize(new java.awt.Dimension(236, 200));

        jPanel2.setMinimumSize(new java.awt.Dimension(150, 200));
        jPanel2.setLayout(new java.awt.GridLayout(3, 1));

        redLabel.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        redLabel.setIcon(new javax.swing.ImageIcon(getClass().getResource("/ex1/tricolor_off.png"))); // NOI18N
        redLabel.setMaximumSize(new java.awt.Dimension(150, 150));
        redLabel.setMinimumSize(new java.awt.Dimension(150, 150));
        jPanel2.add(redLabel);

        orangeLabel.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        orangeLabel.setIcon(new javax.swing.ImageIcon(getClass().getResource("/ex1/tricolor_off.png"))); // NOI18N
        jPanel2.add(orangeLabel);

        greenLabel.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        greenLabel.setIcon(new javax.swing.ImageIcon(getClass().getResource("/ex1/tricolor_off.png"))); // NOI18N
        jPanel2.add(greenLabel);

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
                state = States.GREEN;
                turnOnGreen();
                greenActivation();
                break;
        }
    }

    private void greenTimerActionPerformed() {
        switch(state) {
            case GREEN:
                state = States.ORANGE;
                turnOnOrange();
                orangeActivation();
                break;
        }

    }

    private void orangeTimerActionPerformed() {
        switch(state) {
            case ORANGE:
                state = States.RED;
                turnOnRed();
                redActivation();
                break;
        }
    }                
    
    private void offPanneTimerActionPerformed() {
        switch(state) {
            case OFFPANNE:
                state = States.ONPANNE;
                turnOffAll();
                onPanneActivation();
                break;
        }
    }
    
    private void onPanneTimerActionPerformed() {
        switch(state) {
            case ONPANNE:
                state = States.OFFPANNE;
                turnOnOrange();
                offPanneActivation();
                break;
        }
    }
    
    private void onButtonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_onButtonActionPerformed
        switch(state) {
            case INIT:
                state = States.RED;
                turnOnRed();
                redActivation();
                break;
            case ORANGE:
            case RED:
            case GREEN:
            case ONPANNE:
            case OFFPANNE:
                throw new RuntimeException("Bad state !");
        }
    }//GEN-LAST:event_onButtonActionPerformed

    private void panneButtonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_panneButtonActionPerformed
        switch(state) {
            case ORANGE:
            case RED:
            case GREEN:
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
                state = States.RED;
                turnOnRed();
                redActivation();
                break;
            case ORANGE:
            case RED:
            case GREEN:
            case ONPANNE:
            case OFFPANNE:
                throw new RuntimeException("Bad state !");            
        }
    }//GEN-LAST:event_offButtonActionPerformed

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
            java.util.logging.Logger.getLogger(Ex1FrenchTricolor.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(Ex1FrenchTricolor.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(Ex1FrenchTricolor.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(Ex1FrenchTricolor.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new Ex1FrenchTricolor().setVisible(true);
            }
        });
    }
    
    
    private void initRedTimer() {
            redTimer = new Timer(1000, new ActionListener() {
 
            @Override
            public void actionPerformed(ActionEvent e) {
                redTimerActionPerformed();
            }          
        });
    
    }
    
    private void initOrangeTimer() {
        orangeTimer = new Timer(1000, new ActionListener() {
 
            @Override
            public void actionPerformed(ActionEvent e) {
                orangeTimerActionPerformed();
            }          
             
        });

    }
    
    private void initGreenTimer() {
            greenTimer = new Timer(1000, new ActionListener() {
 
            @Override
            public void actionPerformed(ActionEvent e) {
                greenTimerActionPerformed();
            }          
             
        });
    
    }
    
    private void initOnPanneTimer() {
        onPanneTimer = new Timer(1000, new ActionListener() {
 
            @Override
            public void actionPerformed(ActionEvent e) {
                onPanneTimerActionPerformed();
            }          
             
        });
 
    }
    
    private void initOffPaneTimer() {
        offPanneTimer = new Timer(1000, new ActionListener() {
 
            @Override
            public void actionPerformed(ActionEvent e) {
                offPanneTimerActionPerformed();
            }          
             
        });
    }
    private States state;
    private Timer redTimer;
    private Timer orangeTimer;
    private Timer greenTimer;
    private Timer onPanneTimer;
    private Timer offPanneTimer;
    
    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JLabel greenLabel;
    private javax.swing.JPanel jPanel1;
    private javax.swing.JPanel jPanel2;
    private javax.swing.JButton offButton;
    private javax.swing.JButton onButton;
    private javax.swing.JLabel orangeLabel;
    private javax.swing.JButton panneButton;
    private javax.swing.JLabel redLabel;
    // End of variables declaration//GEN-END:variables
}