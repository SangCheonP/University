import java.util.ArrayList;
import java.util.Collections;

class Mp3File implements Comparable<Mp3File>{
	private String song;
	private String singer;
	Mp3File(String a, String b){
		this.song = a;
		this.singer = b;
	}
	
	public int compareTo(Mp3File m1, Mp3File m2) {
		return m1.singer.compareTo(m2.singer);
	}
}

public class Q5 {
	public static void main(String[] args) {
		ArrayList<Mp3File> list = new ArrayList<>();
		list.add(new Mp3File("Santa Tell Me", "Ariana Grande"));
		list.add(new Mp3File("Last Christmas", "Wham"));
		list.add(new Mp3File("Snowman", "Sia"));
		Collections.sort(list);
		System.out.println("- 정렬 1");
		for (Mp3File s : list)
			System.out.println(s);
		System.out.println("- 정렬 2");
		Collections.sort(list, (Mp3File m1, Mp3File m2) -> m1.song.compareTo(m2.song));
		for (Mp3File s : list)
			System.out.println(s);
	}
}
