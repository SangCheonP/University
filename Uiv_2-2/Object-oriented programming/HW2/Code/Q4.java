package Input;

public class Q4 {
	 public static void main(String[] args) {
		 int number1 = 12321, number2 = 1232, result;
		 result = palindrome(number1);
		 resultPrint(number1, result);
		 result = palindrome(number2);
		 resultPrint(number2, result);
	 }
	 public static void resultPrint(int num1, int num2) {
		 if (num1 == num2)
			 System.out.println(num2 + "는 회문수 입니다.");
		 else
			 System.out.println(num2 + "는 회문수가 아닙니다.");
	 }

	 public static int palindrome(int num) {
		 int reverse=0;
		 int digit =0;
		 while(num != 0) {
			 digit = num %10;
			 reverse = reverse *10 +digit;
			 num /= 10;
		 }
		 return reverse;
	 }
}