package utilities;

public final class Constants {
    private Constants() {
        //just to trick checkstyle
    }

    public static final int INITIAL_XP = 0;
    public static final int XP_NEEDED_FOR_LEVEL_1 = 250;
    public static final int XP_NEEDED_PER_LEVEL = 50;
    public static final int INITIAL_LEVEL = 0;
    public static final int UPDATE_XP_COMPARE_VALUE = 200;
    public static final int UPDATE_XP_MULTIPLIER_VALUE = 40;

    //PYROMANCER
    public static final int PYROMANCER_INITIAL_HP = 500;
    public static final int PYROMANCER_BONUS_LEVEL_HP = 50;

    public static final int FIREBLAST_BASE_DMG = 350;
    public static final int FIREBLAST_BONUS_LEVEL_DMG = 50;
    public static final float FIREBLAST_ROGUE_MODIFIER = -0.2f;
    public static final float FIREBLAST_KNIGHT_MODIFIER = 0.2f;
    public static final float FIREBLAST_PYROMANCER_MODIFIER = -0.1f;
    public static final float FIREBLAST_WIZARD_MODIFIER = 0.05f;

    public static final int IGNITE_BASE_DMG = 150;
    public static final int IGNITE_BONUS_LEVEL_BASE_DMG = 20;
    public static final int IGNITE_ROUND_DMG = 50;
    public static final int IGNITE_BONUS_LEVEL_ROUND_DMG = 30;
    public static final int IGNITE_ROUNDS = 2;
    public static final float IGNITE_ROGUE_MODIFIER = -0.2f;
    public static final float IGNITE_KNIGHT_MODIFIER = 0.2f;
    public static final float IGNITE_PYROMANCER_MODIFIER = -0.1f;
    public static final float IGNITE_WIZARD_MODIFIER = 0.05f;

    public static final float PYROMANCER_VOLCANIC_MODIFIER = 0.25f;

    //KNIGHT
    public static final int KNIGHT_INITIAL_HP = 900;
    public static final int KNIGHT_BONUS_LEVEL_HP = 80;

    public static final int EXECUTE_BASE_DMG = 200;
    public static final int EXECUTE_BONUS_LEVEL_DMG = 30;
    public static final float EXECUTE_HP_LIMIT = 0.2f;
    public static final float EXECUTE_BONUS_LEVEL_HP_LIMIT = 0.01f;
    public static final float EXECUTE_MAX_HP_LIMIT = 0.4f;
    public static final float EXECUTE_ROGUE_MODIFIER = 0.15f;
    public static final float EXECUTE_KNIGHT_MODIFIER = 0.0f;
    public static final float EXECUTE_PYROMANCER_MODIFIER = 0.1f;
    public static final float EXECUTE_WIZARD_MODIFIER = -0.2f;

    public static final int SLAM_BASE_DMG = 100;
    public static final int SLAM_BONUS_LEVEL_DMG = 40;
    public static final int SLAM_SNARE_ROUNDS = 1;
    public static final float SLAM_ROGUE_MODIFIER = -0.2f;
    public static final float SLAM_KNIGHT_MODIFIER = 0.2f;
    public static final float SLAM_PYROMANCER_MODIFIER = -0.1f;
    public static final float SLAM_WIZARD_MODIFIER = 0.05f;

    public static final float KNIGHT_LAND_MODIFIER = 0.15f;

    //WIZARD
    public static final int WIZARD_INITIAL_HP = 400;
    public static final int WIZARD_BONUS_LEVEL_HP = 30;

    public static final float DRAIN_BASE_PERCENT = 0.2f;
    public static final float DRAIN_BONUS_LEVEL_PERCENT = 0.05f;
    public static final float DRAIN_OPPONENT_MAX_HP_PERCENT = 0.3f;
    public static final float DRAIN_ROGUE_MODIFIER = -0.2f;
    public static final float DRAIN_KNIGHT_MODIFIER = 0.2f;
    public static final float DRAIN_PYROMANCER_MODIFIER = -0.1f;
    public static final float DRAIN_WIZARD_MODIFIER = 0.05f;

    public static final float DEFLECT_BASE_PERCENT = 0.35f;
    public static final float DEFLECT_BONUS_LEVEL_PERCENT = 0.02f;
    public static final float DEFLECT_MAX_PERCENT = 0.7f;
    public static final float DEFLECT_ROGUE_MODIFIER = 0.2f;
    public static final float DEFLECT_KNIGHT_MODIFIER = 0.4f;
    public static final float DEFLECT_PYROMANCER_MODIFIER = 0.3f;

    public static final float WIZARD_DESERT_MODIFIER = 0.1f;

    //ROGUE
    public static final int ROGUE_INITIAL_HP = 600;
    public static final int ROGUE_BONUS_LEVEL_HP = 40;

    public static final int BACKSTAB_BASE_DMG = 200;
    public static final int BACKSTAB_BONUS_LEVEL_DMG = 20;
    public static final int BACKSTAB_CRIT_COUNTER = 3;
    public static final float BACKSTAB_WOODS_CRIT_MULTIPLIER = 1.5f;
    public static final float BACKSTAB_ROGUE_MODIFIER = 0.2f;
    public static final float BACKSTAB_KNIGHT_MODIFIER = -0.1f;
    public static final float BACKSTAB_PYROMANCER_MODIFIER = 0.25f;
    public static final float BACKSTAB_WIZARD_MODIFIER = 0.25f;

    public static final int PARALYSIS_ROUND_DMG = 40;
    public static final int PARALYSIS_BONUS_LEVEL_ROUND_DMG = 10;
    public static final int PARALYSIS_OVERTIME_ROUNDS = 3;
    public static final int PARALYSIS_OVERTIME_ROUNDS_WOODS = 6;
    public static final float PARALYSIS_ROGUE_MODIFIER = -0.1f;
    public static final float PARALYSIS_KNIGHT_MODIFIER = -0.2f;
    public static final float PARALYSIS_PYROMANCER_MODIFIER = 0.2f;
    public static final float PARALYSIS_WIZARD_MODIFIER = 0.25f;

    public static final float ROGUE_WOODS_MODIFIER = 0.15f;
}
