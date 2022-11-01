class Matrix{
	
	public void printMatrix(int[][]a) {
		for(int i =  0; i<a.length; i++) {
			for(int j = 0; j < a[i].length; j++) {
				System.out.printf("%d ",a[i][j]);
			}
			System.out.println();
		}
		System.out.println();
	}
	public void addMatrix(int[][]a,int[][]b,int[][]c) {
		
		for(int i =  0; i<a.length; i++) {
			for(int j = 0; j < a[i].length; j++) {
				c[i][j] = a[i][j] + b[i][j];
			}
		}
	}
}


public class Q1 {

	public static void main(String[] args) {
		int[][] a = { { 1, 2, 3 }, { 4, 5, 6 } };
		 int[][] b = { { 6, 3, 4 }, { 5, 1, 2 } };
		 int[][] c = new int[2][3];
		 Matrix mx = new Matrix();
		 System.out.println("행렬 a");
		 mx.printMatrix(a);
		 System.out.println("행렬 b");
		 mx.printMatrix(b);
		 System.out.println("행렬 c");
		 mx.addMatrix(a, b, c);
		 mx.printMatrix(c);
	}

}
