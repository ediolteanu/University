package doubleVectorElements;

public class MyThread implements Runnable {
    int id, N, v[], P, start, end;

    MyThread(int id, int v[], int N) {
        this.id = id;
        this.N = N;
        this.v = v;
    }

    @Override
    public void run() {
        P = 4;
        start = (int) (id * ((double)(N / P)));
        end = (int) (Math.min((id + 1) * ((double) (N / P)), N));
        for (int i = start; i < end; i++) {
            v[i] = v[i] * 2;
        }
    }
}
