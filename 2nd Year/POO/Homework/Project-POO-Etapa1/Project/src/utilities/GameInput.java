package utilities;

import fileio.implementations.FileReader;
import heroes.Hero;
import heroes.Knight;
import heroes.Pyromancer;
import heroes.Rogue;
import heroes.Wizard;

import java.io.IOException;
import java.util.ArrayList;

public final class GameInput {
    private ArrayList<String> terrainMap = new ArrayList<>();
    private int n;
    private int m;
    private int rounds;
    private ArrayList<Hero> heroes = new ArrayList<>();

    public int getN() {
        return n;
    }

    public int getM() {
        return m;
    }

    public ArrayList<String> getTerrainMap() {
        return terrainMap;
    }

    public int getRounds() {
        return rounds;
    }

    public ArrayList<Hero> getHeroes() {
        return heroes;
    }

    public void readFromFile(final String[] args) throws IOException {
        FileReader fileReader = new FileReader(args[0]);
        n = fileReader.nextInt();
        m = fileReader.nextInt();
        for (int i = 0; i < n; i++) {
            terrainMap.add(fileReader.nextWord());
        }
        int heroesNo = fileReader.nextInt();
        for (int i = 0; i < heroesNo; i++) {
            String nameInitial = fileReader.nextWord();
            switch (nameInitial) {
                case "K":
                    Knight knight = new Knight(fileReader.nextInt(), fileReader.nextInt());
                    heroes.add(knight);
                    break;
                case "P":
                    Pyromancer pyromancer = new Pyromancer(fileReader.nextInt(),
                            fileReader.nextInt());
                    heroes.add(pyromancer);
                    break;
                case "R":
                    Rogue rogue = new Rogue(fileReader.nextInt(), fileReader.nextInt());
                    heroes.add(rogue);
                    break;
                case "W":
                    Wizard wizard = new Wizard(fileReader.nextInt(), fileReader.nextInt());
                    heroes.add(wizard);
                    break;
                default:
                    break;
            }
        }
        rounds = fileReader.nextInt();
        for (int i = 0; i < rounds; i++) {
            String moves = fileReader.nextWord();
            for (int j = 0; j < heroesNo; j++) {
                heroes.get(j).getMoves().add(moves.charAt(j));
            }
        }
        fileReader.close();
    }
}
