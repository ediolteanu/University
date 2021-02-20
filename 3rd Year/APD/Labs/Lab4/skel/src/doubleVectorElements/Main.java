package doubleVectorElements;

/**
 * @author cristian.chilipirea
 *
 */
public class Main {

	public static void main(String[] args) {
		int N = 100000013;
		int cores = Runtime.getRuntime().availableProcessors();
		int v[] = new int[N];
		Thread threads[] = new Thread[cores];
		for(int i=0;i<N;i++)
			v[i]=i;

		for (int i = 0; i < cores; i++)
			threads[i] = new Thread(new MyThread(i, v, N));
		for (int i = 0; i < cores; i++)
			threads[i].start();
		for (int i = 0; i < cores; i++) {
			try {
				threads[i].join();
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}

		// Parallelize me
		/*for (int i = 0; i < N; i++) {
			v[i] = v[i] * 2;
		}*/

		for (int i = 0; i < N; i++) {
			if(v[i]!= i*2) {
				System.out.println("Wrong answer");
				System.exit(1);
			}
		}
		System.out.println("Correct");
	}

}
