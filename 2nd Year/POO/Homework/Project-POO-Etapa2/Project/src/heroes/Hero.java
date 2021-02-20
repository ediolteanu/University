package heroes;

import game.TerrainType;
import utilities.Constants;

import java.util.ArrayList;
import java.util.Observable;
import java.util.Observer;

import static java.lang.Math.max;

public abstract class Hero extends Observable implements Visitable {
    private int id;
    private String name;
    private int row;
    private int col;
    private ArrayList<Character> moves;
    private int xp;
    private int totalHP;
    private int currentHP;
    private int level;
    private int remainingSlamRounds;
    private int remainingIgniteRounds;
    private int igniteDamage;
    private int remainingParalysisRounds;
    private int paralysisDamage;
    private boolean dead;
    private boolean hasFought;
    private ArrayList<Float> angelsModifiers;
    private ArrayList<Float> strategyModifiers;
    private ArrayList<Observer> observers;

    Hero(final int id, final String name, final int row, final int col, final int initialHP) {
        this.id = id;
        this.name = name;
        this.row = row;
        this.col = col;
        this.moves = new ArrayList<>();
        this.xp = Constants.INITIAL_XP;
        this.totalHP = initialHP;
        this.currentHP = initialHP;
        this.level = Constants.INITIAL_LEVEL;
        this.remainingSlamRounds = 0;
        this.remainingIgniteRounds = 0;
        this.remainingParalysisRounds = 0;
        this.igniteDamage = 0;
        this.paralysisDamage = 0;
        this.dead = false;
        this.hasFought = false;
        this.angelsModifiers = new ArrayList<>();
        this.strategyModifiers = new ArrayList<>();
        this.observers = new ArrayList<>();
    }

    public final int getId() {
        return id;
    }

    public final String getName() {
        return name;
    }

    public final void setXp(final int xp) {
        this.xp = xp;
    }

    public final boolean getHasFought() {
        return !hasFought;
    }

    public final void setHasFought(final boolean hasFought) {
        this.hasFought = hasFought;
    }

    public final void resetHasFought() {
        this.hasFought = false;
    }

    public final int getRow() {
        return row;
    }

    private void setRow(final int row) {
        this.row = row;
    }

    public final int getCol() {
        return col;
    }

    private void setCol(final int col) {
        this.col = col;
    }

    public final int getXp() {
        return xp;
    }

    public final ArrayList<Character> getMoves() {
        return moves;
    }

    public final int getTotalHP() {
        return totalHP;
    }

    final void setTotalHP(final int totalHP) {
        this.totalHP = totalHP;
    }

    public final int getCurrentHP() {
        return currentHP;
    }

    public final void setCurrentHP(final int currentHP) {
        this.currentHP = currentHP;
    }

    public final int getLevel() {
        return level;
    }

    public final void setLevel(final int level) {
        this.level = level;
    }

    public final int getRemainingSlamRounds() {
        return remainingSlamRounds;
    }

    public final void setRemainingSlamRounds(final int remainingSlamRounds) {
        this.remainingSlamRounds = remainingSlamRounds;
    }

    public final int getRemainingIgniteRounds() {
        return remainingIgniteRounds;
    }

    public final void setRemainingIgniteRounds(final int remainingIgniteRounds) {
        this.remainingIgniteRounds = remainingIgniteRounds;
    }

    public final int getRemainingParalysisRounds() {
        return remainingParalysisRounds;
    }

    public final void setRemainingParalysisRounds(final int remainingParalysisRounds) {
        this.remainingParalysisRounds = remainingParalysisRounds;
    }

    public final int getIgniteDamage() {
        return igniteDamage;
    }

    final void setIgniteDamage(final int igniteDamage) {
        this.igniteDamage = igniteDamage;
    }

    public final int getParalysisDamage() {
        return paralysisDamage;
    }

    final void setParalysisDamage(final int paralysisDamage) {
        this.paralysisDamage = paralysisDamage;
    }

    public final boolean isDead() {
        return dead;
    }

    public final void setDead(final boolean dead) {
        this.dead = dead;
    }

    public abstract int calculateDamageBeforeRaceModifiers(Hero hero, TerrainType terrainType);

    public abstract void accept(Hero hero, TerrainType terrainType, int heroDmg);

    public abstract void fight(Knight knight, TerrainType terrainType, int heroDmg);

    public abstract void fight(Pyromancer pyromancer, TerrainType terrainType, int heroDmg);

    public abstract void fight(Rogue rogue, TerrainType terrainType, int heroDmg);

    public abstract void fight(Wizard wizard, TerrainType terrainType, int heroDmg);

    public final void setWinnerXp(final Hero loser) {
        this.xp += max(0, Constants.UPDATE_XP_COMPARE_VALUE - (this.level - loser.getLevel())
                * Constants.UPDATE_XP_MULTIPLIER_VALUE);
    }

    public final int updateLevel() {
        int oldLevel = getLevel();
        if (xp >= Constants.XP_NEEDED_FOR_LEVEL_1) {
            level = (xp - Constants.XP_NEEDED_FOR_LEVEL_1) / Constants.XP_NEEDED_PER_LEVEL + 1;
            if (oldLevel != level) {
                for (int i = oldLevel + 1; i <= level; i++) {
                    this.notifyObservers("level-up", i);
                }
                return 1;
            }
        }
        return 0;
    }

    final void resetDebuffs() {
        this.remainingSlamRounds = 0;
        this.remainingIgniteRounds = 0;
        this.remainingParalysisRounds = 0;
        this.igniteDamage = 0;
        this.paralysisDamage = 0;
    }

    public final void updatePosition(final int round) {
        switch (moves.get(round)) {
            case 'R':
                setCol(getCol() + 1);
                break;
            case 'D':
                setRow(getRow() + 1);
                break;
            case 'L':
                setCol(getCol() - 1);
                break;
            case 'U':
                setRow(getRow() - 1);
                break;
            default:
                break;
        }
    }

    public abstract void updateTotalHP();

    public final ArrayList<Float> getAngelsModifiers() {
        return angelsModifiers;
    }

    public final void addAngelsModifiers(final float angelsModifier) {
        this.angelsModifiers.add(angelsModifier);
    }

    public final ArrayList<Float> getStrategyModifiers() {
        return strategyModifiers;
    }

    public final void addStrategyModifiers(final float strategyModifier) {
        this.strategyModifiers.add(strategyModifier);
    }

    public abstract void applyStrategy();

    public final void addObserver(final Observer observer) {
        observers.add(observer);
    }

    public final void notifyObservers(final String string, final Object obj) {
        String phrase = null;
        for (Observer o : observers) {
            switch (string) {
                case Constants.CASE_KBP:
                    phrase = "Player " + name + " " + id + " was killed by "
                            + ((Hero) obj).getName() + " " + ((Hero) obj).getId() + "\n";
                    break;
                case Constants.CASE_LVL_UP:
                    phrase = name + " " + id + " reached level " + obj + "\n";
                    break;
                case Constants.CASE_KBA:
                    phrase = "Player " + name + " " + id + " was killed by an angel\n";
                    break;
                case Constants.CASE_SPAWNED:
                    phrase = "Player " + name + " " + id + " was brought to life by an angel\n";
                default:
            }

            o.update(this, phrase);
        }
    }
}
