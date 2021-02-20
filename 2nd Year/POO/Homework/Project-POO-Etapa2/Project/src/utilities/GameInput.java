package utilities;

import angels.Angel;
import angels.AngelFactory;
import fileio.implementations.FileReader;
import heroes.Hero;
import heroes.HeroFactory;

import java.io.IOException;
import java.util.ArrayList;

public final class GameInput {
    private ArrayList<String> terrainMap = new ArrayList<>();
    private int n;
    private int m;
    private int rounds;
    private ArrayList<Hero> heroes = new ArrayList<>();
    private ArrayList<Angel> angels = new ArrayList<>();

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

    public ArrayList<Angel> getAngels() {
        return angels;
    }

    public void readFromFile(final String[] args) throws IOException {
        FileReader fileReader = new FileReader(args[0]);
        n = fileReader.nextInt();
        m = fileReader.nextInt();
        for (int i = 0; i < n; i++) {
            terrainMap.add(fileReader.nextWord());
        }
        int heroesNo = fileReader.nextInt();
        HeroFactory heroFactory = HeroFactory.getInstance();
        for (int i = 0; i < heroesNo; i++) {
            heroes.add(heroFactory.createHero(i, fileReader.nextWord(),
                    fileReader.nextInt(), fileReader.nextInt()));
        }
        rounds = fileReader.nextInt();
        for (int i = 0; i < rounds; i++) {
            String moves = fileReader.nextWord();
            for (int j = 0; j < heroesNo; j++) {
                heroes.get(j).getMoves().add(moves.charAt(j));
            }
        }
        AngelFactory angelFactory = AngelFactory.getInstance();
        for (int i = 0; i < rounds; i++) {
            int roundAngelsNo = fileReader.nextInt();
            for (int j = 0; j < roundAngelsNo; j++) {
                angels.add(angelFactory.createAngel(i + 1, fileReader.nextWord()));
            }
        }

        fileReader.close();
    }
}
