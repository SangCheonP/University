import java.util.StringTokenizer;
public class Q1 {

	public static void main(String[] args) {
		String s1 = "동해물과 백두산이 마르고 닳도록";
		String s2 = "2020/11/03";
		String s3 = "2020년11월03일";
		
		StringTokenizer st1 = new StringTokenizer(s1);
		int i = 1;
		System.out.println("s1 counts: " + st1.countTokens());
		while(st1.hasMoreTokens()) {
			System.out.println(i++ + " : " + st1.nextToken());
		}
		System.out.println();
		
		StringTokenizer st2 = new StringTokenizer(s2,"/");
		i = 1;
		System.out.println("s1 counts: " + st2.countTokens());
		while(st2.hasMoreTokens()) {
			System.out.println(i++ + " : " + st2.nextToken());
		}
		System.out.println();
		
		StringTokenizer st3 = new StringTokenizer(s3,"년월일");
		i = 1;
		System.out.println("s1 counts: " + st3.countTokens());
		while(st3.hasMoreTokens()) {
			System.out.println(i++ + " : " + st3.nextToken());
		}
	}

}
