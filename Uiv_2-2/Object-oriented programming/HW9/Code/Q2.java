class PairGen<K, V> {
	private K key;
	private V value;

	PairGen(K key, V value) {
		this.key = key;
		this.value = value;
	}
	
	K getKey() {
		return this.key;
	}
	
	V getValue() {
		return this.value;
	}
}

class CompareGen {
	public static <K, V> boolean compare(PairGen<K, V> p1, PairGen<K, V> p2) {
		if(p1.getKey().equals(p2.getKey()) && p1.getValue().equals(p2.getValue())) {
			return true;
		}
		return false;
	}
}

public class Q2 {
	public static void main(String[] args) {
		PairGen<String, Integer> p1 = new PairGen<>("Apple", 3);
		PairGen<String, Integer> p2 = new PairGen<>("Apple", 3);
		System.out.println(CompareGen.compare(p1, p2));

		PairGen<String, String> p3 = new PairGen<>("객체지향", "Java");
		PairGen<String, String> p4 = new PairGen<>("객체지향", "C++");
		System.out.println(CompareGen.compare(p3, p4));
	}
}
