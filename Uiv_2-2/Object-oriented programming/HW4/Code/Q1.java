
public class Q1 {

	public static void main(String[] args) {
		String text = "I love you";
		int len = text.length();

		for(int i = 0; i<len; i++) {
			String str1 = text.substring(0,1);
			String str2 = text.substring(1);
			text = str2.concat(str1);
			System.out.println(text);
		}
	}

}
