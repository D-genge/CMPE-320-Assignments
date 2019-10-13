#include "game_board.h"

GameBoard::GameBoard(int width, int height) : 
	width(width),
	height(height),
	grid(height, std::vector<int>(width, 0))
{

}

bool GameBoard::placePiece(GamePiece piece, GridLoc loc, Player p)
{
	if (placeable(piece, loc, p)) {
		for (auto& block : piece.getBlocks()) {
			GridLoc local = block.getLoc();
			local.x += loc.x;
			local.y += loc.y;
			grid[local.x][local.y] = p.getID();
		}
		return true;
	}
	return false;
}

bool GameBoard::placeable(GamePiece piece, GridLoc loc, Player p)
{
	bool cornerCheck = false; // if this becomes true the piece can be placed
	bool firstPiece = false;
	for (auto& block : piece.getBlocks()) {
		GridLoc local = block.getLoc();
		GridLoc onGrid = GridLoc(local.x + loc.x, local.y + loc.y);
		if (((onGrid.x == 0 && onGrid.y == 0) //bottom left
			|| (onGrid.x == width-1 && onGrid.y == 0) //bottom right
			|| (onGrid.x == 0 && onGrid.y == height - 1) //top left
			|| (onGrid.x == width - 1 && onGrid.y == height - 1)) //top right
			&& !p.hasMoved()) {
			firstPiece = true;
		}
		if (onGrid.x < 0 || onGrid.x >= width || onGrid.y < 0 || onGrid.y >= height) return false; // any pieces off the grid?
		if (grid[onGrid.x][onGrid.y] != 0) return false; // is there already a piece there?
		for (int x = -1; x <= 1; x+=2) {
			for (int y = -1; y <= 1; y +=2) {
				if (onGrid.x + x >= 0 && onGrid.x + x < width && onGrid.y + y >= 0 && onGrid.y +y < height) {
					if (grid[onGrid.x+x][onGrid.y+y] == p.getID()) { // if player owns the adjacent corner 
						cornerCheck = true;
					}
				}
			}
		}
	}
	return cornerCheck || firstPiece;
}
