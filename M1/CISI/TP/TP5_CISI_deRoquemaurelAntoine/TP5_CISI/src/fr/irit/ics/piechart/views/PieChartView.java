/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package fr.irit.ics.piechart.views;

import fr.irit.ics.piechart.PieChart;

/**
 *
 * @author aroquemaurel
 */
public class PieChartView extends PieChart implements IView {

    @Override
    public void notifyValChanged(int value) {
        setAngle(value);
    }
    
}
