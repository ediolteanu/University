package angels;

import heroes.Knight;
import heroes.Pyromancer;
import heroes.Rogue;
import heroes.Wizard;
import utilities.Constants;

import static java.lang.Math.max;

public final class SmallAngel extends Angel {
    public SmallAngel(final int roundNo, final int row, final int col) {
        super("SmallAngel", true, roundNo, row, col);
    }

    @Override
    public void visit(final Knight knight) {
        knight.addAngelsModifiers(Constants.SMALLANGEL_KNIGHT_MODIFIER);
        knight.setCurrentHP(max(0, knight.getCurrentHP()
                + Constants.SMALLANGEL_KNIGHT_CHANGED_HP));
    }

    @Override
    public void visit(final Pyromancer pyromancer) {
        pyromancer.addAngelsModifiers(Constants.SMALLANGEL_PYROMANCER_MODIFIER);
        pyromancer.setCurrentHP(max(0, pyromancer.getCurrentHP()
                + Constants.SMALLANGEL_PYROMANCER_CHANGED_HP));
    }

    @Override
    public void visit(final Rogue rogue) {
        rogue.addAngelsModifiers(Constants.SMALLANGEL_ROGUE_MODIFIER);
        rogue.setCurrentHP(max(0, rogue.getCurrentHP()
                + Constants.SMALLANGEL_ROGUE_CHANGED_HP));
    }

    @Override
    public void visit(final Wizard wizard) {
        wizard.addAngelsModifiers(Constants.SMALLANGEL_WIZARD_MODIFIER);
        wizard.setCurrentHP(max(0, wizard.getCurrentHP()
                + Constants.SMALLANGEL_WIZARD_CHANGED_HP));
    }
}
