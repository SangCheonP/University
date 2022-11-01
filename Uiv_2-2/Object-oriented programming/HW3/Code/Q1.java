class TV{
	private String TvName;
	private int year;
	private int inchi;
	
	public TV(String str, int yy, int in) {
		TvName = str;
		year = yy;
		inchi = in;
	}
	
	public void show() {
		System.out.println(TvName + "에서 만든 " + year + "년형 "+ inchi + "인치 TV");
}
}

public class Q1 {
	public static void main(String[] args) {
		TV myTV = new TV("LG", 2017, 32);
		myTV.show();
	}

}
