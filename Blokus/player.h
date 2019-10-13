#pragma once
#include "game_piece.h"


class Player {
public:
	Player() { Player(0); };
	Player(int id);
	int getID() { return ID; };
	void finishedTurn() { moved = true; };
	bool hasMoved() { return moved; };
	GamePiece getAvalPiece();
private:
	vector<GamePiece> availPieces;
	int ID;
	bool moved;
};