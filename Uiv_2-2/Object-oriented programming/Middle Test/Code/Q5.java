
public class Q5 {
	public static boolean isNumber(String str) {
		int length = str.length();
		StringBuilder s1 = new StringBuilder(str);
		for(int i = 0; i <length; i++) {
			String s = str.substring(i,i+1);
			System.out.println(s);
			if(s != "1" ||s != "2"||s != "3"||s != "4"||s != "5"||s != "6"||s != "7"||s != "8"||s != "9"||s != "0") {
				return false;
			}
		}
		
		return true;
	}
	
	public static void main(String[] args) {
		String str = "123";
		System.out.println(str + "는 숫자입니까? " + isNumber(str));
		str = "1234x";
		System.out.println(str + "는 숫자입니까? " + isNumber(str));

	}

}
