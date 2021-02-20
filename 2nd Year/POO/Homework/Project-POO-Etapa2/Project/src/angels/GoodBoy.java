package angels;

import heroes.Knight;
import heroes.Pyromancer;
import heroes.Rogue;
import heroes.Wizard;
import utilities.Constants;

import static java.lang.Math.max;

public final class GoodBoy extends Angel {
    public GoodBoy(final int roundNo, final int row, final int col) {
        super("GoodBoy", true, roundNo, row, col);
    }

    @Override
    public void visit(final Knight knight) {
        knight.addAngelsModifiers(Constants.GOODBOY_KNIGHT_MODIFIER);
        knight.setCurrentHP(max(0, knight.getCurrentHP()
                + Constants.GOODBOY_KNIGHT_CHANGED_HP));
    }

    @Override
    public void visit(final Pyromancer pyromancer) {
        pyromancer.addAngelsModifiers(Constants.GOODBOY_PYROMANCER_MODIFIER);
        pyromancer.setCurrentHP(max(0, pyromancer.getCurrentHP()
                + Constants.GOODBOY_PYROMANCER_CHANGED_HP));
    }

    @Override
    public void visit(final Rogue rogue) {
        rogue.addAngelsModifiers(Constants.GOODBOY_ROGUE_MODIFIER);
        rogue.setCurrentHP(max(0, rogue.getCurrentHP()
                + Constants.GOODBOY_ROGUE_CHANGED_HP));
    }

    @Override
    public void visit(final Wizard wizard) {
        wizard.addAngelsModifiers(Constants.GOODBOY_WIZARD_MODIFIER);
        wizard.setCurrentHP(max(0, wizard.getCurrentHP()
                + Constants.GOODBOY_WIZARD_CHANGED_HP));
    }
}
