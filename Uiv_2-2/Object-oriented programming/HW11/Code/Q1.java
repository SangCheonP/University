enum Company{
	AMAZON(170), APPLE(165), GOOGLE(136), FACEBOOK(101), MICROSOFT(91);
	
	private int val;
	private Company(int n) {
		this.val = n;
	}
	
	@Override
	public String toString() {
		return (this.ordinal()+1) + "위 " + this.name() + " 기업가치 " + val + "조";
	}
}

public class Q1 {
	public static void main(String[] args) {
		showAll("FACEBOOK");
		showAll("APPLE", "MICROSOFT");
		showAll("AMAZON", "APPLE", "GOOGLE");
	}
	
	public static void showAll(String...str) {
		for(int i = 0; i < str.length; i++) {
			System.out.println(Company.valueOf(str[i]));
		}
		System.out.println("세계 기업가치 Top5 중에서 " + str.length + "개 기업이 있습니다.");
		System.out.println();
	}
}