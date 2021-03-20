#include "Board.h"

Board::Board()
{
	//Scans through the PlayField array and sets all locations equal to 0.
	//0 represents an empty space in the playfield.
	for (int i = 0; i < nBOARD_HEIGHT; i++) for (int i = 0; i < nBOARD_WIDTH; i++)
		PlayField[nBOARD_HEIGHT][nBOARD_WIDTH] = 0;
}

int Board::GetBoardWidth() const
{
	return nBOARD_WIDTH;
}

int Board::GetBoardHeight() const
{
	return nBOARD_HEIGHT;
}