import java.util.SortedSet;
import java.util.TreeSet;

public class Q3 {
	public static void main(String[] args) {
		TreeSet<Integer> set = new TreeSet<Integer>();
		SortedSet subset;
		set.add(80);
		set.add(100);
		set.add(70);
		set.add(85);
		set.add(98);
		set.add(83);
		
		Integer num = 0;
		
		num = set.first();
		System.out.println("가장 낮은 점수 : " + num);
		num = set.last();
		System.out.println("가장 높은 점수 : " + num);
		num = set.lower(90);
		System.out.println("90점 아래 점수 : " + num);
		num = set.higher(90);
		System.out.println("90점 위 점수 : " + num);
		subset = set.subSet(70, 90);
		System.out.println("70점부터 90점 사이 점수 : " + subset);
		subset = set.headSet(85);
		System.out.println("85점 까지의 점수 : " + subset);
		subset = set.tailSet(85);
		System.out.println("85점 이상의 점수 : " + subset);
	}
}
