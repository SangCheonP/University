package Input;

public class Q1 {

	public static void main(String[] args) {
	
		int count8 = 0;
		int count9 = 0;
		for(int i = 1; i <= 100; i++) {
			if((i % 8) == 0 && (i % 9) ==0) {
				break;
			}
			else if((i % 8) == 0) {
				count8++;
			}
			else if((i % 9) == 0) {
				count9++;
			}
		}
		System.out.println("8의 배수 : " + count8 + "개");
		System.out.println("9의 배수 : " + count9 + "개");
}
	
}