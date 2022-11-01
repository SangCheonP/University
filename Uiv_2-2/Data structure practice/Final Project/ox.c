#include <stdio.h>
#include <stdlib.h>

int explain(); //게임 설명화면
int intro(); //메인 화면
int game3(); //삼목 메인함수
///////////////////////////////////////  *아래는 오목 함수*
int game5(); //오목 메인함수
int wincheck(); //승리조건 체크함수
void print(); //판 그려주는 함수
void p1(); //player1의 차례
void p2(); //player2의 차례
int x, y;
int map[10][10];

int main(void){
    int menu = -1;

    do
    {
        menu = intro();
        
        if (menu == 1) //게임설명
        {
            explain();
        }
        else if (menu == 2) //3x3
        {
            if(game3() == 0){
                exit(0);
            }
            else{
                game3();
            }
        }
        else if (menu == 3) //5x5
        {
            if(game5() == 0){
                exit(0);
            }
            else{
                game5();
            }
        }
        else if (menu == 4)
        {
            exit(0); //종료
        }
    }while(menu);
    return 0;
}

int explain(){
    system("clear");

    int ch=0;
    printf("\n\n\n\t\t\t\t");
    printf("         게임설명서\n\n\n\t");
    printf("                삼목 : 자신의 돌이 3개 연속으로 놓아지면 승리!\n\n\t");
    printf("                오목 : 자신의 돌이 5개 연속으로 놓아지면 승리!\n\n\n\t\t\t\t\t");
    printf("   조작법\n\n\n\t\t\t");
    printf("      돌놓기 : 원하는 칸 입력 후 Enter\n\n\n\t");
    printf("                 게임 메뉴로 돌아가기(1 입력 후 Enter) : ");

    while (1)
    {
        scanf("%d", &ch);
        if (ch == 1)
            break;
    }
    return 0;
}

int intro(){
    int menu = 0;

    while (1)
    {
        system("clear");
        printf("\n\n\n\n\t\t\t\t");
        printf("          오  목  게  임\n\n\t\t\t");
        printf("\033[93m☆ ★ ☆ ★ ☆ ★ ☆ ★ ☆ ★ ☆ ★ ☆ ★ ☆ ★ ☆ ★ ☆ ★ ☆ ★ ☆ ★ \033[0m\n\n\t\t\t\t");
        printf("          게  임  메  뉴\n\n\t\t\t");
        printf("\033[93m☆ ★ ☆ ★ ☆ ★ ☆ ★ ☆ ★ ☆ ★ ☆ ★ ☆ ★ ☆ ★ ☆ ★ ☆ ★ ☆ ★ \033[0m\n\n\t\t\t");
        printf("         =\t  (1)   게임 설명     =\n\n\t\t\t");
        printf("         =\t  (2)     삼목        =\n\n\t\t\t");
        printf("         =\t  (3)     오목        =\n\n\t\t\t");
        printf("         =\t  (4)     종료        =\n\n\t\t\t");
        printf("\033[93m☆ ★ ☆ ★ ☆ ★ ☆ ★ ☆ ★ ☆ ★ ☆ ★ ☆ ★ ☆ ★ ☆ ★ ☆ ★ ☆ ★ \033[0m\n\n\t\t\t\t\t");
        printf("    선택 : ");
        scanf("%d", &menu);
        if (menu < 1 || menu > 4)
        {
            continue;
        }
        else
        {
            return menu;
        }
    }
    return 0;
}

int game3(){
    int player = 0;
    int winner = 0;
    int r = 0;
    int c = 0;
    int num = 0;

    char map[3][3] = {'1','2','3','4','5','6','7','8','9'};

    int turn;

    for( turn = 0; turn < 9 && winner == 0; turn++){
        system("clear");
        printf("\n\n");
        printf("+---+---+---+\n");
        printf("| %c | %c | %c |\n", map[0][0], map[0][1], map[0][2]);
        printf("+---+---+---+\n");
        printf("| %c | %c | %c |\n", map[1][0], map[1][1], map[1][2]);
        printf("+---+---+---+\n");
        printf("| %c | %c | %c |\n", map[2][0], map[2][1], map[2][2]);
        printf("+---+---+---+\n");

        player = (turn % 2) + 1;

        do{
            printf("\n");
            printf("Player %d(%c) : ", player, (player == 1) ? 'X' : 'O');
            int a = 0;
            scanf("%d", &num);
            
            num--;

            c = num % 3;
            r = num / 3;
        }while(num < 0 || num > 9 || map[r][c] > '9');

        map[r][c] = (player == 1) ? 'X' : 'O';

        if(((map[0][0] == map[1][1]) && (map[0][0] == map[2][2])) ||
                    ((map[2][0] == map[1][1]) && (map[2][0] == map[0][2]))){
                winner = player;
        }
        else{
            for(int i = 0; i <= 2; i++){
                if(((map[i][0] == map[i][1]) && (map[i][0] == map[i][2])) || ((map[0][i] == map[1][i]) && (map[0][i] == map[2][i]))){
                    winner = player;
                }
            }
        }
    }
    
    system("clear");
    printf("\n\n");
    printf("+---+---+---+\n");
    printf("| %c | %c | %c |\n", map[0][0], map[0][1], map[0][2]);
    printf("+---+---+---+\n");
    printf("| %c | %c | %c |\n", map[1][0], map[1][1], map[1][2]);
    printf("+---+---+---+\n");
    printf("| %c | %c | %c |\n", map[2][0], map[2][1], map[2][2]);
    printf("+---+---+---+\n");
    
    if(winner == 0){
        printf("\n이번 게임은 무승부입니다! \n");
    }
    else {
        printf("\n축하드립니다! 승자는 Player %d(%c)입니다!\n\n\n", winner, (player == 1) ? 'X' : 'O');
    }
    printf("게임 종료 : 0  |  재시작 : 1 을 입력해주세요. => ");

    int re = 9;
    scanf("%d", &re);

    if(re == 0){
        return 0;
    }else if(re == 1){
        return 1;
    }

    return -1;
}

