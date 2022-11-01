
public class Eiensteins {
	public static int row = 120; // 5! = 5*4*3*2*1 = 120
	public static int col = 5;

	public static int arr[][] = new int[row][col];

	public static int colorArr[] = new int[col];
	public static int nationalityArr[] = new int[col];
	public static int beverageArr[] = new int[col];
	public static int smokeArr[] = new int[col];
	public static int petArr[] = new int[col];

	public static int res[][] = { colorArr, nationalityArr, beverageArr, smokeArr, petArr };

	public static int Red = 0, Green = 1, White = 2, Yellow = 3, Blue = 4;
	
	public static int Brit = 0, Swede = 1, Dane = 2, Norwegian = 3, German = 4;

	public static int Tea = 0, Coffee = 1, Milk = 2, Beer = 3, Water = 4;

	public static int PallMall = 0, Dunhill = 1, Blend = 2, BlueMaster = 3, Prince = 4;

	public static int Dog = 0, Bird = 1, Cat = 2, Horse = 3, Fish = 4;

	//////////////////////////////////////////////

	public static void arrInit(int arr[][]) {
		int i = 0;
		for (int n = 0; n < 5; n++) {
			for (int c = 0; c < 5; c++) {
				for (int b = 0; b < 5; b++) {
					for (int s = 0; s < 5; s++) {
						for (int p = 0; p < 5; p++) {

							if (n != c && n != b && n != s && n != p && c != b && c != s && c != p && b != s && b != p
									&& s != p) {
								arr[i][0] = n;
								arr[i][1] = c;
								arr[i][2] = b;
								arr[i][3] = s;
								arr[i][4] = p;
								i++;
							}
						}
					}
				}
			}
		}
	}

	public static void print(int res[][]) {
		System.out.print("     COLORS : ");
		for (int i = 0; i < 5; i++) { // 색깔 출력
			switch (res[1][i]) {
			case 0:
				System.out.print("Red        ");
				break;
			case 1:
				System.out.print("Green      ");
				break;
			case 2:
				System.out.print("White      ");
				break;
			case 3:
				System.out.print("Yellow     ");
				break;
			case 4:
				System.out.print("Blue       ");
				break;
			}
		}
		System.out.println();
		
		System.out.print("NATIONALITY : ");
		for (int i = 0; i < 5; i++) { // 국적 출력
			switch (res[0][i]) {
			case 0:
				System.out.print("Brit       ");
				break;
			case 1:
				System.out.print("Swede      ");
				break;
			case 2:
				System.out.print("Dane       ");
				break;
			case 3:
				System.out.print("Norwegian  ");
				break;
			case 4:
				System.out.print("German     ");
				break;
			}
		}
		System.out.println();
		
		System.out.print("   BEVERAGE : ");
		for (int i = 0; i < 5; i++) { // 음료 출력
			switch (res[2][i]) {
			case 0:
				System.out.print("Tea        ");
				break;
			case 1:
				System.out.print("Coffe      ");
				break;
			case 2:
				System.out.print("Milk       ");
				break;
			case 3:
				System.out.print("Beer       ");
				break;
			case 4:
				System.out.print("Water      ");
				break;
			}
		}
		System.out.println();
		
		System.out.print("      CIGAR : ");
		for (int i = 0; i < 5; i++) { // 담배 출력
			switch (res[3][i]) {
			case 0:
				System.out.print("PallMall   ");
				break;
			case 1:
				System.out.print("Dunhill    ");
				break;
			case 2:
				System.out.print("Blend      ");
				break;
			case 3:
				System.out.print("Bluemaster ");
				break;
			case 4:
				System.out.print("Prince     ");
				break;
			}
		}
		System.out.println();
		
		System.out.print("        PET : ");
		for (int i = 0; i < 5; i++) { // 애완동물 출력
			switch (res[4][i]) {
			case 0:
				System.out.print("Dog        ");
				break;
			case 1:
				System.out.print("Bird       ");
				break;
			case 2:
				System.out.print("Cat        ");
				break;
			case 3:
				System.out.print("Horse      ");
				break;
			case 4:
				System.out.print("Fish       ");
				break;
			}
		}
		System.out.println();
	}

