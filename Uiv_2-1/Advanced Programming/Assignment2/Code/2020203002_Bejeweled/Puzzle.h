#pragma once

#include <utility>
#include <string>
#include <vector>
using namespace std;

enum class Jewel
{
	NONE=-1, RED, ORANGE, YELLOW, GREEN, BLUE, PURPLE, WHITE
};

class Puzzle
{
public:
	Puzzle(int num_rows, int num_columns);
	
	struct Chain
	{
		Jewel jewel;
		std::pair<int, int> start;
		std::pair<int, int> end;
		int match=0;
	}grid[10][10];
	
	bool full();
	bool check();
	std::vector<Jewel> jewel_arr;

	bool initialize(const std::string& jewel_list);
	void randomize();
	bool update();
	
	bool setJewel(std::pair<int, int> loc, Jewel jewel);
	Jewel getJewel(std::pair<int, int> loc) const;

	void show();

	bool swapJewels(std::pair<int, int> prev_loc, std::pair<int, int> next_loc);

	inline int getNumRows() const { return num_rows; }
	inline int getNumColumns() const { return num_columns; }

	static Jewel getJewelType(char letter);
	static char getJewelLetter(Jewel jewel);

private:
	int num_rows;
	int num_columns;
};
