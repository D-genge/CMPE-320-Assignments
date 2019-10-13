#pragma once
#include <vector>
#include <string>
#include <iostream>

using namespace std;
class GridLoc {
public:
	GridLoc() { GridLoc(0, 0); };
	GridLoc(int x, int y) : 
		x(x),
		y(y)
	{};
	int x;
	int y;
private:
};
enum class CONFIG {
	F,
	I1,
	I2,
	I3,
	I4,
	I5,
	L4,
	L5,
	N,
	O4,
	P,
	T,
	T4,
	U,
	V3,
	V5,
	W,
	X,
	Y,
	Z4,
	Z5,
	First=F,
	Last=Z5
};

inline CONFIG operator++(CONFIG& x);
CONFIG operator*(CONFIG t);
CONFIG begin(CONFIG t);
CONFIG end(CONFIG t);


class Block {
public:
	Block(GridLoc);
	void setLoc(GridLoc);
	GridLoc getLoc();
private:
	GridLoc loc;
};
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