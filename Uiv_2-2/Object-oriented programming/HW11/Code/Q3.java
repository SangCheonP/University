import java.util.ArrayList;
import java.util.List;
import java.util.function.IntSupplier;
import java.util.function.IntUnaryOperator;
import java.util.function.Predicate;
import java.util.Random;


public class Q3 {
	static <T> List<Integer> makeRandomList(IntSupplier s, int size){
		List<Integer> list1 = new ArrayList<>();
		for(int i = 0; i < size; i++) {
			list1.add(s.getAsInt());
		}
		return list1;
	}
	
	static void sumDigits(IntUnaryOperator u, List<Integer> list) {
		for(int i = 0; i < list.size(); i++) {
			list.set(i,u.applyAsInt(list.get(i)));
		}
	}
	
	public static void main(String[] args) {
		List<Integer> list = new ArrayList<>();
		IntSupplier is = () -> {
			Random rand = new Random();
			int n = rand.nextInt(100) + 100;
			return n;
		};
		list = makeRandomList(is, 10);
		System.out.println(list);
		
		IntUnaryOperator iu = s -> (s/100) + (s%100)/10 + (s%10);
		sumDigits(iu, list);
		System.out.println(list);
		
		Predicate<Integer> p = s -> s >= 10;
		list.removeIf(p);
		System.out.println(list);
	}
}
