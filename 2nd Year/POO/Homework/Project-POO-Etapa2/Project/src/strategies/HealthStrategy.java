package strategies;

import heroes.Knight;
import heroes.Pyromancer;
import heroes.Rogue;
import heroes.Wizard;

public interface HealthStrategy {
    void applyPercentageHealthStrategy(Knight knight);
    void applyPercentageHealthStrategy(Pyromancer pyromancer);
    void applyPercentageHealthStrategy(Rogue rogue);
    void applyPercentageHealthStrategy(Wizard wizard);
}
