/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package fr.irit.ics.piechart.views;

import javax.swing.JTextField;

/**
 *
 * @author aroquemaurel
 */
public class JTextFieldPercent extends JTextField implements IView {

    @Override
    public void notifyValChanged(int value) {
        setText(String.valueOf(value));
    }
    
}
