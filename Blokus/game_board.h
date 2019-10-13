#pragma once
#include <vector>
#include "game_piece.h"
#include "player.h"
using namespace std;

class GameBoard {
public:
	GameBoard(int width = 20, int height = 20);
	bool placePiece(GamePiece, GridLoc, Player);
	bool placeable(GamePiece, GridLoc, Player);
	int getWidth() { return width; };
	int getHeight() { return height; };
	int getGridVal(GridLoc loc) { return grid[loc.x][loc.y]; };// needs bounds check
private:
	vector<vector<int>> grid;
	int width, height;
};