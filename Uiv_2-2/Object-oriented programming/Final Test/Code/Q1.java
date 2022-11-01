class pa{
	public static int addAll(Integer...a) {
		int sum = 0;
		for(int s : a) {
			sum += s;
		}
		return sum;
	}
}

public class Q1 {

	public static void main(String[] args) {
		pa p = new pa();
		System.out.println("totalSum=" + p.addAll(p.addAll(1),p.addAll(1,2),p.addAll(1,2,3),p.addAll(1,2,3,4),p.addAll(1,2,3,4,5),p.addAll(1,2,3,4,5,6),p.addAll(1,2,3,4,5,6,7),p.addAll(1,2,3,4,5,6,7,8),p.addAll(1,2,3,4,5,6,7,8,9),p.addAll(1,2,3,4,5,6,7,8,9,10)));
	}

}
