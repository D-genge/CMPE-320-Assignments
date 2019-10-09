#pragma once
#include <vector>
#include "game_board.h"
#include "player.h"

using namespace std;

class Game {
public:
	void change_turn() { curTurn = (curTurn + 1) % players.size(); };
private:
	vector<Player> players;
	short int curTurn;
};
