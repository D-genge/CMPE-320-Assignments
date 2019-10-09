#include "game_board.h"

GameBoard::GameBoard(int width, int height) : 
	grid(height, std::vector<int>(width, 0))
{

}