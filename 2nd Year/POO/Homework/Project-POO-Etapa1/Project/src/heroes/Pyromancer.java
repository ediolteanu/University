package heroes;

import game.TerrainType;
import utilities.Constants;

import static java.lang.Math.round;

public final class Pyromancer extends Hero {
    public Pyromancer(final int row, final int col) {
        super(row, col, Constants.PYROMANCER_INITIAL_HP);
    }


    public void updateTotalHP() {
        setTotalHP(Constants.PYROMANCER_INITIAL_HP + this.getLevel()
                * Constants.PYROMANCER_BONUS_LEVEL_HP);
        setCurrentHP(getTotalHP());
    }

    public void accept(final Hero hero, final TerrainType terrainType, final int heroDmg) {
        hero.fight(this, terrainType, heroDmg);
    }

    public int calculateDamageBeforeRaceModifiers(final Hero hero, final TerrainType terrainType) {
        float fireblastDamage = Constants.FIREBLAST_BASE_DMG
                + this.getLevel() * Constants.FIREBLAST_BONUS_LEVEL_DMG;
        if (terrainType == TerrainType.Volcanic) {
            fireblastDamage = fireblastDamage
                    + fireblastDamage * Constants.PYROMANCER_VOLCANIC_MODIFIER;
        }
        fireblastDamage = round(fireblastDamage);
        float igniteDamage = Constants.IGNITE_BASE_DMG
                + this.getLevel() * Constants.IGNITE_BONUS_LEVEL_BASE_DMG;
        if (terrainType == TerrainType.Volcanic) {
            igniteDamage = igniteDamage + igniteDamage * Constants.PYROMANCER_VOLCANIC_MODIFIER;
        }
        igniteDamage = round(igniteDamage);
        return (int) (fireblastDamage + igniteDamage);
    }

    private int fireblast(final TerrainType terrainType, final float raceModifier) {
        float damage = Constants.FIREBLAST_BASE_DMG
                + this.getLevel() * Constants.FIREBLAST_BONUS_LEVEL_DMG;
        if (terrainType == TerrainType.Volcanic) {
            damage = damage + damage * Constants.PYROMANCER_VOLCANIC_MODIFIER;
        }
        damage = round(damage + damage * raceModifier);
        return (int) damage;
    }

    private int ignite(final Hero hero, final TerrainType terrainType, final float raceModifier) {
        float damage = Constants.IGNITE_BASE_DMG
                + this.getLevel() * Constants.IGNITE_BONUS_LEVEL_BASE_DMG;
        float damageOverTime = Constants.IGNITE_ROUND_DMG
                + this.getLevel() * Constants.IGNITE_BONUS_LEVEL_ROUND_DMG;
        if (terrainType == TerrainType.Volcanic) {
            damage = damage + damage * Constants.PYROMANCER_VOLCANIC_MODIFIER;
            damageOverTime = damageOverTime
                    + damageOverTime * Constants.PYROMANCER_VOLCANIC_MODIFIER;
        }
        damage = round(damage + damage * raceModifier);
        damageOverTime = round(damageOverTime + damageOverTime * raceModifier);
        hero.resetDebuffs();
        hero.setRemainingIgniteRounds(Constants.IGNITE_ROUNDS);
        hero.setIgniteDamage((int) damageOverTime);
        return (int) damage;
    }

    public void fight(final Knight knight, final TerrainType terrainType, final int knightDmg) {
        int totalDamage;
        totalDamage = this.fireblast(terrainType, Constants.FIREBLAST_KNIGHT_MODIFIER)
                + this.ignite(knight, terrainType, Constants.IGNITE_KNIGHT_MODIFIER);
        knight.setCurrentHP(knight.getCurrentHP() - totalDamage);
        if (knight.getCurrentHP() <= 0) {
            knight.setDead(true);
        }
    }

    public void fight(final Pyromancer pyromancer,
                      final TerrainType terrainType, final int pyroDmg) {
        int totalDamage;
        totalDamage = this.fireblast(terrainType,
                Constants.FIREBLAST_PYROMANCER_MODIFIER)
                + this.ignite(pyromancer, terrainType, Constants.IGNITE_PYROMANCER_MODIFIER);
        pyromancer.setCurrentHP(pyromancer.getCurrentHP() - totalDamage);
        if (pyromancer.getCurrentHP() <= 0) {
            pyromancer.setDead(true);
        }
    }

    public void fight(final Rogue rogue, final TerrainType terrainType, final int rogueDmg) {
        int totalDamage;
        totalDamage = this.fireblast(terrainType, Constants.FIREBLAST_ROGUE_MODIFIER)
                + this.ignite(rogue, terrainType, Constants.IGNITE_ROGUE_MODIFIER);
        rogue.setCurrentHP(rogue.getCurrentHP() - totalDamage);
        if (rogue.getCurrentHP() <= 0) {
            rogue.setDead(true);
        }
    }

    public void fight(final Wizard wizard, final TerrainType terrainType, final int wizardDmg) {
        int totalDamage;
        totalDamage = this.fireblast(terrainType, Constants.FIREBLAST_WIZARD_MODIFIER)
                + this.ignite(wizard, terrainType, Constants.IGNITE_WIZARD_MODIFIER);
        wizard.setCurrentHP(wizard.getCurrentHP() - totalDamage);
        if (wizard.getCurrentHP() <= 0) {
            wizard.setDead(true);
        }
    }

    @Override
    public String toString() {
        if (isDead()) {
            return "P dead\n";
        } else {
            return "P " + getLevel() + " " + getXp() + " " + getCurrentHP()
                    + " " + getRow() + " " + getCol() + "\n";
        }
    }
}
