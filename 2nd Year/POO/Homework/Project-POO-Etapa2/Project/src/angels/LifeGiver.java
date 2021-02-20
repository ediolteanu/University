package angels;

import heroes.Knight;
import heroes.Pyromancer;
import heroes.Rogue;
import heroes.Wizard;
import utilities.Constants;

import static java.lang.Math.min;

public final class LifeGiver extends Angel {
    public LifeGiver(final int roundNo, final int row, final int col) {
        super("LifeGiver", true, roundNo, row, col);
    }

    @Override
    public void visit(final Knight knight) {
        knight.setCurrentHP(min(knight.getTotalHP(), knight.getCurrentHP()
                + Constants.LIFEGIVER_KNIGHT_CHANGED_HP));
    }

    @Override
    public void visit(final Pyromancer pyromancer) {
        pyromancer.setCurrentHP(min(pyromancer.getTotalHP(), pyromancer.getCurrentHP()
                + Constants.LIFEGIVER_PYROMANCER_CHANGED_HP));
    }

    @Override
    public void visit(final Rogue rogue) {
        rogue.setCurrentHP(min(rogue.getTotalHP(), rogue.getCurrentHP()
                + Constants.LIFEGIVER_ROGUE_CHANGED_HP));
    }

    @Override
    public void visit(final Wizard wizard) {
        wizard.setCurrentHP(min(wizard.getTotalHP(), wizard.getCurrentHP()
                + Constants.LIFEGIVER_WIZARD_CHANGED_HP));
    }
}