	// 1. 영국사람은 빨간집에 산다
	public static boolean rule1(int res[][]) {
		for (int i = 0; i < nationalityArr.length; i++) {
			if (res[0][i] == Brit) {
				if (res[1][i] == Red)
					return true;
			}
		}
		return false;
	}

	// 2. 스웨덴사람은 개를 키운다
	public static boolean rule2(int res[][]) {
		for (int i = 0; i < nationalityArr.length; i++) {
			if (res[0][i] == Swede) {
				if (res[4][i] == Dog)
					return true;
			}
		}
		return false;
	}

	// 3. 덴마크사람은 차를 마신다
	public static boolean rule3(int res[][]) {
		for (int i = 0; i < nationalityArr.length; i++) {
			if (res[0][i] == Dane) {
				if (res[2][i] == Tea)
					return true;
			}
		}
		return false;
	}

	// 4. 초록집은 흰집 왼쪽에 있다
	public static boolean rule4(int res[][]) {
		for (int i = 0; i < colorArr.length; i++) {
			if (res[1][i] == Green) {
				for (int j = 0; j < colorArr.length; j++) {
					if (res[1][j] == White) {
						if (j - i == 1)
							return true;
					}
				}
			}
		}
		return false;
	}

	// 5. 초록집의 주인은 커피를 마신다
	public static boolean rule5(int res[][]) {
		for (int i = 0; i < colorArr.length; i++) {
			if (res[1][i] == Green) {
				if (res[2][i] == Coffee)
					return true;
			}
		}
		return false;
	}

	// 6. Pall Mall을 피는 사람은 새를 기른다
	public static boolean rule6(int res[][]) {
		for (int i = 0; i < smokeArr.length; i++) {
			if (res[3][i] == PallMall) {
				if (res[4][i] == Bird)
					return true;
			}
		}
		return false;
	}

	// 7. 노란집 주인은 Dunhill을 핀다
	public static boolean rule7(int res[][]) {
		for (int i = 0; i < colorArr.length; i++) {
			if (res[1][i] == Yellow) {
				if (res[3][i] == Dunhill)
					return true;
			}
		}
		return false;
	}

	// 8. 가운데 집에 사는 사람은 우유를 마신다
	public static boolean rule8(int res[][]) {
		if (res[2][2] == Milk)
			return true;
		return false;
	}

	// 9. 노르웨이사람은 왼쪽에서 첫번째 집에 산다.
	public static boolean rule9(int res[][]) {
		if (res[0][0] == Norwegian)
			return true;
		return false;
	}

	// 10. Blend를 피는 사람은 고양이를 기르는 사람 옆에 산다
	public static boolean rule10(int res[][]) {
		for (int i = 0; i < smokeArr.length; i++) {
			if (res[3][i] == Blend) {
				for (int j = 0; j < petArr.length; j++) {
					if (res[4][j] == Cat) {
						if (i - j == 1 || j - i == 1)
							return true;
					}
				}
			}
		}
		return false;
	}

	// 11. 말을 기르는 사람은 Dunhill을 피는 사람 옆에 산다.
	public static boolean rule11(int res[][]) {
		for (int i = 0; i < petArr.length; i++) {
			if (res[4][i] == Horse) {
				for (int j = 0; j < smokeArr.length; j++) {
					if (res[3][j] == Dunhill) {
						if (i - j == 1 || j - i == 1)
							return true;
					}
				}
			}
		}
		return false;
	}

	// 12. BlueMaster을 피는 사람은 맥주를 마신다.
	public static boolean rule12(int res[][]) {
		for (int i = 0; i < smokeArr.length; i++) {
			if (res[3][i] == BlueMaster) {
				if (res[2][i] == Beer)
					return true;
			}
		}
		return false;
	}

