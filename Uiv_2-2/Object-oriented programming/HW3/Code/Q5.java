class Calc{
	private int a, b;
	private char operator;
	
	public void setValue(int num1, int num2, char op) {
		a = num1;
		b = num2;
		operator = op;
	}
	
	public void result() {
		switch (operator) {
		case '+':
			System.out.println("result = " + add(a,b));
			break;
		case '-':
			System.out.println("result = " + sub(a,b));
			break;
		case '*':
			System.out.println("result = " + mul(a,b));
			break;
		case '/':
			System.out.println("result = " + div(a,b));
			break;
		default:
			System.out.println("잘못된 연산자입니다.");
		}
	}
	
	public int add(int num1, int num2) {
		return num1 + num2;
	}
	
	public int sub(int num1, int num2) {
		return num1 - num2;
	}
	
	public int mul(int num1, int num2) {
		return num1 * num2;
	}
	
	public int div(int num1, int num2) {
		return num1 / num2;
	}
}

public class Q5 {

	public static void main(String[] args) {
		 Calc c = new Calc();
		 c.setValue(2, 5, '+');
		 c.result();
		 c.setValue(2, 5, '$');
		 c.result();
		 c.setValue(2, 5, '-');
		 c.result();
		 c.setValue(2, 5, '*');
		 c.result();
		 c.setValue(2, 5, '/');
		 c.result();

	}

}
