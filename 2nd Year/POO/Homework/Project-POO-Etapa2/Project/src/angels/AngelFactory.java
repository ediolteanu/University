package angels;

import java.util.StringTokenizer;

public final class AngelFactory {
    private static AngelFactory instance = null;

    private AngelFactory() {
    }

    public static AngelFactory getInstance() {
        if (instance == null) {
            instance = new AngelFactory();
        }
        return instance;
    }

    public Angel createAngel(final int roundNo, final String angelParameters) {
        StringTokenizer stringTokenizer = new StringTokenizer(angelParameters, ",");
        String angelType = stringTokenizer.nextToken();
        int row = Integer.parseInt(stringTokenizer.nextToken());
        int col = Integer.parseInt(stringTokenizer.nextToken());
        switch (angelType) {
            case "DamageAngel":
                return new DamageAngel(roundNo, row, col);
            case "DarkAngel":
                return new DarkAngel(roundNo, row, col);
            case "Dracula":
                return new Dracula(roundNo, row, col);
            case "GoodBoy":
                return new GoodBoy(roundNo, row, col);
            case "LevelUpAngel":
                return new LevelUpAngel(roundNo, row, col);
            case "LifeGiver":
                return new LifeGiver(roundNo, row, col);
            case "SmallAngel":
                return new SmallAngel(roundNo, row, col);
            case "Spawner":
                return new Spawner(roundNo, row, col);
            case "TheDoomer":
                return new TheDoomer(roundNo, row, col);
            case "XPAngel":
                return new XPAngel(roundNo, row, col);
            default:
                return null;
        }
    }
}
