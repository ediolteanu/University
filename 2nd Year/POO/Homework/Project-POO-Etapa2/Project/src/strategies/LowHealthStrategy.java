package strategies;

import heroes.Knight;
import heroes.Pyromancer;
import heroes.Rogue;
import heroes.Wizard;
import utilities.Constants;

import static java.lang.Math.floor;

public final class LowHealthStrategy implements HealthStrategy {
    @Override
    public void applyPercentageHealthStrategy(final Knight knight) {
        knight.addStrategyModifiers(Constants.STRATEGY_KNIGHT_LOST_MODIFIER);
        knight.setCurrentHP((int) floor(knight.getCurrentHP()
                * (1 + Constants.STRATEGY_KNIGHT_GAINED_HP)));
    }

    @Override
    public void applyPercentageHealthStrategy(final Pyromancer pyromancer) {
        pyromancer.addStrategyModifiers(Constants.STRATEGY_PYROMANCER_LOST_MODIFIER);
        pyromancer.setCurrentHP((int) floor(pyromancer.getCurrentHP()
                * (1 + Constants.STRATEGY_PYROMANCER_GAINED_HP)));
    }

    @Override
    public void applyPercentageHealthStrategy(final Rogue rogue) {
        rogue.addStrategyModifiers(Constants.STRATEGY_ROGUE_LOST_MODIFIER);
        rogue.setCurrentHP((int) floor(rogue.getCurrentHP()
                * (1 + Constants.STRATEGY_ROGUE_GAINED_HP)));
    }

    @Override
    public void applyPercentageHealthStrategy(final Wizard wizard) {
        wizard.addStrategyModifiers(Constants.STRATEGY_WIZARD_LOST_MODIFIER);
        wizard.setCurrentHP((int) floor(wizard.getCurrentHP()
                * (1 + Constants.STRATEGY_WIZARD_GAINED_HP)));
    }
}
