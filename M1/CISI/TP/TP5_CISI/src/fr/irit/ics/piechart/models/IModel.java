package fr.irit.ics.piechart.models;

import fr.irit.ics.piechart.views.IView;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


/**
 *
 * @author aroquemaurel
 */
public interface IModel {
    public void setValue(int value);
    public int getValue();
    public void incrementValue();
    public void decrementValue();
    public void addView(IView view);
}
