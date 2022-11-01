#include "Puzzle.h"

#include <iostream>

std::vector<std::string> predefined_puzzles = {
	"!#!&%*&@&!@&!!@#!@$$**%!&!&&!##&#*@$&@$%%$$*&*@$##$#@$%@#$&#%$@#",
	"#!%%@%!&@*%!&@&!#*$$%%%&#*$#@$@!$%$@%@&!%$&%&@*%*$&&*&#!$$&*$#*!",
	"*@&*@#%%&%%&!$!*%#%*!*##*$$###*$$!#&&@*$$@#&#$&$$#!!!**@##@@@!!!",
	"$#@!%@$#$&$&!!*@@!$$@$!&*@**&$&@$!#*@&*@&###!@@%&@&!%&&%##$#@@&$",
};

void Game()
{
	Puzzle puzzle(8, 8);
	int option1 = 0;
	int option2 = 0;
	pair<int, int> p1;
	pair<int, int> p2;
	int col = 0;
	cout << "<<< BEJEWELED >>>"<<endl<<endl;
	cout << "[1] Start a new random puzzle" << endl;
	cout << "[2] Start a pre-defined puzzle" << endl;
	cout << "[3] Exit" << endl << endl;
	cout << "> Choose a menu option (1~3): "; cin >> option1;
	if (option1 == 1)
	{
		cout << endl;
		puzzle.randomize();
		cout << endl;
		do
		{

		} while (puzzle.update());
		do
		{
			cout << "Input the first swap position (row, col): "; cin >> p1.second >> p1.first;
			cout << "Input the second swap position (row, col): "; cin >> p2.second >> p2.first;
		} while (puzzle.swapJewels(p1, p2));
	}
	else if(option1 == 2)
	{
		cout << "> Choose a puzzle number (0~3): "; cin >> option2;
		if (option2 == 0)
		{
			cout << endl;
			puzzle.initialize("!#!&%*&@&!@&!!@#!@$$**%!&!&&!##&#*@$&@$%%$$*&*@$##$#@$%@#$&#%$@#");
			do
			{

			} while (puzzle.update());
			do
			{
				cout << "Input the first swap position (row, col): "; cin >> p1.second >> p1.first;
				cout << "Input the second swap position (row, col): "; cin >> p2.second >> p2.first;
			} while (puzzle.swapJewels(p1, p2));
		}
		else if (option2 == 1)
		{
			cout << endl;
			puzzle.initialize("#!%%@%!&@*%!&@&!#*$$%%%&#*$#@$@!$%$@%@&!%$&%&@*%*$&&*&#!$$&*$#*!");
			puzzle.show();
			cout << endl;
			do
			{
				
			} while (puzzle.update());
			do
			{
				cout << "Input the first swap position (row, col): "; cin >> p1.second >> p1.first;
				cout << "Input the second swap position (row, col): "; cin >> p2.second >> p2.first;
			} while (puzzle.swapJewels(p1, p2));
		}
		else if (option2 == 2)
		{
			cout << endl;
			puzzle.initialize("*@&*@#%%&%%&!$!*%#%*!*##*$$###*$$!#&&@*$$@#&#$&$$#!!!**@##@@@!!!");
			puzzle.show();
			cout << endl;
			do
			{

			} while (puzzle.update());
			do
			{
				cout << "Input the first swap position (row, col): "; cin >> p1.second >> p1.first;
				cout << "Input the second swap position (row, col): "; cin >> p2.second >> p2.first;
			} while (puzzle.swapJewels(p1, p2));
		}
		else if (option2 == 3)
		{
			cout << endl;
			puzzle.initialize("$#@!%@$#$&$&!!*@@!$$@$!&*@**&$&@$!#*@&*@&###!@@%&@&!%&&%##$#@@&$");
			puzzle.show();
			cout << endl;
			do
			{
			
			} while (puzzle.update());
			do
			{
				cout << "Input the first swap position (row, col): "; cin >> p1.second >> p1.first;
				cout << "Input the second swap position (row, col): "; cin >> p2.second >> p2.first;
			} while (puzzle.swapJewels(p1, p2));
		}
		else
		{
			exit;
			cout << endl;
			Game();
		}
	}
	else if (option1 == 3)
	{
		exit;
	}
	else
	{
		exit;
		cout << endl;
		Game();
	}

}

int main()
{
	Game();
	return 0;
}