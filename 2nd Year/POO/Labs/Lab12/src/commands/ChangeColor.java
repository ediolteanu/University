package commands;

import diagram.DiagramCanvas;

public class ChangeColor implements DrawCommand {
    private DiagramCanvas diagramCanvas;
    private int componentId;
    private String color;
    private String oldColor;
    public ChangeColor(DiagramCanvas diagramCanvas, int componentId, String color) {
        this.diagramCanvas = diagramCanvas;
        this.color = color;
        this.componentId = componentId;
    }


    @Override
    public void execute() {
        oldColor = diagramCanvas.getComponent(componentId).getColor();
        diagramCanvas.getComponent(componentId).setColor(color);
    }

    @Override
    public void undo() {
        diagramCanvas.getComponent(componentId).setColor(oldColor);
    }

    @Override
    public String toString() {
        return "ChangeColor{" +
                "diagramCanvas=" + diagramCanvas +
                ", componentId=" + componentId +
                ", color='" + color + '\'' +
                '}';
    }
}
