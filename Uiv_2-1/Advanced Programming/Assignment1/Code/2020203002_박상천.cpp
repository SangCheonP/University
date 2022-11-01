#include "std_lib_facilities.h"

void PrintTowers(vector<vector<int>>& v, int n, int from, int to)
{
    static int p = 1; // static�Լ��� �����Ͽ� ����Ƚ���� ����Ѵ�
    vector<int> tmp;
    tmp.push_back(from);
    tmp.push_back(to);
    v.push_back(tmp); // ���ۺ��� �������� ���� ������ �ϳ��� ���, ��θ� v�� ��´�
    cout << "  " << p++ << "    " << n << " :";
    cout << " [  " << from << "  " << to << "  ] " << endl;
}

int intro()  //�ϳ���ž�� �����ϴ� ȭ�� �Լ��̴�

{
    double n = 0;
    cout << "�����ų �ϳ���ž�� ������ �����ϼ���. " << endl << endl;
    cout << "   1) ��� : 3��, ���� : 3���� �ϳ���ž�� Ǯ��" << endl;
    cout << "   2) ��� : 3���� �ϳ���ž�� Ǯ��(���� ���� ��������)" << endl << endl;
    cout << "���� : ";
    cin >> n;
    cout << endl;

    if (n == 1) // 1 ���ý�
    {
        return 1;
    }
    else if (n == 2) // 2 ���ý�
    {
        return 2;
    }
    else // ������ ������ ���ؼ� ó��
    {
        cout << "�߸��� �Է��Դϴ�. " << endl << endl;
        intro();
    }
}

void MoveDisk(vector<vector<int>>& v, int n, int from, int to, int ex)
{
    if (n == 1) // ������ 1���϶� �����Ѵ�
    {
        PrintTowers(v, n, from, to);
    }
    else // �׿��� ��Ȳ������ ����Լ��� �̿��Ѵ�
    {
        MoveDisk(v, n - 1, from, ex, to); // ���������� n - 1���� 1������ 2������ �ű��
        PrintTowers(v, n, from, to); // ������ �ٴڿ� �ִ� �� ���� 1������ ���� 3������ �ű��
        MoveDisk(v, n - 1, ex, to, from); // 2������ �ű� n - 1 ���� 2������ ���� 3������ �ű��
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

    if (a == 1)  // intro�� 1�� ��ȯ�� �Ǿ��� ��
    {
        int cnt = 0;
        cout << "Ƚ�� ����  ����->����(��� �̵�)" << endl;
        vector<vector<int>> re = sol(n);
        for (vector<int> v : re)
        {
            cnt++; // ����Ƚ���� ���
        }
        cout << endl;
        cout << "������ �̵���Ų �� Ƚ�� : " << cnt << " ��";
        cout << endl;
        return 0;
    }
    else if (a == 2) // intro�� 2�� ��ȯ�� �Ǿ��� ��
    {
        int cnt = 0;
        cout << "������ ������ �Է����ּ���.(0<n<10)" << endl;
        cout << "   ex ) 3" << endl << endl;
        cout << "�Է��� ������ ���� : ";
        cin >> n;
        cout << "Ƚ�� ����  ����->����(��� �̵�)" << endl;
        vector<vector<int>> re = sol(n);

        for (vector<int> v : re)
        {
            cnt++; // ����Ƚ���� ��� �ּҷ� �ű�� ���� 2^n - 1
        }
        cout << endl;
        cout << "������ �̵���Ų �� Ƚ�� : " << cnt << " ��";
        cout << endl;
        return 0;
    }
}