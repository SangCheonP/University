class Shape{
	private String name;
	Shape(String name){
		this.name = name;
	}
	public String getName() {
		return name;
	}
	public double getArea() {
		return 0;
	}
}

class Circle extends Shape{
	private double radius;
	Circle(String name, int radius){
		super(name);
		this.radius = radius;
	}
	public double getArea() {
		return 3.14*radius*radius;
	}
}

class Rectangle extends Shape{
	private double x;
	private double y;
	Rectangle(String name, double x, double y){
		super(name);
		this.x = x;
		this.y = y;
	}
	public double getArea() {
		return x*y;
	}
}

class Triangle extends Shape{
	private double x;
	private double h;
	Triangle(String name, double x, double h){
		super(name);
		this.x = x;
		this.h = h;
	}
	public double getArea() {
		return x*h/2;
	}
}

public class Q3 {

	public static void main(String[] args) {
		Shape[] arr = { new Circle("Circle", 5),
						new Rectangle("Rectangle", 3, 4),
						new Triangle("Triangle", 5, 5)
						};

		double sum = 0;
		for (Shape a : arr) {
			System.out.println(a.getName() + "면적 : " + a.getArea());
			sum += a.getArea();
		 }
		 System.out.println("면적의 합 : " + sum);
	}

}
