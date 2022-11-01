class GQueue<T> {
	int tos;
	static int tos2 = 0;
	Object[] arr;

	public GQueue(int a) {
		tos = 0;
		arr = new Object[a];
	}

	public void enqueue(T data) {
		if(tos == arr.length) {
			return;
		}
		arr[tos] = data;
		tos++;
	}

	public T dequeue() {
		if(tos==arr.length) {
			return null;
		}
		return (T)arr[tos2++];
	}
}

public class Q4 {
	public static void main(String[] args) {
		int size = 10;
		GQueue<String> stringQueue = new GQueue<>(size);
		stringQueue.enqueue("seoul");
		stringQueue.enqueue("busan");
		stringQueue.enqueue("LA");
		for (int i = 0; i < size; i++) {
			String str = stringQueue.dequeue();
			if (str != null)
				System.out.println(str);
		}
		GQueue<Integer> intQueue = new GQueue<>(size);
		intQueue.enqueue(1);
		intQueue.enqueue(2);
		intQueue.enqueue(3);
		for (int i = 0; i < size; i++) {
			Integer is = intQueue.dequeue();
			if (is != null)
				System.out.println(is);
		}
	}
}
