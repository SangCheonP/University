import java.util.Random;
public class Q2 {

	public static void main(String[] args) {
		Random rand = new Random();
		int[] ar = new int[10];
		int num = 0;
		for(int i = 0; i < 100; i++) {
			num = rand.nextInt(10);
			System.out.print(num);
			ar[num] += 1;
			if(i%20==19) {
				System.out.println();
			}
		}
		System.out.println();
		printGraph(ar);
	}
	
	public static void printGraph(int[] a) {
		for(int i = 0; i < a.length; i++) {
			System.out.print(i + "개수:");
			for(int j = 0; j < a[i]; j ++) {
				System.out.print("*");
			}
			System.out.println();
		}
	}

}
