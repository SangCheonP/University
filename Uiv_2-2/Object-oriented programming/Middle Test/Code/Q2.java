class ArrayUtil {
	int[] a;

	ArrayUtil(int[] a) {
		this.a = a;
	}

	public static int[] calc(int[] a, int[] b, int[] c) {
		int[] sum = new int[a.length + b.length];
		for (int i = 0; i < a.length + b.length; i++) {
			if (i < a.length) {
				for(int j =0; j <i; j++) {
					if(sum[j]==a[i]) {
						continue;
					}
				}
				sum[i] = a[i];
			} else {
				sum[i] = b[i - a.length];
			}
		}
		return sum;
	}
}

public class Q2 {

	public static void main(String[] args) {
		int[] A = { 7, 5, 3, 1, -1 };
		int[] B = { 3, 2, 1, 0, -1, -2 };
		int[] C = { 7, 4, 1, -2 };
		int[] R = ArrayUtil.calc(A, B, C);
		System.out.print("(A U B) ∩ C = { " + R[0]);
		for (int i = 1; i < R.length; i++)
			System.out.print(", " + R[i]);
		System.out.println(" }");

	}

}