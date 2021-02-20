package commands;

import diagram.DiagramCanvas;
import diagram.DiagramComponent;

public class DrawRectangle implements DrawCommand {
    private DiagramCanvas diagramCanvas;
    private DiagramComponent diagramComponent;
    public DrawRectangle(DiagramCanvas diagramCanvas) {
        this.diagramCanvas = diagramCanvas;
        this.diagramComponent = new DiagramComponent();
    }

    @Override
    public void execute() {
        diagramCanvas.addComponent(diagramComponent);
    }

    @Override
    public void undo() {
        diagramCanvas.removeComponent(diagramComponent);
    }

    @Override
    public String toString() {
        return "DrawRectangle{" +
                "diagramCanvas=" + diagramCanvas + '\'' +
                '}';
    }
}
