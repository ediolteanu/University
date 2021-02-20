package angels;

import heroes.Knight;
import heroes.Pyromancer;
import heroes.Rogue;
import heroes.Wizard;
import utilities.Constants;

public final class Spawner extends Angel {
    public Spawner(final int roundNo, final int row, final int col) {
        super("Spawner", true, roundNo, row, col);
    }

    @Override
    public void visit(final Knight knight) {
        knight.setDead(false);
        knight.setCurrentHP(Constants.SPAWNER_KNIGHT_SPAWN_HP);
    }

    @Override
    public void visit(final Pyromancer pyromancer) {
        pyromancer.setDead(false);
        pyromancer.setCurrentHP(Constants.SPAWNER_PYROMANCER_SPAWN_HP);
    }

    @Override
    public void visit(final Rogue rogue) {
        rogue.setDead(false);
        rogue.setCurrentHP(Constants.SPAWNER_ROGUE_SPAWN_HP);
    }

    @Override
    public void visit(final Wizard wizard) {
        wizard.setDead(false);
        wizard.setCurrentHP(Constants.SPAWNER_WIZARD_SPAWN_HP);
    }
}
