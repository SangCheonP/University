
public class Q3 {
	public static void main(String[] args) {
		String text1 = "eW"; 
		String text2 = "LOVE";
		String text3 = "C++";
		String text4 = "	programming.	";
		
		StringBuilder str1 = new StringBuilder(text1);
		str1.reverse();
		str1.append(' ').append(text2.toLowerCase());
		str1.append(' ').append(text3);
		str1.replace(8, 11, "JAVA");
		str1.append(' ').append(text4.trim());
		
		System.out.println(str1.toString());
	}
}