///////////////////////////////////////////////////////////////

int wincheck() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (map[i][j] == 1 && map[i + 1][j + 1] == 1 && map[i + 2][j + 2] == 1 && map[i + 3][j + 3] == 1 && map[i + 4][j + 4] == 1) {
                return 1;
             }
             else if (map[i][j] == 1 && map[i][j + 1] == 1 && map[i][j + 2] == 1 && map[i][j + 3] == 1 && map[i][j + 4] == 1) {
                return 1;
             }
             else if (map[j][i] == 1 && map[j + 1][i] == 1 && map[j + 2][i] == 1 && map[j + 3][i] == 1 && map[j + 4][i] == 1) {
                 return 1;
             }
             else if (map[i][j] == 1 && map[i - 1][j + 1] == 1 && map[i - 2][j + 2] == 1 && map[i - 3][j + 3] == 1 && map[i - 4][j + 4] == 1) {
                return 1;
             }
        }
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (map[i][j] == 2 && map[i + 1][j + 1] == 2 && map[i + 2][j + 2] == 2 && map[i + 3][j + 3] == 2 && map[i + 4][j + 4] == 2) {
                return 2;
             }
             else if (map[i][j] == 2 && map[i][j + 1] == 2 && map[i][j + 2] == 2 && map[i][j + 3] == 2 && map[i][j + 4] == 2) {
                return 2;
             }
             else if (map[j][i] == 2 && map[j + 1][i] == 2 && map[j + 2][i] == 2 && map[j + 3][i] == 2 && map[j + 4][i] == 2) {
                return 2;
             }
             else if (map[i][j] == 2 && map[i - 1][j + 1] == 2 && map[i - 2][j + 2] == 2 && map[i - 3][j + 3] == 2 && map[i - 4][j + 4] == 2) {
                return 2;
             }
        }
    }
}

void print() {
    system("clear");
    printf("  0 1 2 3 4 5 6 7 8 9 \n");

    for (int i = 0; i < 10; i++) {
        printf("%d",i);
        for (int j = 0; j < 10; j++) {
            if (map[i][j] == 0) {
                printf(" +");
            }
            else if (map[i][j] == 1) {
                printf("● ");
            }
            else if (map[i][j] == 2) {
                printf("○ ");
            }
        }
        printf("\n");
    }
}

void p1() {
    printf("\n");
    printf("● 돌의 차례입니다. X Y 좌표를 입력주세요( ex: 3 2 ) : ");
    scanf("%d %d",&x ,&y);
    if (map[y][x] == 0) {
        map[y][x] = 1;
    }
    else if (map[y][x] != 0) {
        printf("좌표를 다시 입력해주세요!\n");
        p1();
    }
}

void p2() {
    printf("\n");
    printf("○ 돌의 차례입니다. X Y 좌표를 입력주세요( ex: 3 2 ) : ");
    scanf("%d %d", &x, &y);
    if (map[y][x] == 0) {
        map[y][x] = 2;
    }
    else if (map[y][x] != 0) {
        printf("좌표를 다시 입력해주세요!\n");
        p2();
    }
}

int game5() {
    int turn = 1;

    for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
            map[i][j] = 0;
        }
    }
    x = 0;
    y = 0;

    print();
    while (1) {
        if (turn == 1) {
            p1();
            print();
            ++turn;
        }
        else if (turn == 2) {
            p2();
            print();
            --turn;
        }
        int a = wincheck();
        if (a == 1) {
            printf("\n");
            printf("축하합니다! ● 돌이 승리하였습니다!\n");
            break;
        }
        else if (a == 2) {
            printf("\n");
            printf("축하합니다! ○ 돌이 승리하였습니다!\n");
            break;
        }
    }
    
    printf("\n");
    printf("게임 종료 : 0 | 재시작 : 1 을 입력해주세요! => ");

    int ans = 9;
    scanf("%d", &ans);

    if (ans == 0) {
        return 0;
    }
    else if (ans == 1) {
        return 1;
    }
    return -1;
}
