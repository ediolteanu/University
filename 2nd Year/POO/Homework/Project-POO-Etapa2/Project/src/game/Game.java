package game;

import angels.Angel;
import angels.Spawner;
import heroes.Hero;
import utilities.Constants;
import utilities.GreatMagician;

import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Observable;

public final class Game extends Observable {
    private static Game instance = null;
    private Map map;
    private int rounds;
    private ArrayList<Hero> heroes;
    private ArrayList<Angel> angels;

    private Game(final Map map,
                 final ArrayList<Hero> heroes,
                 final ArrayList<Angel> angels,
                 final int rounds) {
        this.map = map;
        this.heroes = heroes;
        this.rounds = rounds;
        this.angels = angels;
    }

    public static Game getInstance(final Map map,
                                   final ArrayList<Hero> heroes,
                                   final ArrayList<Angel> angels,
                                   final int rounds) {
        if (instance == null) {
            instance = new Game(map, heroes, angels, rounds);
        }
        return instance;
    }

    private void applyOverTimeAbilities(final Hero hero, final int round) {
        if (hero.getRemainingSlamRounds() > 0) {
            hero.setRemainingSlamRounds(hero.getRemainingSlamRounds() - 1);
            if (hero.getCurrentHP() <= 0) {
                hero.setDead(true);
            }
        } else if (hero.getRemainingParalysisRounds() > 0) {
            hero.setRemainingParalysisRounds(hero.getRemainingParalysisRounds() - 1);
            hero.setCurrentHP(hero.getCurrentHP() - hero.getParalysisDamage());
            if (hero.getCurrentHP() <= 0) {
                hero.setDead(true);
            }
        } else {
            if (hero.getRemainingIgniteRounds() > 0) {
                hero.setRemainingIgniteRounds(hero.getRemainingIgniteRounds() - 1);
                hero.setCurrentHP(hero.getCurrentHP() - hero.getIgniteDamage());
            }
            if (hero.getCurrentHP() <= 0) {
                hero.setDead(true);
            } else {
                hero.applyStrategy();
                hero.updatePosition(round);
            }
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
            if (hero1.getId() > hero2.getId()) {
                hero1.notifyObservers(Constants.CASE_KBP, hero2);
                hero2.notifyObservers(Constants.CASE_KBP, hero1);
            } else {
                hero2.notifyObservers(Constants.CASE_KBP, hero1);
                hero1.notifyObservers(Constants.CASE_KBP, hero2);
            }
            hero1.setWinnerXp(hero2);
            hero2.setWinnerXp(hero1);
            hero1.updateLevel();
            hero2.updateLevel();
        } else if (hero1.isDead()) {
            hero1.notifyObservers(Constants.CASE_KBP, hero2);
            hero2.setWinnerXp(hero1);
            int ret = hero2.updateLevel();
            if (ret == 1) {
                hero2.updateTotalHP();
            }
        } else if (hero2.isDead()) {
            hero2.notifyObservers(Constants.CASE_KBP, hero1);
            hero1.setWinnerXp(hero2);
            int ret = hero1.updateLevel();
            if (ret == 1) {
                hero1.updateTotalHP();
            }
        }
    }

    private void spawnAngels(final int roundNo) {
        for (Angel angel : angels) {
            if (angel.getRoundNo() == roundNo) {
                angel.notifyObservers(Constants.CASE_SPAWNED, angel);
                for (Hero hero : heroes) {
                    if ((hero.getCol() == angel.getCol())
                            && hero.getRow() == angel.getRow()) {
                        if (!hero.isDead()) {
                            if (!(angel instanceof Spawner)) {
                                hero.accept(angel);
                                if (angel.isGood()) {
                                    angel.notifyObservers(Constants.CASE_HELPED, hero);
                                } else {
                                    angel.notifyObservers(Constants.CASE_HIT, hero);
                                }
                                if (hero.getCurrentHP() <= 0) {
                                    hero.notifyObservers(Constants.CASE_KBA, hero);
                                    hero.setDead(true);
                                } else {
                                    int ret = hero.updateLevel();
                                    if (ret == 1) {
                                        hero.updateTotalHP();
                                    }
                                }
                            }
                        } else if (angel instanceof Spawner) {
                            hero.accept(angel);
                            angel.notifyObservers(Constants.CASE_HELPED, hero);
                            hero.notifyObservers(Constants.CASE_SPAWNED, hero);
                        }
                    }
                }
            }
        }
    }

    public void playGame(final FileWriter fileWriter) throws IOException {
        GreatMagician greatMagician = GreatMagician.getInstance(fileWriter);
        for (Hero hero : heroes) {
            hero.addObserver(greatMagician);
        }
        for (Angel angel : angels) {
            angel.addObserver(greatMagician);
        }
        for (int i = 0; i < rounds; i++) {
            fileWriter.write("~~ Round " + (i + 1) + " ~~\n");
            fileWriter.flush();
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
            spawnAngels(i + 1);
            fileWriter.write("\n");
            fileWriter.flush();
        }
    }

    public void endGame(final FileWriter fileWriter) throws IOException {
        fileWriter.write("~~ Results ~~\n");
        for (Hero hero : heroes) {
            fileWriter.write(hero.toString());
            fileWriter.flush();
        }
    }
}
