package game;

import java.util.ArrayList;

public final class Map {
    private static Map instance = null;
    private char[][] mapTerrain;

    private Map(final int n, final int m, final ArrayList<String> terrainMap) {
        mapTerrain = new char[n][m];
        for (int i = 0; i < terrainMap.size(); i++) {
            for (int j = 0; j < terrainMap.get(i).length(); j++) {
                mapTerrain[i][j] = terrainMap.get(i).charAt(j);
            }
        }
    }

    public static Map getInstance(final int n, final int m, final ArrayList<String> terrainMap) {
        if (instance == null) {
            instance = new Map(n, m, terrainMap);
        }
        return instance;
    }

    char[][] getMapTerrain() {
        return mapTerrain;
    }

    TerrainType getTerrainType(final char terrainType) {
        switch (terrainType) {
            case 'W':
                return TerrainType.Woods;

            case 'L':
                return TerrainType.Land;

            case 'V':
                return TerrainType.Volcanic;

            case 'D':
                return TerrainType.Desert;

            default:
                return null;
        }
    }

}
