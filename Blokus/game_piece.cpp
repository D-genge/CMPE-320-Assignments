#include "game_piece.h"
using namespace std;

inline CONFIG operator++(CONFIG& x) { return x = (CONFIG)(underlying_type<CONFIG>::type(x) + 1); };
CONFIG operator*(CONFIG t) { return t; };
CONFIG begin(CONFIG t) { return CONFIG::First; };
CONFIG end(CONFIG t) { CONFIG l = CONFIG::Last; return ++l; };

Block::Block(GridLoc location)
{
	loc = location;
}

void Block::setLoc(GridLoc location)
{	
	loc = location;
}

GridLoc Block::getLoc()
{
	return loc;
}

GamePiece::GamePiece(CONFIG type) :
	config(type),
	loc(GridLoc(0,0))
{
	blocks.push_back(Block(GridLoc(0,0)));
	switch (config) { // reference for piece names found here: http://pentolla.com/images/Pieces.png
		case CONFIG::F  : 
			blocks.push_back(Block(GridLoc(-1,0)));
			blocks.push_back(Block(GridLoc(0,-1)));
			blocks.push_back(Block(GridLoc(0,1)));
			blocks.push_back(Block(GridLoc(1,1)));
			break;
		case CONFIG::I1 :
			break;
		case CONFIG::I2 : 
			blocks.push_back(Block(GridLoc(0,1)));
			break;
		case CONFIG::I3 :
			blocks.push_back(Block(GridLoc(0,1)));
			blocks.push_back(Block(GridLoc(0,-1)));
			break;
		case CONFIG::I4 :
			blocks.push_back(Block(GridLoc(0,1)));
			blocks.push_back(Block(GridLoc(0,-1)));
			blocks.push_back(Block(GridLoc(0,2)));
			break;
		case CONFIG::I5 :
			blocks.push_back(Block(GridLoc(0,1)));
			blocks.push_back(Block(GridLoc(0,2)));
			blocks.push_back(Block(GridLoc(0,-1)));
			blocks.push_back(Block(GridLoc(0,-2)));
			break;
		case CONFIG::L4 :
			blocks.push_back(Block(GridLoc(0,1)));
			blocks.push_back(Block(GridLoc(0,-1)));
			blocks.push_back(Block(GridLoc(1,-1)));
			break;
		case CONFIG::L5 :
			blocks.push_back(Block(GridLoc(0,1)));
			blocks.push_back(Block(GridLoc(0,2)));
			blocks.push_back(Block(GridLoc(0,-1)));
			blocks.push_back(Block(GridLoc(1,-1)));
			break;
		case CONFIG::N  :
			blocks.push_back(Block(GridLoc(1,0)));
			blocks.push_back(Block(GridLoc(1,-1)));
			blocks.push_back(Block(GridLoc(0,1)));
			blocks.push_back(Block(GridLoc(0,2)));
			break;
		case CONFIG::O4 : 
			blocks.push_back(Block(GridLoc(0,1)));
			blocks.push_back(Block(GridLoc(1,0)));
			blocks.push_back(Block(GridLoc(1,1)));
			break;
		case CONFIG::P  : 
			blocks.push_back(Block(GridLoc(0,1)));
			blocks.push_back(Block(GridLoc(1,0)));
			blocks.push_back(Block(GridLoc(1,1)));
			blocks.push_back(Block(GridLoc(0,-1)));
			break;
		case CONFIG::T  : 
			blocks.push_back(Block(GridLoc(-1,1)));
			blocks.push_back(Block(GridLoc(0,1)));
			blocks.push_back(Block(GridLoc(1,1)));
			blocks.push_back(Block(GridLoc(0,-1)));
			break;
		case CONFIG::T4 : 
			blocks.push_back(Block(GridLoc(-1,0)));
			blocks.push_back(Block(GridLoc(1,0)));
			blocks.push_back(Block(GridLoc(0,-1)));
			break;
		case CONFIG::U  :
			blocks.push_back(Block(GridLoc(-1,0)));
			blocks.push_back(Block(GridLoc(1,0)));
			blocks.push_back(Block(GridLoc(-1,1)));
			blocks.push_back(Block(GridLoc(1,1)));
			break;
		case CONFIG::V3 :
			blocks.push_back(Block(GridLoc(0,1)));
			blocks.push_back(Block(GridLoc(1,0)));
			break;
		case CONFIG::V5 :
			blocks.push_back(Block(GridLoc(0,1)));
			blocks.push_back(Block(GridLoc(0,2)));
			blocks.push_back(Block(GridLoc(1,0)));
			blocks.push_back(Block(GridLoc(2,0)));
			break;
		case CONFIG::W  :
			blocks.push_back(Block(GridLoc(-1,1)));
			blocks.push_back(Block(GridLoc(-1,0)));
			blocks.push_back(Block(GridLoc(0,-1)));
			blocks.push_back(Block(GridLoc(1,-1)));
			break;
		case CONFIG::X  :
			blocks.push_back(Block(GridLoc(0,1)));
			blocks.push_back(Block(GridLoc(1,0)));
			blocks.push_back(Block(GridLoc(0,-1)));
			blocks.push_back(Block(GridLoc(-1,0)));
			break;
		case CONFIG::Y  : 
			blocks.push_back(Block(GridLoc(0,1)));
			blocks.push_back(Block(GridLoc(1,0)));
			blocks.push_back(Block(GridLoc(0,-1)));
			blocks.push_back(Block(GridLoc(0,-2)));
			break;
		case CONFIG::Z4 :
			blocks.push_back(Block(GridLoc(-1,1)));
			blocks.push_back(Block(GridLoc(0,1)));
			blocks.push_back(Block(GridLoc(1,0)));
			break;
		case CONFIG::Z5 : 
			blocks.push_back(Block(GridLoc(-1,1)));
			blocks.push_back(Block(GridLoc(0,1)));
			blocks.push_back(Block(GridLoc(0,-1)));
			blocks.push_back(Block(GridLoc(1,-1)));
			break;
	};

}

