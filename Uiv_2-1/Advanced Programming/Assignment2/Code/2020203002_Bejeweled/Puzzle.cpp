#include "Puzzle.h"
#include <iostream>
using namespace std;

Puzzle::Puzzle(int num_rows, int num_columns) // ��ó�� ����, ������ ũ�⸦ �Է¹޾� �� ���̸�ŭ ���Ϳ� NONE�� �ִ´�.
{											  // �׸��� �װ��� 2���� �迭�� ������ ��ǥ�� �����Ų��.
	this->num_rows = num_rows;
	this->num_columns = num_columns;

	int num_jewels = num_rows * num_columns;

	for (int i = 0; i < num_jewels; i++)
	{
		Jewel jewel = Jewel::NONE;
		jewel_arr.push_back(jewel);
	}
	int a = 0;
	for (int i = 0; i < num_rows; i++)
	{
		for (int j = 0; j < num_columns; j++)
		{
			grid[i][j].jewel = jewel_arr[a];
			a++;
		}
	}
}

bool Puzzle::initialize(const std::string& jewel_list)
{
	int a = 0;
	int num_jewels = num_rows * num_columns;
	if ((int)jewel_list.length() != num_jewels) //���̰� ���� ������ false�� ��ȯ
	{
		return false;
	}
	else
	{
		for (int i = 0; i < num_rows; i++)
		{
			for (int j = 0; j < num_columns; j++)
			{
				grid[i][j].jewel = getJewelType(jewel_list[a]);
				a++;
			}
		}
		return true;
	}
}

void Puzzle::randomize() // 2���� �迭�� ���� �������� Jewel�� �ִ´�.
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			grid[i][j].jewel = Jewel(rand() % 7);
		}
	}
}

