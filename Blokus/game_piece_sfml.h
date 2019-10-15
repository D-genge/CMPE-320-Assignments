#pragma once
#include "game_piece.h"
#include "player.h"

class GamePiece {
public:
	GamePiece(CONFIG);
	vector<Block> getBlocks();
	// rotate clockwise in 90 degree increments. negs do counterclockwise
	void rotate(int rotations);
	void flip();
	void drawTerminal();
private:
	vector<Block> blocks;
	GridLoc loc;
	CONFIG config;
	//bool flipped;
	//short int rotations; //reference clockwise
};