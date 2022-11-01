class Point {
	private int x, y;
	public Point(int x, int y) {
		this.x = x;
		this.y = y;
	}
	public int getX() { return x; }
	public int getY() { return y; }
	protected void move(int x, int y) {
		this.x = x;
		this.y = y;
	}
}

class ColorPoint extends Point{
	private String color;
	ColorPoint(int n1, int n2, String str){
		super(n1,n2);
		this.color = str;
	}
	public void setXY(int n1, int n2) {
		move(n1, n2);
	}
	public void setColor(String str) {
		this.color = str;
	}
	public String toString() {
		return (color + "색의 (" + getX() + "," + getY() + ")의 점");
	}
	
}

public class Q1 {

	public static void main(String[] args) {
		ColorPoint cp = new ColorPoint(5, 5, "Yellow");
		cp.setXY(10, 20);
		cp.setColor("Red");
		String str = cp.toString();
		System.out.println(str + "입니다.");
	}
}