bool Puzzle::update() // chain�� �ִ��� �˻��ϰ�, ������ �� chain��ġ�� jewel�� NONE���� �ٲ۴�.
{					  // ���� NONE�� �ִ��� �˻��ϰ�, ������ ���� Jewel���� ��ĭ�� ���� ��ĭ�� ä���ְ�, �� ��ĭ�� ������ Jewel�� ä���.
	int a = 0;
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)	
		{
			if (grid[i][j].jewel == grid[i + 1][j].jewel)
				if (grid[i][j].jewel == grid[i - 1][j].jewel)
				{
					grid[i - 1][j].jewel = Jewel::NONE;
					grid[i][j].jewel = Jewel::NONE;
					grid[i + 1][j].jewel = Jewel::NONE;
					a = 1;
				}

			if (grid[i][j].jewel == grid[i][j + 1].jewel)
				if (grid[i][j].jewel == grid[i][j - 1].jewel)
				{
					grid[i][j - 1].jewel = Jewel::NONE;
					grid[i][j].jewel = Jewel::NONE;
					grid[i][j + 1].jewel = Jewel::NONE;
					a = 1;
				}
		}
	if (a == 1)
	{
		show();
	}
		cout << endl;

	do
	{
		for (int i = 0; i < 8; i++)
		{
			if (grid[7][i].jewel == Jewel::NONE)
			{
				while (grid[7][i].jewel == Jewel::NONE)
				{
						grid[7][i].jewel = grid[6][i].jewel;
						grid[6][i].jewel = grid[5][i].jewel;
						grid[5][i].jewel = grid[4][i].jewel;
						grid[4][i].jewel = grid[3][i].jewel;
						grid[3][i].jewel = grid[2][i].jewel;
						grid[2][i].jewel = grid[1][i].jewel;
						grid[1][i].jewel = grid[0][i].jewel;
						grid[0][i].jewel = Jewel(rand() % 7);
				}
			}
				if (grid[6][i].jewel == Jewel::NONE)
				{
					while (grid[6][i].jewel == Jewel::NONE)
					{
						grid[6][i].jewel = grid[5][i].jewel;
						grid[5][i].jewel = grid[4][i].jewel;
						grid[4][i].jewel = grid[3][i].jewel;
						grid[3][i].jewel = grid[2][i].jewel;
						grid[2][i].jewel = grid[1][i].jewel;
						grid[1][i].jewel = grid[0][i].jewel;
						grid[0][i].jewel = Jewel(rand() % 7);
					}
				}
				if (grid[5][i].jewel == Jewel::NONE)
				{
					while (grid[5][i].jewel == Jewel::NONE)
					{
						grid[5][i].jewel = grid[4][i].jewel;
						grid[4][i].jewel = grid[3][i].jewel;
						grid[3][i].jewel = grid[2][i].jewel;
						grid[2][i].jewel = grid[1][i].jewel;
						grid[1][i].jewel = grid[0][i].jewel;
						grid[0][i].jewel = Jewel(rand() % 7);
					}
				}
				if (grid[4][i].jewel == Jewel::NONE)
				{
					while (grid[4][i].jewel == Jewel::NONE)
					{
						grid[4][i].jewel = grid[3][i].jewel;
						grid[3][i].jewel = grid[2][i].jewel;
						grid[2][i].jewel = grid[1][i].jewel;
						grid[1][i].jewel = grid[0][i].jewel;
						grid[0][i].jewel = Jewel(rand() % 7);
					}
				}
				if (grid[3][i].jewel == Jewel::NONE)
				{
					while (grid[3][i].jewel == Jewel::NONE)
					{
						grid[3][i].jewel = grid[2][i].jewel;
						grid[2][i].jewel = grid[1][i].jewel;
						grid[1][i].jewel = grid[0][i].jewel;
						grid[0][i].jewel = Jewel(rand() % 7);
					}
				}
				if (grid[2][i].jewel == Jewel::NONE)
				{
					while (grid[2][i].jewel == Jewel::NONE)
					{
						grid[2][i].jewel = grid[1][i].jewel;
						grid[1][i].jewel = grid[0][i].jewel;
						grid[0][i].jewel = Jewel(rand() % 7);
					}
				}
				if (grid[1][i].jewel == Jewel::NONE)
				{
					while (grid[1][i].jewel == Jewel::NONE)
					{
						grid[1][i].jewel = grid[0][i].jewel;
						grid[0][i].jewel = Jewel(rand() % 7);
					}
				}
				if (grid[0][i].jewel == Jewel::NONE)
				{
					while (grid[0][i].jewel == Jewel::NONE)
					{
						grid[0][i].jewel = Jewel(rand() % 7);
					}
				}
		}
	} while (!full());
	show();
	cout << endl;

	if (check())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Puzzle::swapJewels(std::pair<int, int> prev_loc, std::pair<int, int> next_loc) // 2���� ��ǥ�� �Է¹޾� �� ��ǥ�� ����ִ� ����� ���� �ٲ۴�.
																					// �̶� update�Լ��� ����Ͽ� chain�� üũ�Ѵ�.
{
	if(prev_loc.first >= 0 && prev_loc.first < num_rows && prev_loc.second >= 0 && prev_loc.second < num_columns&& next_loc.first >= 0 
		&& next_loc.first < num_rows && next_loc.second >= 0 && next_loc.second < num_columns)
		if (prev_loc.first + 1 == next_loc.first && prev_loc.second == next_loc.second 
			|| prev_loc.first - 1 == next_loc.first && prev_loc.second == next_loc.second 
			|| prev_loc.first == next_loc.first && prev_loc.second + 1 == next_loc.second 
			|| prev_loc.first == next_loc.first && prev_loc.second - 1 == next_loc.second)
		{
			cout << endl;
			Jewel jA, jB, temp;
			jA = getJewel(prev_loc);
			jB = getJewel(next_loc);
			temp = jA;
			jA = jB;
			jB = temp;
			setJewel(prev_loc, (Jewel)jA);
			setJewel(next_loc, (Jewel)jB);
			do
			{

			} while (update());
			cout << endl;
			return true;
		}
		else
		{
			exit;
			return false;
		}
	else 
	{
		return false;
	}
}

bool Puzzle::setJewel(std::pair<int, int> loc, Jewel jewel) // �Է¹��� ��ġ�� ����� 2���� �迭�� �ִ´�.
{
	if (loc.first >= 0 && loc.first < 8 && loc.second >= 0 && loc.second < 8)
	{
		grid[loc.first][loc.second].jewel = Jewel(jewel);
		return true;
	}
	else
	{
		return false;
	}
}

