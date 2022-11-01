interface Shape {
	final double PI = 3.14;

	void draw();

	double getArea();
}

class Circle implements Shape{
	private int rad;
	public Circle(int a) {
		this.rad = a;
	}
	
	public void draw() {
		System.out.println("반지름이 " + rad + "인 원입니다.");
	}
	
	public double getArea() {
		return this.rad*this.rad*PI;
	}
}

class Oval implements Shape{
	private int x;
	private int y;
	public Oval(int a, int b) {
		this.x = a;
		this.y = b;
	}
	
	public void draw() {
		System.out.println(x + "x" + y + "에 내접하는 타원입니다.");
	}
	
	public double getArea() {
		return PI*this.x*this.y;
	}
}

class Rect implements Shape{
	private int x;
	private int y;
	public Rect(int a, int b) {
		this.x = a;
		this.y = b;
	}
	
	public void draw() {
		System.out.println(x + "x" + y + "크기의 사각형입니다.");
	}
	
	public double getArea() {
		return this.x*this.y;
	}
}

public class Q3 {
	static public void main(String[] args) {
		Shape[] list = { new Circle(20), new Oval(20, 30), new Rect(20, 30) };
		for (Shape a : list)
			a.draw();
		for (Shape a : list)
			System.out.println("면적은 " + a.getArea());
	}
}
