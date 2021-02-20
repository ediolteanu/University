package multipleProducersMultipleConsumers;

import java.util.LinkedList;
import java.util.concurrent.Semaphore;

/**
 * @author cristian.chilipirea
 *
 */
public class Buffer {
	LinkedList<Integer> a = new LinkedList<>();
	Semaphore gol = new Semaphore(10);
	Semaphore plin = new Semaphore(0);

	void put(int value) throws InterruptedException {
		gol.acquire();
		synchronized (a) {
			a.add(value);
		}
		plin.release();
	}

	int get() throws InterruptedException {
		plin.acquire();
		gol.release();
		synchronized (a) {
			return a.pop();
		}
	}
}
