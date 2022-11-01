import java.util.Scanner;

class Day {
	private String work; // 하루의 할 일을 나타내는 문자열
	public void set(String work) { this.work = work; }
	public String get() { return work; }
	public void show() {
		if(work == null)
			System.out.println("없습니다.");
		else
			System.out.println(work + "입니다.");
	}
}

class MonthSchedule{
	private int nDays;
	private Day[] days;
	private Scanner scanner;
	
	MonthSchedule(int nDays){
		this.nDays = nDays;
		this.days = new Day[nDays];
		for(int i = 0; i < nDays; i++) {
			days[i] = new Day();
		}
		scanner = new Scanner(System.in);
	}
	
	public void input() {
		System.out.printf("날짜(1~%d)?",nDays);
		int n = scanner.nextInt();
		n--;
		if(n<0 || n>=nDays) {
			System.out.println("날짜를 잘못 입력하였습니다.");
			return;
		}
		if(days[n].get() != null) {
			System.out.printf("할 일이 이미 있습니다.");
			return;
		}
		
		System.out.print("할일(빈칸없이입력)?");
		String work = scanner.next();//next 중요 엔터나 스페이스 다음 문자를 찾음 
		
		days[n].set(work);
	}
	
	public void view() {
		System.out.printf("날짜(1~30)?");
		Scanner num = new Scanner(System.in);
		int n = num.nextInt();
		System.out.println(n + "일의 할 일은 " + days[n-1].get() + "입니다.");
	}
	
	public void finish() {
		System.out.printf("프로그램을 종료합니다.\n");
		return;
	}
	
}

public class Q3 {
	 public static void main(String[] args) {
		 Scanner scanner = new Scanner(System.in);
		 MonthSchedule ms = new MonthSchedule(30);
		 System.out.println("이번달 스케쥴 관리 프로그램.");
		 
		 while (true) {
			 System.out.print("할일(입력:1, 보기:2, 끝내기:3) >>");
			 int menu = scanner.nextInt();
			
			 switch (menu) {
			 case 1: 
				 ms.input(); break;
				 
			 case 2:
				 ms.view(); break;
				 
			 case 3:
				 ms.finish(); return;
				 
			 default: System.out.println("잘못입력하였습니다.");
			 }
			 System.out.println();
		 }
	}
}