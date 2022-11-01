import java.util.Scanner;
class count{
	
}
public class Q1 {

	public static void main(String[] args) {
		int length = 0;
		int count = 0;
		Scanner sc = new Scanner(System.in);
		System.out.print("두 개의 정수 입력 : ");
		int n1 = sc.nextInt();
		int n2 = sc.nextInt();
		int cp = n1;
		int cp2 = n1;
		int cp3 = n1;
		while(cp2 != 0) {
			cp2 /= 10;
			++length;
		}
		
		int[] arr = new int[length];
		for(int i =0; i <length; i++) {
			arr[i] = cp%10;
			cp/=10;
		}
		
		while(cp3 != 0) {
			int dig = cp3%10;
			if(dig==n2) {
				++count;
				cp3 /= 10;
			}else {
				cp3 /= 10;
			}
		}
		
		System.out.println("count : " + count);

	}

}
