package heroes;

import angels.Visitor;
import game.TerrainType;
import strategies.EnoughHealthStrategy;
import strategies.LowHealthStrategy;
import utilities.Constants;

import static java.lang.Math.min;
import static java.lang.Math.round;

public final class Wizard extends Hero {
    public Wizard(final int id, final int row, final int col) {
        super(id, "Wizard", row, col, Constants.WIZARD_INITIAL_HP);
    }

    public void updateTotalHP() {
        setTotalHP(Constants.WIZARD_INITIAL_HP + this.getLevel() * Constants.WIZARD_BONUS_LEVEL_HP);
        setCurrentHP(getTotalHP());
    }

    public void accept(final Hero hero, final TerrainType terrainType, final int heroDmg) {
        hero.fight(this, terrainType, heroDmg);
    }

    public int calculateDamageBeforeRaceModifiers(final Hero hero, final TerrainType terrainType) {
        /*
        This method's purpose is just to get the damage dealt by heroes in order to know the
        damage the wizard should deflect. Because wizards do not apply deflect between themselves
         the wizard implementation simply returns 0
         */
        return 0;
    }

    private int drain(final Hero hero, final TerrainType terrainType, final float raceModifier) {
        float damage;
        float percent = Constants.DRAIN_BASE_PERCENT
                + this.getLevel() * Constants.DRAIN_BONUS_LEVEL_PERCENT;

        if (terrainType == TerrainType.Desert) {
            percent = percent + percent * Constants.WIZARD_DESERT_MODIFIER;
        }

        float sumModifiers = raceModifier;
        for (Float f : getAngelsModifiers()) {
            sumModifiers += f;
        }
        for (Float f : getStrategyModifiers()) {
            sumModifiers += f;
        }
        percent = percent + percent * (sumModifiers);


        damage = percent * min(Constants.DRAIN_OPPONENT_MAX_HP_PERCENT
                * hero.getTotalHP(), hero.getCurrentHP());
        damage = round(damage);
        return (int) damage;
    }

    private int deflect(final TerrainType terrainType, final float raceModifier,
                        final int heroDmg) {
        float damage;
        float percent = Constants.DEFLECT_BASE_PERCENT + this.getLevel()
                * Constants.DEFLECT_BONUS_LEVEL_PERCENT;
        percent = min(percent, Constants.DEFLECT_MAX_PERCENT);

        if (terrainType == TerrainType.Desert) {
            percent = percent + percent * Constants.WIZARD_DESERT_MODIFIER;
        }

        float sumModifiers = raceModifier;
        for (Float f : getAngelsModifiers()) {
            sumModifiers += f;
        }
        for (Float f : getStrategyModifiers()) {
            sumModifiers += f;
        }
        percent = percent + percent * (sumModifiers);

        damage = percent * heroDmg;
        damage = round(damage);
        return (int) damage;
    }

    public void fight(final Knight knight, final TerrainType terrainType, final int knightDmg) {
        int totalDamage;
        totalDamage = this.drain(knight, terrainType, Constants.DRAIN_KNIGHT_MODIFIER)
                + this.deflect(terrainType, Constants.DEFLECT_KNIGHT_MODIFIER,
                knightDmg);
        knight.setCurrentHP(knight.getCurrentHP() - totalDamage);
        if (knight.getCurrentHP() <= 0) {
            knight.setDead(true);
        }
    }

    public void fight(final Pyromancer pyromancer,
                      final TerrainType terrainType, final int pyromancerDmg) {
        int totalDamage;
        totalDamage = this.drain(pyromancer, terrainType, Constants.DRAIN_PYROMANCER_MODIFIER)
                + this.deflect(terrainType, Constants.DEFLECT_PYROMANCER_MODIFIER,
                pyromancerDmg);
        pyromancer.setCurrentHP(pyromancer.getCurrentHP() - totalDamage);
        if (pyromancer.getCurrentHP() <= 0) {
            pyromancer.setDead(true);
        }
    }

    public void fight(final Rogue rogue, final TerrainType terrainType, final int rogueDmg) {
        int totalDamage;
        totalDamage = this.drain(rogue, terrainType, Constants.DRAIN_ROGUE_MODIFIER)
                + this.deflect(terrainType, Constants.DEFLECT_ROGUE_MODIFIER,
                rogueDmg);
        rogue.setCurrentHP(rogue.getCurrentHP() - totalDamage);
        if (rogue.getCurrentHP() <= 0) {
            rogue.setDead(true);
        }
    }

    public void fight(final Wizard wizard, final TerrainType terrainType, final int wizardDmg) {
        int totalDamage;
        totalDamage = this.drain(wizard, terrainType, Constants.DRAIN_WIZARD_MODIFIER);
        wizard.setCurrentHP(wizard.getCurrentHP() - totalDamage);
        if (wizard.getCurrentHP() <= 0) {
            wizard.setDead(true);
        }
    }

    @Override
    public void accept(final Visitor visitor) {
        visitor.visit(this);
    }

    @Override
    public void applyStrategy() {
        if ((this.getCurrentHP() > Constants.STRATEGY_WIZARD_LOWER_PERCENT * this.getTotalHP())
                && (this.getCurrentHP()
                < Constants.STRATEGY_WIZARD_UPPER_PERCENT * this.getTotalHP())) {
            EnoughHealthStrategy enoughHealthStrategy = new EnoughHealthStrategy();
            enoughHealthStrategy.applyPercentageHealthStrategy(this);
        } else if (this.getCurrentHP()
                < Constants.STRATEGY_WIZARD_LOWER_PERCENT * this.getTotalHP()) {
            LowHealthStrategy lowHealthStrategy = new LowHealthStrategy();
            lowHealthStrategy.applyPercentageHealthStrategy(this);
        }
    }

    @Override
    public String toString() {
        if (isDead()) {
            return "W dead\n";
        } else {
            return "W " + getLevel() + " " + getXp() + " " + getCurrentHP()
                    + " " + getRow() + " " + getCol() + "\n";
        }
    }
}
