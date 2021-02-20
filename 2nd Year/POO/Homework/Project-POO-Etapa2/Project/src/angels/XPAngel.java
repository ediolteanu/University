package angels;

import heroes.Knight;
import heroes.Pyromancer;
import heroes.Rogue;
import heroes.Wizard;
import utilities.Constants;

public final class XPAngel extends Angel {
    public XPAngel(final int roundNo, final int row, final int col) {
        super("XPAngel", true, roundNo, row, col);
    }

    @Override
    public void visit(final Knight knight) {
        knight.setXp(knight.getXp() + Constants.XPANGEL_KNIGHT_CHANGED_XP);
    }

    @Override
    public void visit(final Pyromancer pyromancer) {
        pyromancer.setXp(pyromancer.getXp() + Constants.XPANGEL_PYROMANCER_CHANGED_XP);
    }

    @Override
    public void visit(final Rogue rogue) {
        rogue.setXp(rogue.getXp() + Constants.XPANGEL_ROGUE_CHANGED_XP);
    }

    @Override
    public void visit(final Wizard wizard) {
        wizard.setXp(wizard.getXp() + Constants.XPANGEL_WIZARD_CHANGED_XP);
    }
}
