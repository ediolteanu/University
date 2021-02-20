package angels;

import heroes.Knight;
import heroes.Pyromancer;
import heroes.Rogue;
import heroes.Wizard;
import utilities.Constants;

public final class DamageAngel extends Angel {

    public DamageAngel(final int roundNo, final int row, final int col) {
        super("DamageAngel", true, roundNo, row, col);
    }

    @Override
    public void visit(final Knight knight) {
        knight.addAngelsModifiers(Constants.DAMAGEANGEL_KNIGHT_MODIFIER);
    }

    @Override
    public void visit(final Pyromancer pyromancer) {
        pyromancer.addAngelsModifiers(Constants.DAMAGEANGEL_PYROMANCER_MODIFIER);
    }

    @Override
    public void visit(final Rogue rogue) {
        rogue.addAngelsModifiers(Constants.DAMAGEANGEL_ROGUE_MODIFIER);
    }

    @Override
    public void visit(final Wizard wizard) {
        wizard.addAngelsModifiers(Constants.DAMAGEANGEL_WIZARD_MODIFIER);
    }
}
