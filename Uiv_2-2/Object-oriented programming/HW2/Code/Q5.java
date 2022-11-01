package Input;

public class Q5 {

	public static void main(String[] args) {
		for(int i = 0; i<=5; i++) {
			System.out.println("f(" + i +") = " + fac(i));
		}
	}
	public static int fac(int n) {
		if(n == 0)
			return 1;
		else
			return 2*fac(n-1)+1;
	}
}
