import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.function.Predicate;
import java.util.function.*;

public class Q6 {

	public static void main(String[] args) {
		List<Integer> list = Arrays.asList(3, -1, 2, 4, -1, 1, 2);
		list = new ArrayList<>(list);

		Predicate<Integer> p = s -> s < 0;
		list.removeIf(p);
		System.out.println(list);

		for (int i = 0; i < list.size(); i++) {
			for (int j = 0; j < list.get(i); j++) {
				System.out.print("*");
			}
			System.out.println();
		}

	}

}
