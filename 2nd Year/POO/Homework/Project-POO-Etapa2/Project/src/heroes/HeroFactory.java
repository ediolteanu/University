package heroes;

public final class HeroFactory {
    private static HeroFactory instance = null;

    private HeroFactory() {
    }

    public static HeroFactory getInstance() {
        if (instance == null) {
            instance = new HeroFactory();
        }
        return instance;
    }

    public Hero createHero(final int id, final String heroType, final int row, final int col) {
        switch (heroType) {
            case "K":
                return new Knight(id, row, col);
            case "P":
                return new Pyromancer(id, row, col);
            case "R":
                return new Rogue(id, row, col);
            case "W":
                return new Wizard(id, row, col);
            default:
                return null;
        }
    }
}
