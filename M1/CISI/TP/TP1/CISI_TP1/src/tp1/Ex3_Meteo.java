/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package tp1;

/**
 *
 * @author 21003495
 */
public class Ex3_Meteo extends javax.swing.JFrame {
    private enum States {Init, EMarche};
    
    /**
     * Creates new form Ex3_Meteo
     */
    public Ex3_Meteo() {
        initComponents();
        init();
    }
    private void stateMarche() {
        startButton.setEnabled(false);
        ticButton.setEnabled(true);
        stopButton.setEnabled(true);
    }
    
    private void stateInit() {
        startButton.setEnabled(true);
        ticButton.setEnabled(false);
        stopButton.setEnabled(false);   
        nbTics = 0;
    }
    
    private void displaySun() {
        text.setText("Soleil");
    }
    
    private void displayCloud() {
        text.setText("Nuages");
    }
    
    private void displayRain() {
        text.setText("Pluie");
    }
    
    private void afficherEclaires() {
        text.setText("Eclaires");
    }
    
    private void afficherPouf() {
        text.setText("Pouf");
    }
    
    private void afficherVide() {
        text.setText("");
    }
    private void init() {
        afficherVide();
        state = States.Init;
        stateInit();
    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jPanel1 = new javax.swing.JPanel();
        jPanel7 = new javax.swing.JPanel();
        filler8 = new javax.swing.Box.Filler(new java.awt.Dimension(0, 0), new java.awt.Dimension(0, 0), new java.awt.Dimension(32767, 0));
        text = new javax.swing.JLabel();
        filler9 = new javax.swing.Box.Filler(new java.awt.Dimension(0, 0), new java.awt.Dimension(0, 0), new java.awt.Dimension(32767, 0));
        jPanel2 = new javax.swing.JPanel();
        filler1 = new javax.swing.Box.Filler(new java.awt.Dimension(0, 0), new java.awt.Dimension(0, 0), new java.awt.Dimension(32767, 0));
        stopButton = new javax.swing.JButton();
        startButton = new javax.swing.JButton();
        ticButton = new javax.swing.JButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        jPanel1.setLayout(new java.awt.CardLayout());

        jPanel7.setLayout(new javax.swing.BoxLayout(jPanel7, javax.swing.BoxLayout.LINE_AXIS));
        jPanel7.add(filler8);

        text.setText("Label");
        jPanel7.add(text);
        jPanel7.add(filler9);

        jPanel1.add(jPanel7, "card6");

        getContentPane().add(jPanel1, java.awt.BorderLayout.CENTER);

        jPanel2.setLayout(new javax.swing.BoxLayout(jPanel2, javax.swing.BoxLayout.LINE_AXIS));
        jPanel2.add(filler1);

        stopButton.setText("Stop");
        stopButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                stopButtonActionPerformed(evt);
            }
        });
        jPanel2.add(stopButton);

        startButton.setText("Start");
        startButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                startButtonActionPerformed(evt);
            }
        });
        jPanel2.add(startButton);

        ticButton.setText("Tic");
        ticButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                ticButtonActionPerformed(evt);
            }
        });
        jPanel2.add(ticButton);

        getContentPane().add(jPanel2, java.awt.BorderLayout.SOUTH);

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void startButtonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_startButtonActionPerformed
        switch(state) {
            case Init:
                displaySun();
                stateMarche();
                state = States.EMarche;
                break;
            case EMarche:
                throw new RuntimeException("bad state");
        }
    }//GEN-LAST:event_startButtonActionPerformed

    private void ticButtonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_ticButtonActionPerformed
        switch(state) {
            case EMarche:
                if(nbTics == 0) {
                    displayCloud();
                    state = States.EMarche;
                } else if(nbTics == 1) {
                    displayRain();
                    state = States.EMarche;
                } else if(nbTics == 2) {
                    afficherEclaires();                      
                    state = States.EMarche;
                } else if(nbTics > 2) {
                    afficherPouf();
                    stateInit();
                    state = States.Init;
                }
                ++nbTics;
                break;
            case Init:
                throw new RuntimeException("bad state");
        }
    }//GEN-LAST:event_ticButtonActionPerformed

    private void stopButtonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_stopButtonActionPerformed
        switch(state) {
            case EMarche:
                nbTics = 0;
                init();
                break;
            case Init:
                throw new RuntimeException("bad state");
        }
    }//GEN-LAST:event_stopButtonActionPerformed

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
            java.util.logging.Logger.getLogger(Ex3_Meteo.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(Ex3_Meteo.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(Ex3_Meteo.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(Ex3_Meteo.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new Ex3_Meteo().setVisible(true);
            }
        });
    }
    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.Box.Filler filler1;
    private javax.swing.Box.Filler filler8;
    private javax.swing.Box.Filler filler9;
    private javax.swing.JPanel jPanel1;
    private javax.swing.JPanel jPanel2;
    private javax.swing.JPanel jPanel7;
    private javax.swing.JButton startButton;
    private javax.swing.JButton stopButton;
    private javax.swing.JLabel text;
    private javax.swing.JButton ticButton;
    // End of variables declaration//GEN-END:variables

    private States state;
    private int nbTics;
}
