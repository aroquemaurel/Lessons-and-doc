package fr.irit.ics.piechart.models;

import fr.irit.ics.piechart.views.IView;
import java.util.HashSet;
import java.util.Set;

/**
 *
 * @author aroquemaurel
 */
public class Model implements IModel {
    private int value;
    private Set<IView> views;
    
    public Model() {
        value = 0;
        views = new HashSet<>();
    }
    
    @Override
    public int getValue() {
        return value;
    }
    
    @Override
    public void setValue(int value) {
        this.value = value;
    }

    @Override
    public void addView(IView view) {
        views.add(view);
    }

    public void notifyValChanged() {
        for(IView view : views) {
            view.notifyValChanged(value);
        }
    }
    @Override
    public void incrementValue() {
        ++value;
    }

    @Override
    public void decrementValue() {
        --value;
    }
}
