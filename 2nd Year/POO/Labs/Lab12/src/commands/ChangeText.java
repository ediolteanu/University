package commands;

import diagram.DiagramCanvas;
import diagram.DiagramComponent;

public class ChangeText implements DrawCommand {
    private DiagramCanvas diagramCanvas;
    private int componentId;
    private String text;
    private String oldText;
    public ChangeText(DiagramCanvas diagramCanvas, int componentId, String text) {
        this.diagramCanvas = diagramCanvas;
        this.text = text;
        this.componentId = componentId;
    }


    @Override
    public void execute() {
        oldText = diagramCanvas.getComponent(componentId).getText();
        diagramCanvas.getComponent(componentId).setText(text);
    }

    @Override
    public void undo() {
        diagramCanvas.getComponent(componentId).setText(oldText);
    }

    @Override
    public String toString() {
        return "ChangeText{" +
                "diagramCanvas=" + diagramCanvas +
                ", componentId=" + componentId +
                ", text='" + text + '\'' +
                '}';
    }
}
