#pragma once
#include <vector>

using namespace std;

class GameBoard {
public:
	GameBoard(int width = 20, int height = 20);
private:
	vector<vector<int>> grid;
};