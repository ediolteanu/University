package angels;

import heroes.Knight;
import heroes.Pyromancer;
import heroes.Rogue;
import heroes.Wizard;
import utilities.Constants;

import static java.lang.Math.max;

public final class DarkAngel extends Angel {
    public DarkAngel(final int roundNo, final int row, final int col) {
        super("DarkAngel", false, roundNo, row, col);
    }

    @Override
    public void visit(final Knight knight) {
        knight.setCurrentHP(max(0, knight.getCurrentHP()
                + Constants.DARKANGEL_KNIGHT_CHANGED_HP));
    }

    @Override
    public void visit(final Pyromancer pyromancer) {
        pyromancer.setCurrentHP(max(0, pyromancer.getCurrentHP()
                + Constants.DARKANGEL_PYROMANCER_CHANGED_HP));
    }

    @Override
    public void visit(final Rogue rogue) {
        rogue.setCurrentHP(max(0, rogue.getCurrentHP()
                + Constants.DARKANGEL_ROGUE_CHANGED_HP));
    }

    @Override
    public void visit(final Wizard wizard) {
        wizard.setCurrentHP(max(0, wizard.getCurrentHP()
                + Constants.DARKANGEL_WIZARD_CHANGED_HP));
    }
}
