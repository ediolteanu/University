package multipleProducersMultipleConsumers;

import java.util.concurrent.ArrayBlockingQueue;

public class Buffer {
	int value;
	ArrayBlockingQueue array = new ArrayBlockingQueue<Integer>(10);
	void put(int value) throws InterruptedException {
		array.put(value);
	}

	int get() throws InterruptedException {
		return (int) array.take();
	}
}
