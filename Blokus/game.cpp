#include "game.h"
#include <iostream>
using namespace std;
Game::Game() : numPlayers(4), curTurn(1), board()
{
	for (int i = 1; i <= numPlayers; i++) { // player id's start at 1
		players.push_back(Player(i));
	}
}

void Game::terminalDraw(GridLoc placement, GamePiece current) // for testing
{
	bool blockHere = false;
	string formatted = "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	for (int y = board.getHeight()-1; y >= 0; y--) {
		for (int x = 0; x < board.getWidth(); x++) {
			for (auto& block : current.getBlocks()) {
				if (x == block.getLoc().x + placement.x && y == block.getLoc().y + placement.y) {
					formatted += "X ";
					blockHere = true;
				}
			}
			if (!blockHere)	formatted += to_string(board.getGridVal(GridLoc(x, y))) + " ";
			blockHere = false;
			
		}
		formatted += "\n";
	}
	formatted += current.toString();
	cout << formatted;
}
