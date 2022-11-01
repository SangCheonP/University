#include "std_lib_facilities.h"

void PrintTowers(vector<vector<int>>& v, int n, int from, int to)
{
    static int p = 1; // static함수를 정의하여 실행횟수를 기록한다
    vector<int> tmp;
    tmp.push_back(from);
    tmp.push_back(to);
    v.push_back(tmp); // 시작봉과 도착봉에 대한 정보를 하나씩 담고, 모두를 v에 담는다
    cout << "  " << p++ << "    " << n << " :";
    cout << " [  " << from << "  " << to << "  ] " << endl;
}

int intro()  //하노이탑을 선택하는 화면 함수이다

{
    double n = 0;
    cout << "실행시킬 하노이탑의 종류를 선택하세여. " << endl << endl;
    cout << "   1) 기둥 : 3개, 원판 : 3개의 하노이탑의 풀이" << endl;
    cout << "   2) 기둥 : 3개의 하노이탑의 풀이(원판 갯수 조절가능)" << endl << endl;
    cout << "선택 : ";
    cin >> n;
    cout << endl;

    if (n == 1) // 1 선택시
    {
        return 1;
    }
    else if (n == 2) // 2 선택시
    {
        return 2;
    }
    else // 나머지 오류에 대해서 처리
    {
        cout << "잘못된 입력입니다. " << endl << endl;
        intro();
    }
}

void MoveDisk(vector<vector<int>>& v, int n, int from, int to, int ex)
{
    if (n == 1) // 원판이 1개일때 실행한다
    {
        PrintTowers(v, n, from, to);
    }
    else // 그외의 상황에서는 재귀함수를 이용한다
    {
        MoveDisk(v, n - 1, from, ex, to); // 위에서부터 n - 1개를 1번에서 2번으로 옮긴다
        PrintTowers(v, n, from, to); // 나머지 바닥에 있는 한 개를 1번에서 최종 3번으로 옮긴다
        MoveDisk(v, n - 1, ex, to, from); // 2번으로 옮긴 n - 1 개를 2번에서 최종 3번으로 옮긴다
    }
}

vector<vector<int>> sol(int n)
{
    vector<vector<int>> re;
    MoveDisk(re, n, 1, 3, 2);
    return re;
}

int main()
{
    int a = 0;
    int n = 3;
    a = intro();

    if (a == 1)  // intro가 1로 반환이 되었을 때
    {
        int cnt = 0;
        cout << "횟수 원판  시작->도착(기둥 이동)" << endl;
        vector<vector<int>> re = sol(n);
        for (vector<int> v : re)
        {
            cnt++; // 실행횟수를 기록
        }
        cout << endl;
        cout << "원판을 이동시킨 총 횟수 : " << cnt << " 번";
        cout << endl;
        return 0;
    }
    else if (a == 2) // intro가 2로 반환이 되었을 때
    {
        int cnt = 0;
        cout << "원판의 갯수를 입력해주세요.(0<n<10)" << endl;
        cout << "   ex ) 3" << endl << endl;
        cout << "입력할 원판의 갯수 : ";
        cin >> n;
        cout << "횟수 원판  시작->도착(기둥 이동)" << endl;
        vector<vector<int>> re = sol(n);

        for (vector<int> v : re)
        {
            cnt++; // 실행횟수를 기록 최소로 옮기는 수는 2^n - 1
        }
        cout << endl;
        cout << "원판을 이동시킨 총 횟수 : " << cnt << " 번";
        cout << endl;
        return 0;
    }
}