Jewel Puzzle::getJewel(std::pair<int, int> loc) const // �Է¹��� ��ġ�� 2���� �迭���� ����� ������ ���� ��ȯ�Ѵ�.
{
	Jewel jewel=Jewel::NONE;

	if (loc.first >= 0 && loc.first < 8 && loc.second >= 0 && loc.second <8)
	{
		jewel = grid[loc.first][loc.second].jewel;
		return jewel;
	}
	else
	{
		return jewel;
	}
}

Jewel Puzzle::getJewelType(char letter) // char�� ���ڸ� �޾� �׿� �����ϴ� Jewel�� ��ȯ�Ѵ�.
{
	Jewel jewel = Jewel::NONE;

	switch (letter)
	{
	case' ': 
		jewel = Jewel::NONE;
		break;

	case'@':
		jewel = Jewel::RED;
		break;

	case'#':
		jewel = Jewel::ORANGE;
		break;

	case'*':
		jewel = Jewel::YELLOW;
		break;

	case'%':
		jewel = Jewel::GREEN;
		break;

	case'$':
		jewel = Jewel::BLUE;
		break;

	case'&':
		jewel = Jewel::PURPLE;
		break;

	case'!':
		jewel = Jewel::WHITE;
		break;
	}

	return jewel;
}

char Puzzle::getJewelLetter(Jewel jewel) // Jewel�� �޾� �׿� �����ϴ� char������ ��ȯ�Ѵ�.
{
	char letter = ' ';

	switch (jewel)
	{
	case Jewel::NONE:
		letter = ' ';
		break;

	case Jewel::RED:
		letter = '@';
		break;

	case Jewel::ORANGE:
		letter = '#';
		break;

	case Jewel::YELLOW:
		letter = '*';
		break;

	case Jewel::GREEN:
		letter = '%';
		break;

	case Jewel::BLUE:
		letter = '$';
		break;

	case Jewel::PURPLE:
		letter = '&';
		break;

	case Jewel::WHITE:
		letter = '!';
		break;

	default:
		break;
	}

	return letter;
}

void Puzzle::show() // 2���� �迭�� �̿��Ͽ� �� ��ǥ�� �ִ� Jewel�� �����ǰ� �Բ� ����Ѵ�.
{
	cout << "   0 1 2 3 4 5 6 7" << endl;
	cout << "  +---------------" << endl;
	cout << "0 |";
	for (int j = 0; j < 8; j++)
	{
		cout << getJewelLetter(grid[0][j].jewel) << " ";
	}cout << endl;

	cout << "1 |";
	for (int j = 0; j < 8; j++)
	{
		cout << getJewelLetter(grid[1][j].jewel) << " ";
	}cout << endl;

	cout << "2 |";
	for (int j = 0; j < 8; j++)
	{
		cout << getJewelLetter(grid[2][j].jewel) << " ";
	}cout << endl;

	cout << "3 |";
	for (int j = 0; j < 8; j++)
	{
		cout << getJewelLetter(grid[3][j].jewel) << " ";
	}cout << endl;

	cout << "4 |";
	for (int j = 0; j < 8; j++)
	{
		cout << getJewelLetter(grid[4][j].jewel) << " ";
	}cout << endl;

	cout << "5 |";
	for (int j = 0; j < 8; j++)
	{
		cout << getJewelLetter(grid[5][j].jewel) << " ";
	}cout << endl;

	cout << "6 |";
	for (int j = 0; j < 8; j++)
	{
		cout << getJewelLetter(grid[6][j].jewel) << " ";
	}cout << endl;

	cout << "7 |";
	for (int j = 0; j < 8; j++)
	{
		cout << getJewelLetter(grid[7][j].jewel) << " ";
	}cout << endl;
}

bool  Puzzle::check() // ü���� ���� ������ true, ������ false�� ��ȯ�Ѵ�.
{
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
		{
			if (grid[i][j].jewel == grid[i][j - 1].jewel && grid[i][j].jewel == grid[i][j + 1].jewel 
				|| grid[i][j].jewel == grid[i - 1][j].jewel && grid[i][j].jewel == grid[i + 1][j].jewel)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
}

bool Puzzle::full() // ��ĭ�� ������ true, ������ false�� ��ȯ�Ѵ�.
{
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
		{
			if (grid[i][j].jewel == Jewel::NONE)
			{
				return true;
			}
			else
			{
				return true;
			}
		}
}