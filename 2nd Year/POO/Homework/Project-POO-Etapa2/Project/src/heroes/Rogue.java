package heroes;

import angels.Visitor;
import game.TerrainType;
import strategies.EnoughHealthStrategy;
import strategies.LowHealthStrategy;
import utilities.Constants;

import static java.lang.Math.round;

public final class Rogue extends Hero {
    private int backstabCounter = 0;

    public Rogue(final int id, final int row, final int col) {
        super(id, "Rogue", row, col, Constants.ROGUE_INITIAL_HP);
    }

    public void updateTotalHP() {
        setTotalHP(Constants.ROGUE_INITIAL_HP + this.getLevel() * Constants.ROGUE_BONUS_LEVEL_HP);
        setCurrentHP(getTotalHP());
    }

    public void accept(final Hero hero, final TerrainType terrainType, final int heroDmg) {
        hero.fight(this, terrainType, heroDmg);
    }

    public int calculateDamageBeforeRaceModifiers(final Hero hero, final TerrainType terrainType) {
        backstabCounter += 1;
        float backstabDamage = Constants.BACKSTAB_BASE_DMG
                + this.getLevel() * Constants.BACKSTAB_BONUS_LEVEL_DMG;
        if (terrainType == TerrainType.Woods) {
            backstabDamage = backstabDamage + backstabDamage * Constants.ROGUE_WOODS_MODIFIER;
            if (backstabCounter % Constants.BACKSTAB_CRIT_COUNTER == 1) {
                backstabDamage = backstabDamage * Constants.BACKSTAB_WOODS_CRIT_MULTIPLIER;
            }
        }
        backstabCounter -= 1;
        backstabDamage = round(backstabDamage);
        float paralysisDamage = Constants.PARALYSIS_ROUND_DMG
                + this.getLevel() * Constants.PARALYSIS_BONUS_LEVEL_ROUND_DMG;
        if (terrainType == TerrainType.Woods) {
            paralysisDamage = paralysisDamage + paralysisDamage * Constants.ROGUE_WOODS_MODIFIER;
        }
//        if ((hero instanceof Knight) || (hero instanceof Rogue)) {
//            paralysisDamage -= Constants.ADJUST_ROGUE_DAMAGE;
//        }
        paralysisDamage = round(paralysisDamage);
        return (int) (backstabDamage + paralysisDamage);
    }

    private int backstab(final TerrainType terrainType, final float raceModifier) {
        backstabCounter += 1;
        float damage = Constants.BACKSTAB_BASE_DMG
                + this.getLevel() * Constants.BACKSTAB_BONUS_LEVEL_DMG;

        if (terrainType == TerrainType.Woods) {
            damage = damage + damage * Constants.ROGUE_WOODS_MODIFIER;
            damage = round(damage);
            if (backstabCounter % Constants.BACKSTAB_CRIT_COUNTER == 1) {
                damage = damage * Constants.BACKSTAB_WOODS_CRIT_MULTIPLIER;
                damage = round(damage);
            }
        } else if (backstabCounter == Constants.BACKSTAB_CRIT_COUNTER) {
            backstabCounter = 1;
        }

        float sumModifiers = raceModifier;
        for (Float f : getAngelsModifiers()) {
            sumModifiers += f;
        }
        for (Float f : getStrategyModifiers()) {
            sumModifiers += f;
        }
        damage = damage + damage * (sumModifiers);

        damage = round(damage);
        return (int) damage;
    }

    private int paralysis(final Hero hero, final TerrainType terrainType,
                          final float raceModifier) {
        float damage = Constants.PARALYSIS_ROUND_DMG
                + this.getLevel() * Constants.PARALYSIS_BONUS_LEVEL_ROUND_DMG;
        hero.resetDebuffs();

        if (terrainType == TerrainType.Woods) {
            damage = damage + damage * Constants.ROGUE_WOODS_MODIFIER;
            hero.setRemainingParalysisRounds(Constants.PARALYSIS_OVERTIME_ROUNDS_WOODS);
        } else {
            hero.setRemainingParalysisRounds(Constants.PARALYSIS_OVERTIME_ROUNDS);
        }
        damage = round(damage);

        float sumModifiers = raceModifier;
        for (Float f : getAngelsModifiers()) {
            sumModifiers += f;
        }
        for (Float f : getStrategyModifiers()) {
            sumModifiers += f;
        }
        sumModifiers += Constants.ADJUST_ROGUE_DAMAGE;
        damage = damage + damage * (sumModifiers);

        damage = round(damage);
        hero.setParalysisDamage((int) damage);
        return (int) damage;
    }

    public void fight(final Knight knight, final TerrainType terrainType, final int knightDmg) {
        int totalDamage;
        totalDamage = this.backstab(terrainType, Constants.BACKSTAB_KNIGHT_MODIFIER)
                + this.paralysis(knight, terrainType, Constants.PARALYSIS_KNIGHT_MODIFIER);
        knight.setCurrentHP(knight.getCurrentHP() - totalDamage);
        if (knight.getCurrentHP() <= 0) {
            knight.setDead(true);
        }
    }

    public void fight(final Pyromancer pyromancer,
                      final TerrainType terrainType, final int pyroDmg) {
        int totalDamage;
        totalDamage = this.backstab(terrainType, Constants.BACKSTAB_PYROMANCER_MODIFIER)
                + this.paralysis(pyromancer, terrainType, Constants.PARALYSIS_PYROMANCER_MODIFIER);
        pyromancer.setCurrentHP(pyromancer.getCurrentHP() - totalDamage);
        if (pyromancer.getCurrentHP() <= 0) {
            pyromancer.setDead(true);
        }
    }

    public void fight(final Rogue rogue, final TerrainType terrainType, final int rogueDmg) {
        int totalDamage;
        totalDamage = this.backstab(terrainType, Constants.BACKSTAB_ROGUE_MODIFIER)
                + this.paralysis(rogue, terrainType, Constants.PARALYSIS_ROGUE_MODIFIER);
        rogue.setCurrentHP(rogue.getCurrentHP() - totalDamage);
        if (rogue.getCurrentHP() <= 0) {
            rogue.setDead(true);
        }
    }

    public void fight(final Wizard wizard, final TerrainType terrainType, final int wizardDmg) {
        int totalDamage;
        totalDamage = this.backstab(terrainType, Constants.BACKSTAB_WIZARD_MODIFIER)
                + this.paralysis(wizard, terrainType, Constants.PARALYSIS_WIZARD_MODIFIER);
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
        if ((this.getCurrentHP() > Constants.STRATEGY_ROGUE_LOWER_PERCENT * this.getTotalHP())
                && (this.getCurrentHP()
                < Constants.STRATEGY_ROGUE_UPPER_PERCENT * this.getTotalHP())) {
            EnoughHealthStrategy enoughHealthStrategy = new EnoughHealthStrategy();
            enoughHealthStrategy.applyPercentageHealthStrategy(this);
        } else if (this.getCurrentHP()
                < Constants.STRATEGY_ROGUE_LOWER_PERCENT * this.getTotalHP()) {
            LowHealthStrategy lowHealthStrategy = new LowHealthStrategy();
            lowHealthStrategy.applyPercentageHealthStrategy(this);
        }
    }

    @Override
    public String toString() {
        if (isDead()) {
            return "R dead\n";
        } else {
            return "R " + getLevel() + " " + getXp() + " " + getCurrentHP()
                    + " " + getRow() + " " + getCol() + "\n";
        }
    }
}
