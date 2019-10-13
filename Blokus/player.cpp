#include "player.h"

Player::Player(int id) :
	moved(false),
	ID(id)
{
	for (auto type : CONFIG()) {
		availPieces.push_back(GamePiece(type));
	}
}


GamePiece Player::getAvalPiece()
{
	return availPieces.at(rand() % availPieces.size());
}
