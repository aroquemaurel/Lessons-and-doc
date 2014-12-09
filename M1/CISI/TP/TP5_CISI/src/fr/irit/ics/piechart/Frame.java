package fr.irit.ics.piechart;

import fr.irit.ics.piechart.models.Model;

/**
 *
 * @author aroquemaurel
 */
public class Frame extends javax.swing.JFrame {

    private enum States {
        INIT, OK, NO_UP, EDITING, DOWN, NO_DOWN
    };

    /**
     * Creates new form Frame
     */
    public Frame() {
        initComponents();
        init();
    }

    private void init() {
        state = States.INIT;
        model = new Model();
        model.addView(pieChartView1);
        model.addView(jTextFieldPercent1);
    }

    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jPanel1 = new javax.swing.JPanel();
        upButton = new javax.swing.JButton();
        filler6 = new javax.swing.Box.Filler(new java.awt.Dimension(0, 10), new java.awt.Dimension(0, 10), new java.awt.Dimension(32767, 10));
        downButton = new javax.swing.JButton();
        filler1 = new javax.swing.Box.Filler(new java.awt.Dimension(0, 0), new java.awt.Dimension(0, 0), new java.awt.Dimension(0, 32767));
        jPanel3 = new javax.swing.JPanel();
        filler7 = new javax.swing.Box.Filler(new java.awt.Dimension(10, 0), new java.awt.Dimension(10, 0), new java.awt.Dimension(10, 32767));
        jTextFieldPercent1 = new fr.irit.ics.piechart.views.JTextFieldPercent();
        jLabel1 = new javax.swing.JLabel();
        filler3 = new javax.swing.Box.Filler(new java.awt.Dimension(0, 0), new java.awt.Dimension(0, 0), new java.awt.Dimension(0, 32767));
        jPanel2 = new javax.swing.JPanel();
        filler5 = new javax.swing.Box.Filler(new java.awt.Dimension(10, 0), new java.awt.Dimension(10, 0), new java.awt.Dimension(10, 32767));
        startButton = new javax.swing.JButton();
        filler4 = new javax.swing.Box.Filler(new java.awt.Dimension(10, 0), new java.awt.Dimension(10, 0), new java.awt.Dimension(10, 32767));
        stopButton = new javax.swing.JButton();
        filler2 = new javax.swing.Box.Filler(new java.awt.Dimension(0, 0), new java.awt.Dimension(0, 0), new java.awt.Dimension(0, 0));
        pieChartView1 = new fr.irit.ics.piechart.views.PieChartView();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        jPanel1.setMaximumSize(new java.awt.Dimension(124, 32817));
        jPanel1.setLayout(new javax.swing.BoxLayout(jPanel1, javax.swing.BoxLayout.PAGE_AXIS));

