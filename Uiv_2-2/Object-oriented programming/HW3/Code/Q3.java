class Rectangle{
	private int x;
	private int y;
	private int width;
	private int height;
	
	public Rectangle(int n1, int n2, int n3, int n4) {
		x = n1;
		y = n2;
		width = n3;
		height = n4;
	}
	
	public int square() {
		return width*height;
	}
	
	public void show() {
		System.out.println("(" + x + "," + y + ")에서 크기가 " + width + "x" + height +"인 사각형");
	}
	
	public boolean contains(Rectangle r) {
		if(x < r.x && y < r.y) {
			if((width + x) > (r.x + r.width) && (height + y) > (r.y + r.height)){
				return true;	
			}
		}
		return false;
	}
}

public class Q3 {

	public static void main(String args[]) {
		 Rectangle r = new Rectangle(2, 2, 8, 7);
		 Rectangle s = new Rectangle(5, 5, 6, 6);
		 Rectangle t = new Rectangle(1, 1, 10, 10);
		 r.show();
		 System.out.println("s의 면적은 " + s.square());
		 if (t.contains(r))
		 System.out.println("t는 r을 포함합니다.");
		 if (t.contains(s))
		 System.out.println("t는 s를 포함합니다.");
		 }
}
