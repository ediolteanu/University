package angels;

import heroes.Knight;
import heroes.Pyromancer;
import heroes.Rogue;
import heroes.Wizard;
import utilities.Constants;

import static java.lang.Math.max;

public final class Dracula extends Angel {
    public Dracula(final int roundNo, final int row, final int col) {
        super("Dracula", false, roundNo, row, col);
    }

    @Override
    public void visit(final Knight knight) {
        knight.addAngelsModifiers(Constants.DRACULA_KNIGHT_MODIFIER);
        knight.setCurrentHP(max(0, knight.getCurrentHP()
                + Constants.DRACULA_KNIGHT_CHANGED_HP));
    }

    @Override
    public void visit(final Pyromancer pyromancer) {
        pyromancer.addAngelsModifiers(Constants.DRACULA_PYROMANCER_MODIFIER);
        pyromancer.setCurrentHP(max(0, pyromancer.getCurrentHP()
                + Constants.DRACULA_PYROMANCER_CHANGED_HP));
    }

    @Override
    public void visit(final Rogue rogue) {
        rogue.addAngelsModifiers(Constants.DRACULA_ROGUE_MODIFIER);
        rogue.setCurrentHP(max(0, rogue.getCurrentHP()
                + Constants.DRACULA_ROGUE_CHANGED_HP));
    }

    @Override
    public void visit(final Wizard wizard) {
        wizard.addAngelsModifiers(Constants.DRACULA_WIZARD_MODIFIER);
        wizard.setCurrentHP(max(0, wizard.getCurrentHP()
                + Constants.DRACULA_WIZARD_CHANGED_HP));
    }
}