        upButton.setText("  Up   ");
        upButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                upButtonActionPerformed(evt);
            }
        });
        jPanel1.add(upButton);
        jPanel1.add(filler6);

        downButton.setText("Down");
        downButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                downButtonActionPerformed(evt);
            }
        });
        jPanel1.add(downButton);
        jPanel1.add(filler1);

        jPanel3.setMaximumSize(new java.awt.Dimension(150, 20));
        jPanel3.setLayout(new javax.swing.BoxLayout(jPanel3, javax.swing.BoxLayout.LINE_AXIS));
        jPanel3.add(filler7);

        jTextFieldPercent1.addKeyListener(new java.awt.event.KeyAdapter() {
            public void keyPressed(java.awt.event.KeyEvent evt) {
                jTextFieldPercent1KeyPressed(evt);
            }
        });
        jPanel3.add(jTextFieldPercent1);

        jLabel1.setText("%");
        jPanel3.add(jLabel1);

        jPanel1.add(jPanel3);
        jPanel1.add(filler3);

        getContentPane().add(jPanel1, java.awt.BorderLayout.EAST);

        jPanel2.setLayout(new javax.swing.BoxLayout(jPanel2, javax.swing.BoxLayout.LINE_AXIS));
        jPanel2.add(filler5);

        startButton.setText("Start");
        startButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                startButtonActionPerformed(evt);
            }
        });
        jPanel2.add(startButton);
        jPanel2.add(filler4);

        stopButton.setText("Stop");
        stopButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                stopButtonActionPerformed(evt);
            }
        });
        jPanel2.add(stopButton);
        jPanel2.add(filler2);

        getContentPane().add(jPanel2, java.awt.BorderLayout.SOUTH);

        javax.swing.GroupLayout pieChartView1Layout = new javax.swing.GroupLayout(pieChartView1);
        pieChartView1.setLayout(pieChartView1Layout);
        pieChartView1Layout.setHorizontalGroup(
            pieChartView1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 313, Short.MAX_VALUE)
        );
        pieChartView1Layout.setVerticalGroup(
            pieChartView1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 275, Short.MAX_VALUE)
        );

        getContentPane().add(pieChartView1, java.awt.BorderLayout.CENTER);

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void upButtonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_upButtonActionPerformed
        switch (state) {
            case INIT:
                break;
            case OK:
                break;
            case NO_UP:
                break;
            case EDITING:
                break;
            case DOWN:
                break;
            case NO_DOWN:
                break;
            default:
                throw new AssertionError(state.name());

        }
    }//GEN-LAST:event_upButtonActionPerformed

    private void downButtonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_downButtonActionPerformed
        switch (state) {
            case OK:
                state = States.OK;
                //treatmentBtnDownOK();
                break;
            case EDITING:
            case INIT:
            case NO_DOWN:
            case DOWN:
            case NO_UP:
            default:
                throw new RuntimeException("bad state");

        }
    }//GEN-LAST:event_downButtonActionPerformed

    private void startButtonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_startButtonActionPerformed
        switch (state) {
            case INIT:
                break;
            case OK:
            case NO_UP:
            case EDITING:
            case DOWN:
            case NO_DOWN:
            default:
                throw new RuntimeException("Bad state");

        }
    }//GEN-LAST:event_startButtonActionPerformed

    private void stopButtonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_stopButtonActionPerformed
        switch(state) {
               case NO_DOWN:
                       state = States.INIT;
                     //  initValue();
                       break;
               case NO_UP:
                       state = States.INIT;
                     //  initValue();
                       break;
               case OK:
                     //  initValue();
                       break;
               case EDITING:
                case INIT:
                case DOWN:
                       throw new RuntimeException("bad state");
       }
    }//GEN-LAST:event_stopButtonActionPerformed

    private void jTextFieldPercent1KeyPressed(java.awt.event.KeyEvent evt) {//GEN-FIRST:event_jTextFieldPercent1KeyPressed
        // TODO add your handling code here:
    }//GEN-LAST:event_jTextFieldPercent1KeyPressed

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
            java.util.logging.Logger.getLogger(Frame.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(Frame.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(Frame.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(Frame.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new Frame().setVisible(true);
            }
        });
    }

    private States state;
    private Model model;

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton downButton;
    private javax.swing.Box.Filler filler1;
    private javax.swing.Box.Filler filler2;
    private javax.swing.Box.Filler filler3;
    private javax.swing.Box.Filler filler4;
    private javax.swing.Box.Filler filler5;
    private javax.swing.Box.Filler filler6;
    private javax.swing.Box.Filler filler7;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JPanel jPanel1;
    private javax.swing.JPanel jPanel2;
    private javax.swing.JPanel jPanel3;
    private fr.irit.ics.piechart.views.JTextFieldPercent jTextFieldPercent1;
    private fr.irit.ics.piechart.views.PieChartView pieChartView1;
    private javax.swing.JButton startButton;
    private javax.swing.JButton stopButton;
    private javax.swing.JButton upButton;
    // End of variables declaration//GEN-END:variables
}
