#pragma once
#include <vector>
#include "game_board.h"

using namespace std;

class Game {
public:
	Game();
	void change_turn() { curTurn = (curTurn) % players.size() + 1; };
	void terminalDraw(GridLoc,GamePiece);
	GameBoard& getGameBoard() { return board; };
	Player currentPlayer() { return players[curTurn - 1]; };
	GameBoard board;
private:
	int numPlayers;
	vector<Player> players;

	int curTurn;
};
