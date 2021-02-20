package angels;

import heroes.Knight;
import heroes.Pyromancer;
import heroes.Rogue;
import heroes.Wizard;

public final class TheDoomer extends Angel {
    public TheDoomer(final int roundNo, final int row, final int col) {
        super("TheDoomer", false, roundNo, row, col);
    }

    @Override
    public void visit(final Knight knight) {
        knight.setCurrentHP(0);
        knight.setDead(true);
    }

    @Override
    public void visit(final Pyromancer pyromancer) {
        pyromancer.setCurrentHP(0);
        pyromancer.setDead(true);
    }

    @Override
    public void visit(final Rogue rogue) {
        rogue.setCurrentHP(0);
        rogue.setDead(true);
    }

    @Override
    public void visit(final Wizard wizard) {
        wizard.setCurrentHP(0);
        wizard.setDead(true);
    }
}
