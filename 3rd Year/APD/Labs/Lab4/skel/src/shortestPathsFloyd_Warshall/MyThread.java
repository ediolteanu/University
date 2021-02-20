package shortestPathsFloyd_Warshall;

import java.util.concurrent.BrokenBarrierException;

public class MyThread implements Runnable {
    int P, graph[][], id, start, end;
    MyThread(int id, int graph[][], int P) {
        this.id = id;
        this.graph = graph;
        this.P = P;
    }
    @Override
    public void run() {
        start = (int) (this.id * ((double) graph.length / P));
        end = (int) Math.min((this.id + 1) * ((double) graph.length / P), graph.length);
        for (int k = 0; k < 5; k++) {
            for (int i = start; i < end; i++) {
                for (int j = 0; j < 5; j++) {
                    graph[i][j] = Math.min(graph[i][k] + graph[k][j], graph[i][j]);
                }
            }
            try {
                Main.barrier.await();

            } catch (InterruptedException e) {
                e.printStackTrace();
            } catch (BrokenBarrierException e) {
                e.printStackTrace();
            }

        }
    }
}
