package Input;

public class Q2 {

	public static void main(String[] args) {
		for(int i = 2; i <10; i++) {
			for(int j = 1; j <= i; j++) {
				System.out.print(i +"x" + j +"=" + (i*j) + '\t');
			}
			System.out.print("\n");
		}

	}

}
