class Circle{
	private int x, y, rad;
	
	public Circle(int n1, int n2, int n3){
		this.x = n1;
		this.y = n2;
		this.rad = n3;
	}
	
	public Circle(int n1, int n2){
		this(n1, n2, 5);
	}
	
	public Circle(int n1){
		this(0, 0, n1);
	}
	
	public String toString() {  //이걸 몰랐음
		return "Circle(" + x + "," + y + ") 반지름" + rad;
	}
	
	public boolean equals(Circle a) {
		if((x == a.x)&&(y == a.y)) {
			return true;
		}
		else
			return false;
	}
}

public class Q4 {
	public static void main(String[] args) {
		Circle a = new Circle(2, 3, 30);
		Circle b = new Circle(5);
		Circle c = new Circle(2, 3);
		System.out.println("원 a : " + a);
		System.out.println("원 b : " + b);
		System.out.println("원 c : " + c);
		if (a.equals(b))
			System.out.println("같은 원");
		else
		 	System.out.println("서로 다른 원");
		if (a.equals(c))
		 	System.out.println("같은 원");
		else
			System.out.println("서로 다른 원");
	}
}
