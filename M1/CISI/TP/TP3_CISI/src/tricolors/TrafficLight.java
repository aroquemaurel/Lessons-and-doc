/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package tricolors;

import java.awt.Color;
import java.awt.Graphics;

/**
 *
 * @author aroquemaurel
 */
public class TrafficLight extends javax.swing.JPanel {
    private Color color;
    /**
     * Creates new form TrafficLight
     */
    public TrafficLight() {
        initComponents();
        color = Color.BLACK;
    }

    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        g.setColor(color);
        g.fillOval(75 ,0, 150, 150);
    }
    
    public void turnOnGreen() {
        color = Color.GREEN;
        repaint();
    }
    
    public void turnOnRed() {
        color = Color.RED;
        repaint();
    }
    
    public void turnOnOrange() {
        color = Color.ORANGE;
        repaint();
    }
    
    public void turnOff() {
        color = Color.BLACK;
        repaint();
    }
    
    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(this);
        this.setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 400, Short.MAX_VALUE)
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 300, Short.MAX_VALUE)
        );
    }// </editor-fold>//GEN-END:initComponents


    // Variables declaration - do not modify//GEN-BEGIN:variables
    // End of variables declaration//GEN-END:variables
}