	// 13. 독일사람은 Prince를 핀다
	public static boolean rule13(int res[][]) {
		for (int i = 0; i < nationalityArr.length; i++) {
			if (res[0][i] == German) {
				if (res[3][i] == Prince)
					return true;
			}
		}
		return false;
	}

	// 14. 노르웨이사람은 파란집 옆에 산다
	public static boolean rule14(int res[][]) {
		for (int i = 0; i < nationalityArr.length; i++) {
			if (res[0][i] == Norwegian) {
				for (int j = 0; j < colorArr.length; j++) {
					if (res[1][j] == Blue) {
						if (i - j == 1 || j - i == 1)
							return true;
					}
				}
			}
		}
		return false;
	}

	// 15. Blend를 피는 사람의 옆집 사람은 물을 마신다
	public static boolean rule15(int res[][]) {
		for (int i = 0; i < smokeArr.length; i++) {
			if (res[3][i] == Blend) {
				for (int j = 0; j < beverageArr.length; j++) {
					if (res[2][j] == Water) {
						if (i - j == 1 || j - i == 1)
							return true;
					}
				}
			}
		}
		return false;
	}

	public static int[][] promising() {
		int count = 1;
		int res[][] = new int[5][5];
		arrInit(arr);
		
		// 0행에 모든 경우를 다 넣어봄
		for (int j = 0; j < 120; j++) {
			for (int i = 0; i < 5; i++) {
				res[0][i] = arr[j][i];
			}
			
			// 조건이 만족하지 않으면 다음 경우로 넘어감 -> 0번째 행과 관련된 rule
			if (!rule9(res)) {
				continue;
			}
			
			// 1행에 모든 경우를 다 넣어봄
			for (int k = 0; k < 120; k++) {
				for (int i = 0; i < 5; i++) {
					res[1][i] = arr[k][i];
				}
				
				// 조건1, 4, 14가 만족하지 않으면 다음 경우로 넘어감 -> 0~1번째 행과 관련된 rule
				if (!rule1(res) || !rule4(res) || !rule14(res)) {
					continue;
				}
				
				// 2행에 모든 경우를 다 넣어봄
				for (int l = 0; l < 120; l++) {
					for (int i = 0; i < 5; i++) {
						res[2][i] = arr[l][i];
					}
					
					// 조건3, 5, 8가 만족하지 않으면 다음 경우로 넘어감 -> 0~2번째 행과 관련된 rule
					if (!rule3(res) || !rule5(res) || !rule8(res)) {
						continue;
					}
					
					// 3행에 모든 경우를 다 넣어봄
					for (int m = 0; m < 120; m++) {
						for (int i = 0; i < 5; i++) {
							res[3][i] = arr[m][i];
						}
						
						// 조건7, 12, 13, 15가 만족하지 않으면 다음 경우로 넘어감 -> 0~3번째 행과 관련된 rule
						if (!rule7(res) || !rule12(res) || !rule13(res) || !rule15(res)) {
							continue;
						}

						// 4행에 모든 경우를 다 넣어봄
						for (int n = 0; n < 120; n++) {
							for (int i = 0; i < 5; i++) {

								System.out.println("현재 " + count + "개 Node 탐색");
								count++;

								res[4][i] = arr[n][i];
							}
							
							// 조건2, 6, 10, 11이 만족하지 않으면 다음 경우로 넘어감 -> 0~4번째 행과 관련된 rule
							if (!rule2(res) || !rule6(res) || !rule10(res) || !rule11(res)) {
								continue;
							} else {
								System.out.println("총 " + (count-1) + "개의 Node를 탐색,모든 조건을 만족하는 Node는 " + (count-1) + "번째 Node");
								return res; // 모든 조건을 만족하는 것을 리턴
							}

						}

					}
				}
			}
		}
		return res;
	}

	public static void main(String[] args) {
		int res[][] = new int[5][5];
		res = promising();
		print(res);
	}
}
