/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package exercice2;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.Point;
import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author florent
 */
public class DrawMultipleLinesPanel extends javax.swing.JPanel {

       private List<ArrayList<Point>> polylines ;
       private List<Point> polyline;       
       private int nbPolyline;
       private Point ghost;
       private boolean isGhost;
     /*  protected Point origin;
       protected Point destination;
       protected boolean isMoving;     
        */
        /**
         * Creates new form DrawPanel
         */
        public DrawMultipleLinesPanel() {
                super();
                initComponents();
                init();
        }
       
        public void init() {
                polylines = new ArrayList<>();
                polyline = new ArrayList<>();
                ghost = new Point();
                nbPolyline = 0;
                isGhost = false;
               /* origin = new Point();
                destination = new Point();
                isMoving = false;
                */
        }
        
        @Override
        public void paintComponent(Graphics g) {
                super.paintComponent(g);   
                Point p1 = null;
                Point p2 = null;
                Point origin = null;
                
                // DRAW POLYLINES STORED
                g.setColor(Color.RED);                
                // get current line
                for (ArrayList<Point> p: polylines) {
                        p1 = p.get(0);
                        origin = p1;
                       // get current point of the line
                        for (int i = 1; i < p.size(); i++) {
                                p2 = p.get(i);
                                g.drawLine(
                                        (int)p1.getX(), 
                                        (int)p1.getY(),
                                        (int)p2.getX(), 
                                        (int)p2.getY());
                                p1 = p2;                              
                        }
                         g.drawLine(
                                        (int)p2.getX(), 
                                        (int)p2.getY(),
                                        (int)origin.getX(), 
                                        (int)origin.getY());
                }     
                // DRAW CURRENT POLYLINE
                 g.setColor(Color.DARK_GRAY);
                 if (polyline.size() > 1) {
                         p1 = polyline.get(0);
                         for (int i=1; i < polyline.size(); i++) {
                                 p2 = polyline.get(i);
                                  g.drawLine(
                                        (int)p1.getX(), 
                                        (int)p1.getY(),
                                        (int)p2.getX(), 
                                        (int)p2.getY());
                                  p1 = p2;
                         }
                 }
                // DRAW  GHOST 
                if (polyline.size() > 0 && isGhost) {
                        isGhost = false;
                        p1 = polyline.get(polyline.size()-1);
                        g.drawLine(
                                        (int)p1.getX(), 
                                        (int)p1.getY(),
                                        (int)ghost.getX(), 
                                        (int)ghost.getY());
                }
        }
             /*
        public void drawRedLines(Graphics g) {                               
                g.setColor(Color.RED);                
                // get current line
                for (ArrayList<Point> p: polylines) {
                       // get current point of the line
                        for (int i = 0; i < p.size(); i++) {
                                g.drawLine((int)polyline.get(i).getX(), 
                                    (int)polyline.get(i).getY(),
                                    (int)polyline.get(i+1).getX(), 
                                    (int)polyline.get(i+1).getY());
                        }                        
                }                               
        }
        
        public void drawGhostLine(Graphics g) {
               g.setColor(Color.DARK_GRAY);
               g.drawLine(
                   (int)origin.getX(), 
                   (int)origin.getY(),
                   (int)destination.getX(), 
                   (int)destination.getY());
        }
        */
        public void clean() {
               this.repaint();
       }
        
        public void storePolyline() {
                this.polylines.add((ArrayList<Point>) polyline);
                polyline  = new ArrayList<Point>();                
        }
      
        public void addPoint(Point p) {
                polyline.add(p);
                 System.out.println(""+polyline.size());
                nbPolyline++;
        }
        
        
       
        public void removePoint() {
               this.polyline.remove(polyline.get(polyline.size()-1));
               clean();
       }

        public List<ArrayList<Point>> getPolylines() {
                return polylines;
        }

        public void setPolylines(List<ArrayList<Point>> polylines) {
                this.polylines = polylines;
        }

        public List<Point> getPolyline() {
                return polyline;
        }

        public void setPolyline(List<Point> polyline) {
                this.polyline = polyline;
        }

        public int getNbPolyline() {
                return nbPolyline;
        }

        public void setNbPolyline(int nbPolyline) {
                this.nbPolyline = nbPolyline;
        }

        public Point getGhost() {
                return ghost;
        }

        public void setGhost(Point ghost) {
                this.ghost = ghost;
                isGhost = true;
        }
       
        
        

       
       
 
    
        /**
         * This method is called from within the constructor to initialize the
         * form. WARNING: Do NOT modify this code. The content of this method is
         * always regenerated by the Form Editor.
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
