/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package fr.irit.ics.piechart;

import java.awt.Point;
import javax.swing.JPanel;

/**
 *
 * @author Racim
 */
public class UtilitiesPieChart {
    public static boolean isPointInCircle(JPanel panel, int mouseX, int mouseY) {
        int centerX = panel.getWidth() / 2;
        int centerY = panel.getHeight() / 2;
        int radius = Math.min(panel.getWidth() - 4, panel.getHeight() - 4) / 2;
        return (Math.pow(mouseX - centerX, 2) + Math.pow(mouseY - centerY, 2) < Math.pow(radius, 2));
    }

    public static int pointToPercentage(JPanel p, int x, int y) {
        Point c = new Point(p.getWidth() / 2, p.getHeight() / 2);
        Point b = new Point(p.getWidth(), p.getHeight() / 2);
        double angle = Math.atan2(c.y - b.y, c.x - b.x) - Math.atan2(c.y - y, c.y - x);
        return (int) (Math.ceil(Math.toDegrees(angle)) * 100 / 360);
    }
}
