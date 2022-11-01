class Point3D extends Point{
	private int z;
	Point3D(int n1, int n2, int n3){
		super(n1, n2);
		this.z = n3;
	}
	public void moveUp() {
		this.z += 1;
	}
	public void moveDown() {
		this.z -= 1;
	}
	public void move(int n1, int n2, int n3) {
		move(n1, n2);
		this.z = n3;
	}
	public String toString() {
		return ("(" + getX() + "," + getY() +"," + z + ")의 점");
	}
}

public class Q2 {

	public static void main(String[] args) {
		Point3D p = new Point3D(1, 2, 3); // x, y, z 값
		System.out.println(p.toString() + "입니다.");
		
		p.moveUp();// z 축으로 위쪽 이동
		System.out.println(p.toString() + "입니다.");
		
		p.moveDown();// z 축으로 위쪽 이동
		p.move(10, 10);// x, y 축으로 이동
		System.out.println(p.toString() + "입니다.");
		
		p.move(100, 100, 100);// x, y, z 축으로 이동
		System.out.println(p.toString() + "입니다.");

	}

}
