#include "Board.h"

Board::Board()
{
	for (int y = 0; y < nBOARD_HEIGHT; y++)
		for (int x = 0; x < nBOARD_WIDTH; x++)
		{
			PlayField[y][x] = 0;
		}
}

int Board::GetBoardWidth() const
{
	return nBOARD_WIDTH;
}

int Board::GetBoardHeight() const
{
	return nBOARD_HEIGHT;
}

void Board::CopyBlockToBoard(Block& Tetromino)
{
	for (int y = 0; y < 4; y++)
		for (int x = 0; x < 4; x++)
		{
			if (Tetromino.tetrominos[Tetromino.GetBlockType()][y][x])
				PlayField[Tetromino.GetY() + y][Tetromino.GetX() + x] = Tetromino.GetBlockType() + 1;
		}
}

void Board::DisplayField(sf::RenderWindow &window, Block &Tetromino, sf::RectangleShape &cell) const
{
	for (int y = 0; y < nBOARD_HEIGHT; y++)
		for (int x = 0; x < nBOARD_WIDTH; x++)
		{
			if (PlayField[y][x])
			{
				cell.setFillColor(Tetromino.GetColor(PlayField[y][x] - 1));
				cell.setPosition(sf::Vector2f(x * Tetromino.GetCellSize(), y * Tetromino.GetCellSize()));
				window.draw(cell);
			}
		}
}

bool Board::DoesBlockFit(Block& Tetromino)
{
	for (int y = 0; y < 4; y++)
		for (int x = 0; x < 4; x++)
		{
			if (Tetromino.tetrominos[Tetromino.GetBlockType()][y][x] == 0)
				continue;

			if (Tetromino.GetX() + x < 0 || Tetromino.GetX() + x >= 10 || Tetromino.GetY() + y >= 20)
				return false;

			if (PlayField[Tetromino.GetY() + y][Tetromino.GetX() + x])
				return false;
		}

	return true;
}