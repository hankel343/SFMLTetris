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
			{
				return false;
			}

			if (PlayField[Tetromino.GetY() + y][Tetromino.GetX() + x])
			{
				return false;
			}
		}

	return true;
}

bool Board::PushDown(Block& Tetromino)
{
	Tetromino.MoveBlockDown();
	if (this->DoesBlockFit(Tetromino) == false)
	{
		Tetromino.MoveBlockUp();
		this->CopyBlockToBoard(Tetromino);
		this->RemoveLine();
		Tetromino.CreateNewBlock();
		return false;
	}

	return true;
}

void Board::RemoveLine()
{
	int nNew = nBOARD_HEIGHT - 1;
	//Starting at bottom working to the top of the playfield
	for (int nOld = nBOARD_HEIGHT - 1; nOld >= 0; nOld--)
	{
		int nCount = 0;
		//Scanning along the width of the board counting non-zero elements of the playfield...
		for (int x = 0; x < nBOARD_WIDTH; x++)
			if (PlayField[nOld][x])
				nCount++;

		//If nCount is less than nBOARD_WIDTH, meaning an incomplete line was found -
		//the line will be copied to the the new array and will remain in the playfield
		if (nCount < nBOARD_WIDTH)
		{
			for (int x = 0; x < nBOARD_WIDTH; x++)
				PlayField[nNew][x] = PlayField[nOld][x];
			nNew--;
		}

		//If nCount was equal to nBOARD_WIDTH, a complete line was found and it is not copied -
		//to the updated playfield meaning it is deleted.
	}
}