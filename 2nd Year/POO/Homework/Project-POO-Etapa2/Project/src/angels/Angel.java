package angels;

import heroes.Hero;
import utilities.Constants;

import java.util.ArrayList;
import java.util.Observable;
import java.util.Observer;

public abstract class Angel extends Observable implements Visitor {
    private ArrayList<Observer> observers;
    private String name;
    private int roundNo;
    private int row;
    private int col;
    private boolean good;

    public Angel(final String name,
                 final boolean good,
                 final int roundNo,
                 final int row,
                 final int col) {
        this.name = name;
        this.good = good;
        this.roundNo = roundNo;
        this.row = row;
        this.col = col;
        this.observers = new ArrayList<>();
    }

    public final boolean isGood() {
        return good;
    }

    public final int getRoundNo() {
        return roundNo;
    }

    public final int getRow() {
        return row;
    }

    public final int getCol() {
        return col;
    }

    public final String toString() {
        return roundNo + " " + "angel" + " " + row + "," + col;
    }

    public final void addObserver(final Observer observer) {
        observers.add(observer);
    }

    public final void notifyObservers(final String string, final Object obj) {
        String phrase = null;
        for (Observer o : observers) {
            switch (string) {
                case Constants.CASE_SPAWNED:
                    phrase = "Angel " + name + " was spawned at "
                            + getRow() + " " + getCol() + "\n";
                    break;
                case Constants.CASE_HIT:
                    phrase = name + " hit " + ((Hero) obj).getName()
                            + " " + ((Hero) obj).getId() + "\n";
                    break;
                case Constants.CASE_HELPED:
                    phrase = name + " helped " + ((Hero) obj).getName()
                            + " " + ((Hero) obj).getId() + "\n";
                    break;
                default:
                    break;
            }
            o.update(this, phrase);
        }
    }
}
