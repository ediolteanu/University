package commands;

import diagram.DiagramCanvas;
import static java.lang.Math.round;

public class Resize implements DrawCommand {
    private DiagramCanvas diagramCanvas;
    private double percent;
    private int componentId;

    public Resize(DiagramCanvas diagramCanvas, int componentId, double percent) {
        this.diagramCanvas = diagramCanvas;
        this.percent = percent;
        this.componentId = componentId;
    }

    @Override
    public void execute() {
        diagramCanvas.getComponent(componentId).setHeight(
                (int) round(diagramCanvas.getComponent(componentId).getHeight() * percent));
        diagramCanvas.getComponent(componentId).setWeight(
                (int) round((diagramCanvas.getComponent(componentId).getWeight() * percent)));
    }

    @Override
    public void undo() {
        diagramCanvas.getComponent(componentId).setWeight(
                (int) round(diagramCanvas.getComponent(componentId).getHeight() / percent));
        diagramCanvas.getComponent(componentId).setWeight(
                (int) round((diagramCanvas.getComponent(componentId).getWeight() / percent)));
    }

    @Override
    public String toString() {
        return "Resize{" +
                "diagramCanvas=" + diagramCanvas +
                ", percent=" + percent +
                ", componentId=" + componentId +
                '}';
    }
}
