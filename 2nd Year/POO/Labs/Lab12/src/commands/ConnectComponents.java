package commands;

import diagram.DiagramCanvas;
import diagram.DiagramComponent;

public class ConnectComponents implements DrawCommand {
    DiagramCanvas diagramCanvas;
    int componentId1;
    int componentId2;

    public ConnectComponents(DiagramCanvas diagramCanvas,
                             int componentId1, int componentId2) {
        this.diagramCanvas = diagramCanvas;
        this.componentId1 = componentId1;
        this.componentId2 = componentId2;
    }

    @Override
    public void execute() {
        diagramCanvas.getComponent(componentId1).connectTo(diagramCanvas.getComponent(componentId2).toString());
        diagramCanvas.getComponent(componentId2).connectTo(diagramCanvas.getComponent(componentId1).toString());
    }

    @Override
    public void undo() {
        diagramCanvas.getComponent(componentId1).removeConnection(diagramCanvas.getComponent(componentId2).toString());
        diagramCanvas.getComponent(componentId2).removeConnection(diagramCanvas.getComponent(componentId1).toString());
    }

    @Override
    public String toString() {
        return "ConnectComponents{" +
                "diagramCanvas=" + diagramCanvas +
                ", componentId1=" + componentId1 +
                ", componentId2=" + componentId2 +
                '}';
    }
}
