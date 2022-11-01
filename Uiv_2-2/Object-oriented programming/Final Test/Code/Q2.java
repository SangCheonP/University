public class Q2 {
	public static void main(String[] args) {
		StringBuffer sb = new StringBuffer("Hello Java");
		System.out.println("용량: " + sb.capacity());
		System.out.println("길이: " + sb.length());
		sb.append("!!!!!");
		System.out.println("추가: " + sb);
		sb.insert(6, "C++ & ");
		System.out.println("삽입: " + sb);
		StringBuffer str = sb.delete(5, 27);
		System.out.println("삭제: " + str);
		System.out.println("용량: " + sb.capacity());
		System.out.println("길이: " + sb.length());
		System.out.println("용량: " + str.capacity());
		System.out.println("길이: "+ str.length());
	}
}