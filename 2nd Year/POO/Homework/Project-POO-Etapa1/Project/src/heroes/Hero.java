package heroes;

import game.TerrainType;
import utilities.Constants;

import java.util.ArrayList;

import static java.lang.Math.max;

public abstract class Hero {
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

    Hero(final int row, final int col, final int initialHP) {
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

    final int getXp() {
        return xp;
    }

    public final ArrayList<Character> getMoves() {
        return moves;
    }

    final int getTotalHP() {
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

    final int getLevel() {
        return level;
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
        if (xp >= Constants.XP_NEEDED_FOR_LEVEL_1) {
            level = (xp - Constants.XP_NEEDED_FOR_LEVEL_1) / Constants.XP_NEEDED_PER_LEVEL + 1;
            return 1;
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

}
