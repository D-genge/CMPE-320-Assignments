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
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	bool blockHere = false;
	for (int x = 0; x < board.getWidth(); x++) {
		for (int y = 0; y < board.getHeight(); y++) {
			for (auto& block : current.getBlocks()) {
				if (x == block.getLoc().x + placement.x && y == block.getLoc().y + placement.y) {
					cout << "O ";
					blockHere = true;
				}
			}
			if (!blockHere) cout << board.getGridVal(GridLoc(x, y)) << " ";
			blockHere = false;
			
		}
		cout << endl;
	}
}
