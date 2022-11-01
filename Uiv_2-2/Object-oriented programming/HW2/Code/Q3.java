package Input;

public class Q3 {

	public static void main(String[] args) {
		char a = 'e';
		int b = (int)a;
		
		for(int i=97; i<=b; b--) {
			for(int j = 97; j <=b; j++) {
				System.out.print((char)j);
				}
			System.out.print('\n');
		}
	}

}
