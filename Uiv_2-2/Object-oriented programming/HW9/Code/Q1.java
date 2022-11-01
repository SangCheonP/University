class GStack<T> {
	int tos;
	Object[] arr;
	
	GStack(int size) {
		tos = 0;
		arr = new Object[size];
	}

	public void push(T data) {
		if(tos == arr.length) {
			return;
		}
		arr[tos] = data;
		tos++;
	}

	public T pop() {
		if(tos==0) {
			return null;
		}
		tos--;
		return (T)arr[tos];
	}
}

public class Q1 {
	public static void main(String[] args) {
		int size = 10;
		GStack<String> stringStack = new GStack<String>(size);
		stringStack.push("seoul");
		stringStack.push("busan");
		stringStack.push("LA");
		for (int i = 0; i < size; i++) {
			String str = stringStack.pop();
			if (str != null)
				System.out.println(str);
		}
		GStack<Integer> intStack = new GStack<Integer>(size);
		intStack.push(1);
		intStack.push(3);
		intStack.push(5);
		for (int i = 0; i < size; i++) {
			Integer is = intStack.pop();
			if (is != null)
				System.out.println(is);
		}
	}
}
