package game;

import heroes.Hero;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public final class Game {
    private static Game instance = null;
    private Map map;
    private int rounds;
    private ArrayList<Hero> heroes;

    private Game(final Map map, final ArrayList<Hero> heroes, final int rounds) {
        this.map = map;
        this.heroes = heroes;
        this.rounds = rounds;
    }

    public static Game getInstance(final Map map, final ArrayList<Hero> heroes, final int rounds) {
        if (instance == null) {
            instance = new Game(map, heroes, rounds);
        }
        return instance;
    }

    private void applyOverTimeAbilities(final Hero hero, final int round) {
        if (hero.getRemainingSlamRounds() > 0) {
            hero.setRemainingSlamRounds(hero.getRemainingSlamRounds() - 1);
        } else if (hero.getRemainingParalysisRounds() > 0) {
            hero.setRemainingParalysisRounds(hero.getRemainingParalysisRounds() - 1);
            hero.setCurrentHP(hero.getCurrentHP() - hero.getParalysisDamage());
        } else {
            hero.updatePosition(round);
        }
        if (hero.getRemainingIgniteRounds() > 0) {
            hero.setRemainingIgniteRounds(hero.getRemainingIgniteRounds() - 1);
            hero.setCurrentHP(hero.getCurrentHP() - hero.getIgniteDamage());
        }
        if (hero.getCurrentHP() <= 0) {
            hero.setDead(true);
        }
    }

    private void fight1v1(final Hero hero1, final Hero hero2,
                          final int row, final int col) {

        int dmg1 = hero1.calculateDamageBeforeRaceModifiers(hero2,
                map.getTerrainType(map.getMapTerrain()[row][col]));
        int dmg2 = hero2.calculateDamageBeforeRaceModifiers(hero1,
                map.getTerrainType(map.getMapTerrain()[row][col]));
        hero1.accept(hero2,
                map.getTerrainType(map.getMapTerrain()[row][col]), dmg1);
        hero2.accept(hero1,
                map.getTerrainType(map.getMapTerrain()[row][col]), dmg2);
        hero1.setHasFought(true);
        hero2.setHasFought(true);
    }

    private void fightAftermath(final Hero hero1, final Hero hero2) {
        if (hero1.isDead() && hero2.isDead()) {
            hero1.setWinnerXp(hero2);
            hero2.setWinnerXp(hero1);
        } else if (hero1.isDead()) {
            hero2.setWinnerXp(hero1);
            int ret = hero2.updateLevel();
            if (ret == 1) {
                hero2.updateTotalHP();
            }
        } else if (hero2.isDead()) {
            hero1.setWinnerXp(hero2);
            int ret = hero1.updateLevel();
            if (ret == 1) {
                hero1.updateTotalHP();
            }
        }
    }

    public void playGame() {
        for (int i = 0; i < rounds; i++) {
            for (Hero hero : heroes) {
                hero.resetHasFought();
                applyOverTimeAbilities(hero, i);
            }
            for (Hero hero1 : heroes) {
                if (!hero1.isDead() && hero1.getHasFought()) {
                    int row1 = hero1.getRow();
                    int col1 = hero1.getCol();
                    for (Hero hero2 : heroes) {
                        if ((hero2 != hero1) && (!hero2.isDead() && (hero2.getHasFought()))) {
                            int row2 = hero2.getRow();
                            int col2 = hero2.getCol();
                            if ((row1 == row2) && (col1 == col2)) {
                                fight1v1(hero1, hero2, row1, col1);
                                fightAftermath(hero1, hero2);
                            }
                        }
                    }
                }
            }

        }
    }

    public void endGame(final String outputPath) throws IOException {
        File outputFile = new File(outputPath);
        FileWriter fileWriter = new FileWriter(outputFile);
        for (Hero hero : heroes) {
            fileWriter.write(hero.toString());
            fileWriter.flush();
        }
        fileWriter.close();
    }
}
