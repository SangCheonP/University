class Song{
	private String Title;
	private String artist;
	private int year;
	private String country;
	
	public Song(String str1, String str2, int yy, String str3) {
		Title = str1;
		artist = str2;
		year = yy;
		country = str3;
	}
	
	public void show() {
		System.out.println(year + "년 " + country + " 국적의 " + artist +"가 부른 " + Title);
	}
}


public class Q2 {

	public static void main(String[] args) {
		Song ss = new Song("Dancing Queen", "ABBA", 1978, "스웨덴");
		ss.show();
	}

}
