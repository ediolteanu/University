package heroes;

import angels.Visitor;
import game.TerrainType;
import strategies.EnoughHealthStrategy;
import strategies.LowHealthStrategy;
import utilities.Constants;

import static java.lang.Math.min;
import static java.lang.Math.round;

public final class Knight extends Hero {
    public Knight(final int id, final int row, final int col) {
        super(id, "Knight", row, col, Constants.KNIGHT_INITIAL_HP);
    }

    public void updateTotalHP() {
        setTotalHP(Constants.KNIGHT_INITIAL_HP + this.getLevel() * Constants.KNIGHT_BONUS_LEVEL_HP);
        setCurrentHP(getTotalHP());
    }

    public void accept(final Hero hero, final TerrainType terrainType, final int heroDmg) {
        hero.fight(this, terrainType, heroDmg);
    }

    public int calculateDamageBeforeRaceModifiers(final Hero hero, final TerrainType terrainType) {
        float executeDamage;
        executeDamage = Constants.EXECUTE_BASE_DMG
                + this.getLevel() * Constants.EXECUTE_BONUS_LEVEL_DMG;
        if (terrainType == TerrainType.Land) {
            executeDamage = executeDamage + executeDamage * Constants.KNIGHT_LAND_MODIFIER;
        }
        executeDamage = round(executeDamage);
        float slamDamage = Constants.SLAM_BASE_DMG
                + this.getLevel() * Constants.SLAM_BONUS_LEVEL_DMG;
        if (terrainType == TerrainType.Land) {
            slamDamage = slamDamage + slamDamage * Constants.KNIGHT_LAND_MODIFIER;
        }
        slamDamage = round(slamDamage);
        return (int) (executeDamage + slamDamage);
    }

    private int execute(final Hero hero, final TerrainType terrainType,
                        final float raceModifier) {
        float damage;
        float percentageHp = (float) hero.getCurrentHP() / hero.getTotalHP();
        float limitHp = min(Constants.EXECUTE_MAX_HP_LIMIT, Constants.EXECUTE_HP_LIMIT
                + this.getLevel() * Constants.EXECUTE_BONUS_LEVEL_HP_LIMIT);
        if (percentageHp < limitHp) {
            damage = hero.getCurrentHP();
        } else {
            damage = Constants.EXECUTE_BASE_DMG
                    + this.getLevel() * Constants.EXECUTE_BONUS_LEVEL_DMG;
        }

        if (terrainType == TerrainType.Land) {
            damage = damage + damage * Constants.KNIGHT_LAND_MODIFIER;
        }
        damage = round(damage);
        if (hero instanceof Knight) {
            damage = damage + damage * raceModifier;
        } else {
            float sumModifiers = raceModifier;
            for (Float f : getAngelsModifiers()) {
                sumModifiers += f;
            }
            for (Float f : getStrategyModifiers()) {
                sumModifiers += f;
            }
            damage = damage + damage * (sumModifiers);
        }

        damage = round(damage);
        return (int) damage;
    }

    private int slam(final Hero hero, final TerrainType terrainType, final float raceModifier) {
        float damage = Constants.SLAM_BASE_DMG
                + this.getLevel() * Constants.SLAM_BONUS_LEVEL_DMG;

        if (terrainType == TerrainType.Land) {
            damage = damage + damage * Constants.KNIGHT_LAND_MODIFIER;
        }
        damage = round(damage);
        float sumModifiers = raceModifier;
        for (Float f : getAngelsModifiers()) {
            sumModifiers += f;
        }
        for (Float f : getStrategyModifiers()) {
            sumModifiers += f;
        }
        damage = damage + damage * (sumModifiers);

        damage = round(damage);
        hero.resetDebuffs();
        hero.setRemainingSlamRounds(Constants.SLAM_SNARE_ROUNDS);
        return (int) damage;
    }

    public void fight(final Knight knight, final TerrainType terrainType, final int knightDmg) {
        int totalDamage;
        totalDamage = this.execute(knight, terrainType, Constants.EXECUTE_KNIGHT_MODIFIER)
                + this.slam(knight, terrainType, Constants.SLAM_KNIGHT_MODIFIER);
        knight.setCurrentHP(knight.getCurrentHP() - totalDamage);
        if (knight.getCurrentHP() <= 0) {
            knight.setDead(true);
        }
    }

    public void fight(final Pyromancer pyromancer,
                      final TerrainType terrainType, final int pyroDmg) {
        int totalDamage;
        totalDamage = this.execute(pyromancer, terrainType, Constants.EXECUTE_PYROMANCER_MODIFIER)
                + this.slam(pyromancer, terrainType, Constants.SLAM_PYROMANCER_MODIFIER);
        pyromancer.setCurrentHP(pyromancer.getCurrentHP() - totalDamage);
        if (pyromancer.getCurrentHP() <= 0) {
            pyromancer.setDead(true);
        }
    }

    public void fight(final Rogue rogue, final TerrainType terrainType, final int rogueDmg) {
        int totalDamage;
        totalDamage = this.execute(rogue, terrainType, Constants.EXECUTE_ROGUE_MODIFIER)
                + this.slam(rogue, terrainType, Constants.SLAM_ROGUE_MODIFIER);
        rogue.setCurrentHP(rogue.getCurrentHP() - totalDamage);
        if (rogue.getCurrentHP() <= 0) {
            rogue.setDead(true);
        }
    }

    public void fight(final Wizard wizard, final TerrainType terrainType, final int wizardDmg) {
        int totalDamage;
        totalDamage = this.execute(wizard, terrainType, Constants.EXECUTE_WIZARD_MODIFIER)
                + this.slam(wizard, terrainType, Constants.SLAM_WIZARD_MODIFIER);
        wizard.setCurrentHP(wizard.getCurrentHP() - totalDamage);
        if (wizard.getCurrentHP() <= 0) {
            wizard.setDead(true);
        }
    }

    @Override
    public void accept(final Visitor visitor) {
        visitor.visit(this);
    }

    public void applyStrategy() {
        if ((this.getCurrentHP() > Constants.STRATEGY_KNIGHT_LOWER_PERCENT * this.getTotalHP())
                && (this.getCurrentHP()
                < Constants.STRATEGY_KNIGHT_UPPER_PERCENT * this.getTotalHP())) {
            EnoughHealthStrategy enoughHealthStrategy = new EnoughHealthStrategy();
            enoughHealthStrategy.applyPercentageHealthStrategy(this);
        } else if (this.getCurrentHP()
                < Constants.STRATEGY_KNIGHT_LOWER_PERCENT * this.getTotalHP()) {
            LowHealthStrategy lowHealthStrategy = new LowHealthStrategy();
            lowHealthStrategy.applyPercentageHealthStrategy(this);
        }
    }

    @Override
    public String toString() {
        if (isDead()) {
            return "K dead\n";
        } else {
            return "K " + getLevel() + " " + getXp() + " " + getCurrentHP()
                    + " " + getRow() + " " + getCol() + "\n";
        }
    }


}
