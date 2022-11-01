import java.util.Scanner;

class Dictionary {
	private static String [] kor = 
		{ "사랑", "아기", "돈", "미래", "희망" };
	
	private static String [] eng = 
		{ "love", "baby", "money", "future", "hope" };
	
	public static String kor2Eng(String word) {	
		for(int i = 0; i < kor.length; i++) {
			if(kor[i].equals(word))
				return eng[i];
		}
		return null;
	}
}
public class Q2 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.printf("한영 단어 검색 프로그램입니다.\n");
		while(true){
			System.out.printf("한글 단어?");
			String str = sc.nextLine();
			if(str.equals("그만")){break;}
			String ar = Dictionary.kor2Eng(str);
			if(ar == null)
				System.out.println(str + "는 저의 사전에 없습니다.");
			else
				System.out.println(str + "은 " + ar);
		}
	}
}