vector<Block> GamePiece::getBlocks()
{
	return blocks;
}

void GamePiece::rotate(int rotations)
{
	// if rotations is zero it doesnt rotate
	if (rotations > 0) {
		for (int i = 0; i < rotations; i++) {
			for (auto& block : blocks) {
				GridLoc xy = block.getLoc();
				block.setLoc(GridLoc(xy.y, -xy.x));
			}
		}
	} 
	else if (rotations < 0) {
		int cc = -rotations;
		for (int i = 0; i < cc; i++) {
			for (auto& block : blocks) {
				GridLoc xy = block.getLoc();
				block.setLoc(GridLoc(-xy.y,xy.x));
			}
		}
	}
}

void GamePiece::flip()
{
	for (auto& block : blocks) {
		GridLoc xy = block.getLoc();
		block.setLoc(GridLoc(-xy.x, xy.y));
	}
}

void GamePiece::drawTerminal()
{
	char rep[5][6] = { {' ',' ',' ',' ',' ','\n'},
					   {' ',' ',' ',' ',' ','\n'},
					   {' ',' ',' ',' ',' ','\n'},
					   {' ',' ',' ',' ',' ','\n'},
					   {' ',' ',' ',' ',' ','\n'} };
	string output = "";
	for (auto& block : blocks) {
		rep[block.getLoc().x+2][block.getLoc().y+2] = 'X';
	}
	for (int i = 0; i < 5;i++) {
		for (int j = 0; j < 6; j++) {
			output += " " + string(1,rep[i][j]);
		}
	}
	cout << output;
}
string GamePiece::toString()
{
	char rep[5][6] = { {' ',' ',' ',' ',' ','\n'},
					   {' ',' ',' ',' ',' ','\n'},
					   {' ',' ',' ',' ',' ','\n'},
					   {' ',' ',' ',' ',' ','\n'},
					   {' ',' ',' ',' ',' ','\n'} };
	string output = "";
	for (auto& block : blocks) {
		rep[2-block.getLoc().y][2 + block.getLoc().x] = 'X';
	}
	for (int x = 0; x < 5; x++) {
		for (int y = 0; y < 6; y++) {
			output += " " + string(1, rep[x][y]);
		}
	}
	return output;
}
