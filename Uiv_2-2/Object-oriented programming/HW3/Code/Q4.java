class Circle{
	private double radius;
	private String name;
	final double PI = 3.14;
	
	public Circle(String str, double r){
		name = str;
		setRad(r);
	}
	public void setRad(double rad) {
		if(rad <= 0){
			radius = 0;
		}
		else {
			radius = rad;
		}
	}
	
	public String getName() {
		return name;
	}
	
	public double getArea() {
		return radius * radius * PI;
	}
	
	public void show() {
		System.out.println(getName() + "넓이 : " + getArea());
	}
}

public class Q4 {
	public static void main(String[] args) {
		 Circle c1 = new Circle("Pizza", 0);
		 Circle c2 = new Circle("donut", 0);
		 Circle c3 = new Circle("hamburger", 0);
		
		 c1.setRad(12);
		 c2.setRad(-2);
		 c3.setRad(7);
		 
		 c1.show();
		 c2.show();
		 c3.show();
		 
		 
		 if((c1.getArea() > c2.getArea()) && (c1.getArea() > c3.getArea()))
			 System.out.println("가장 큰 면적은 " + c1.getName());
		 else if((c2.getArea() > c1.getArea()) && (c2.getArea() > c3.getArea()))
			 System.out.println("가장 큰 면적은 " + c2.getName());
		 else if((c3.getArea() > c1.getArea()) && (c3.getArea() > c2.getArea()))
			 System.out.println("가장 큰 면적은 " + c3.getName());
	}

}
