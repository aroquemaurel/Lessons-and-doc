package exercice2;

import java.awt.Point;
import java.awt.event.KeyEvent;
import javax.swing.SwingUtilities;

/**
 *
 * @author florent
 */
public class GimplessFrameRubberBanding extends javax.swing.JFrame {
    private enum States {
        WAIT, ONE_CLICK, CLICKS
    };

    public GimplessFrameRubberBanding() {
        initComponents();
        init();
    }

    private void init() {
        state = States.WAIT;
        nbClics = 0;
        panelDraw.init();
    }

    private void drawRedLines() {
        clean();
    }

    private void drawBlackLines() {
        clean();
    }

    private void storePolyline() {
        panelDraw.storePolyline();
    }

    private void addPoint(Point p) {
        panelDraw.addPoint(p);
    }

    private void removePoint() {
        panelDraw.removePoint();
    }

    private void clean() {
        panelDraw.clean();
    }

    private void drawGhost(Point p) {
        panelDraw.setGhost(p);
    }

    private void treatmentRightClickWait() {
        nbClics = 0;
    }

    private void treatmentRightClicOneClick() {
        nbClics = 0;
        removePoint();
        clean();
        drawRedLines();
    }

    private void treatmentRightClicks(Point p) {
        if (nbClics > 2) {
            state = States.CLICKS;
            nbClics--;
            removePoint();
            drawGhost(p);
            clean();
            drawRedLines();
            drawBlackLines();
        } else {
            state = States.ONE_CLICK;
            nbClics--;
            removePoint();
            drawGhost(p);
            drawRedLines();
            drawBlackLines();
        }

    }

    private void treatmentLeftClickWait(Point p) {
        nbClics = 1;
        addPoint(p);
    }

    private void treatmentLeftClicOneClick(Point p) {
        nbClics++;
        clean();
        addPoint(p);
        drawGhost(p);
        drawBlackLines();;
        drawRedLines();
    }

    private void treatmentLeftClicks(Point p) {
        nbClics++;
        clean();
        addPoint(p);
        drawGhost(p);
        drawBlackLines();
        drawRedLines();
    }

    private void treatmentMouseMoveWait() {
        nbClics = 0;
    }

    private void treatmentMouseMoveOneClick(Point p) {
        //nbClics = nbClics;
        clean();
        drawGhost(p);
        drawRedLines();
    }

    private void treatmentMouseMoveClicks(Point p) {
        //nbClics = nbClics;
        clean();
        drawGhost(p);
        drawBlackLines();
        drawRedLines();
    }

    private void treatmentSpaceKeyPressedWait() {
        nbClics = 0;
    }

    private void treatmentSpaceKeyPressedOneClick() {
        nbClics = 0;
        clean();
        removePoint();
        drawRedLines();
    }

    private void treatmentSpaceKeyPressedClicks() {
        nbClics = 0;
        storePolyline();
        drawRedLines();
    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        panelDraw = new exercice2.DrawMultipleLinesPanel();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setTitle("Gimpless");
        setMinimumSize(new java.awt.Dimension(400, 300));
        setPreferredSize(new java.awt.Dimension(1024, 600));
        addKeyListener(new java.awt.event.KeyAdapter() {
            public void keyPressed(java.awt.event.KeyEvent evt) {
                formKeyPressed(evt);
            }
        });

        panelDraw.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                panelDrawMouseClicked(evt);
            }
        });
        panelDraw.addMouseMotionListener(new java.awt.event.MouseMotionAdapter() {
            public void mouseMoved(java.awt.event.MouseEvent evt) {
                panelDrawMouseMoved(evt);
            }
        });
        panelDraw.setLayout(new java.awt.FlowLayout());
        getContentPane().add(panelDraw, java.awt.BorderLayout.CENTER);

        pack();
    }// </editor-fold>//GEN-END:initComponents

        private void panelDrawMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_panelDrawMouseClicked
            switch (state) {
                case WAIT:
                    if (SwingUtilities.isRightMouseButton(evt)) { // Right click
                        state = States.WAIT;
                        treatmentRightClickWait();
                    } else if (SwingUtilities.isLeftMouseButton(evt)) { // Left click
                        state = States.ONE_CLICK;
                        treatmentLeftClickWait((Point) evt.getPoint());
                    }
                    break;
                case ONE_CLICK:
                    if (SwingUtilities.isRightMouseButton(evt)) { // Right click
                        state = States.WAIT;
                        treatmentRightClicOneClick();
                    } else if (SwingUtilities.isLeftMouseButton(evt)) { // Left click
                        state = States.CLICKS;
                        treatmentLeftClicOneClick((Point) evt.getPoint());
                    }
                    break;
                case CLICKS:
                    if (SwingUtilities.isRightMouseButton(evt)) { // Right click
                        treatmentRightClicks((Point) evt.getPoint());
                    } else if (SwingUtilities.isLeftMouseButton(evt)) { // Left click
                        state = States.CLICKS;
                        treatmentLeftClicks((Point) evt.getPoint());
                    }
                    break;
                default:
                    throw new RuntimeException("bad state");

            }
        }//GEN-LAST:event_panelDrawMouseClicked

        private void panelDrawMouseMoved(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_panelDrawMouseMoved
            switch (state) {
                case WAIT:
                    state = States.WAIT;
                    treatmentMouseMoveWait();
                    break;
                case ONE_CLICK:
                    state = States.ONE_CLICK;
                    treatmentMouseMoveOneClick((Point) evt.getPoint());
                    break;
                case CLICKS:
                    state = States.CLICKS;
                    treatmentMouseMoveClicks((Point) evt.getPoint());
                    break;
                default:
                    throw new RuntimeException("bad state");
            }
        }//GEN-LAST:event_panelDrawMouseMoved

        private void formKeyPressed(java.awt.event.KeyEvent evt) {//GEN-FIRST:event_formKeyPressed
            if (evt.getKeyCode() == KeyEvent.VK_SPACE) {
                switch (state) {
                    case WAIT:
                        state = States.WAIT;
                        treatmentSpaceKeyPressedWait();
                        break;
                    case ONE_CLICK:
                        state = States.WAIT;
                        treatmentSpaceKeyPressedOneClick();
                        break;
                    case CLICKS:
                        state = States.WAIT;
                        treatmentSpaceKeyPressedClicks();
                        break;
                    default:
                        throw new RuntimeException("bad state");
                }
            }
        }//GEN-LAST:event_formKeyPressed

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
            java.util.logging.Logger.getLogger(GimplessFrameRubberBanding.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(GimplessFrameRubberBanding.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(GimplessFrameRubberBanding.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(GimplessFrameRubberBanding.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new GimplessFrameRubberBanding().setVisible(true);
            }
        });
    }

    private States state;
    private int nbClics;

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private exercice2.DrawMultipleLinesPanel panelDraw;
    // End of variables declaration//GEN-END:variables
}
