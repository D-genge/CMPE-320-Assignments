#include "player.h"

Player::Player(int id) :
	moved(false),
	ID(id)
{
	for (auto type : CONFIG()) {
		availPieces.push_back(GamePiece(type));
	}
}


GamePiece Player::getAvalPiece() //set playerID as parameter to func
{
	return availPieces.at(rand() % availPieces.size());
}
