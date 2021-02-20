package utilities;


import java.io.FileWriter;
import java.io.IOException;
import java.util.Observable;
import java.util.Observer;

public final class GreatMagician implements Observer {
    private static GreatMagician instance = null;
    private FileWriter fileWriter;

    private GreatMagician(final FileWriter fileWriter) {
        this.fileWriter = fileWriter;
    }

    public static GreatMagician getInstance(final FileWriter fileWriter) {
        if (instance == null) {
            instance = new GreatMagician(fileWriter);
        }
        return instance;
    }

    @Override
    public void update(final Observable o, final Object arg) {
        try {
            fileWriter.write(arg.toString());
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
