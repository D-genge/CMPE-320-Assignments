#pragma once
class GridLoc {
public:
	GridLoc(int x, int y) : 
		x(x),
		y(y)
	{};
	int x;
	int y;
private:
};
enum class Config {
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
	Z5
};

class GamePiece {
public:
	GridLoc loc;
	Config config;
	bool flipped;
	short int rotations; //reference clockwise
private:
};