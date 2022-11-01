import java.util.Arrays;

class Circle implements Comparable{
	private String name;
	private int rad;
	public Circle(String name, int rad) {
		this.name = name;
		this.rad = rad;
	}
	
	@Override
	public int compareTo(Object o) {
		Circle c = (Circle)o;
		return this.rad - c.rad;
	}
	
	public double getArea() {
		return rad*rad*3.14;
	}
	
	public String toString() {
		return this.name + " " + getArea();
	}
}

public class Q3 {

	public static void main(String[] args) {
		Circle[] c = { new Circle("Cup", 3),
				new Circle("Apple", 4),
				new Circle("Doughnut", 5),
				new Circle("Pizza", 7),
				new Circle("Ball", 2) };
		
		Arrays.sort(c);
		for(Circle a : c) {
			System.out.println(a);
		}
		
		int idx = Arrays.binarySearch(c,new Circle("Apple", 4));
		System.out.println("Index of Apple: " + idx);
	}

}
