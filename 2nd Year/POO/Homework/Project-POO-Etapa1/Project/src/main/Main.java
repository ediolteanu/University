package main;

import game.Game;
import game.Map;
import utilities.GameInput;

import java.io.IOException;

public final class Main {
    private Main() {
        // just to trick checkstyle
    }

    public static void main(final String[] args) throws IOException {
        GameInput gameInput = new GameInput();
        try {
            gameInput.readFromFile(args);
        } catch (IOException e) {
            e.printStackTrace();
        }

        Map map = Map.getInstance(gameInput.getN(), gameInput.getM(),
                gameInput.getTerrainMap());

        Game game = Game.getInstance(map, gameInput.getHeroes(), gameInput.getRounds());

        game.playGame();
        game.endGame(args[1]);
    }
}
