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

void Player::removePiece(GamePiece piece)
{
	for (int i = 0; i < availPieces.size(); i++) {
		if (availPieces[i].type() == piece.type()) {
			availPieces.erase(availPieces.begin() + i);
			break;
		}
	}
}
