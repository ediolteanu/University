package angels;

import heroes.Knight;
import heroes.Pyromancer;
import heroes.Rogue;
import heroes.Wizard;
import utilities.Constants;

public final class LevelUpAngel extends Angel {
    public LevelUpAngel(final int roundNo, final int row, final int col) {
        super("LevelUpAngel", true, roundNo, row, col);
    }

    @Override
    public void visit(final Knight knight) {
        knight.addAngelsModifiers(Constants.LEVELUPANGEL_KNIGHT_MODIFIER);
        knight.setXp(Constants.XP_NEEDED_FOR_LEVEL_1
                + knight.getLevel() * Constants.XP_NEEDED_PER_LEVEL);
    }

    @Override
    public void visit(final Pyromancer pyromancer) {
        pyromancer.addAngelsModifiers(Constants.LEVELUPANGEL_PYROMANCER_MODIFIER);
        pyromancer.setXp(Constants.XP_NEEDED_FOR_LEVEL_1
                + pyromancer.getLevel() * Constants.XP_NEEDED_PER_LEVEL);
    }

    @Override
    public void visit(final Rogue rogue) {
        rogue.addAngelsModifiers(Constants.LEVELUPANGEL_ROGUE_MODIFIER);
        rogue.setXp(Constants.XP_NEEDED_FOR_LEVEL_1
                + rogue.getLevel() * Constants.XP_NEEDED_PER_LEVEL);
    }

    @Override
    public void visit(final Wizard wizard) {
        wizard.addAngelsModifiers(Constants.LEVELUPANGEL_WIZARD_MODIFIER);
        wizard.setXp(Constants.XP_NEEDED_FOR_LEVEL_1
                + wizard.getLevel() * Constants.XP_NEEDED_PER_LEVEL);
    }
}
