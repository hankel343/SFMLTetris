#include "Block.h"

void Block::CreateNewBlock()
{
	nBlockType = std::rand() % 7;
	nPosx = nBoardWidth / 2; //Corresponds to the middle of the game board.
	nPosy = 0; //Board Height
}

void Block::DrawBlock(sf::RenderWindow &window, sf::RectangleShape &cell)
{
	//Color of cell is set according to the current type.
	cell.setFillColor(this->GetColor(this->GetBlockType()));
	
	for (int y = 0; y < 4; y++) for (int x = 0; x < 4; x++)
		if (tetrominos[nBlockType][y][x]) //If a 0 is not found in the tetrominos array at the given coordinates
		{
			cell.setPosition(sf::Vector2f((nPosx + x)*nCellSize, (nPosy + y)*nCellSize));
			window.draw(cell);
		}
}

void Block::MoveBlockLeft()
{
	nPosx--;
}

void Block::MoveBlockRight()
{
	nPosx++;
}

void Block::MoveBlockDown()
{
	nPosy++;
}

void Block::MoveBlockUp()
{
	nPosy--;
}

bool Block::DoesBlockFit()
{
	for (int y = 0; y < 4; y++)
		for (int x = 0; x < 4; x++)
		{
			if (tetrominos[nBlockType][y][x] == 0) 
				continue;

			if (nPosx + x < 0 || nPosx + x >= 10 || nPosy + y >= 20) 
				return false;
		}

	return true;
}

int Block::GetBlockType()
{
	return nBlockType;
}

int Block::GetX()
{
	return nPosx;
}

int Block::GetY()
{
	return nPosy;
}

sf::Color Block::GetColor(int nType)
{
	switch (nType)
	{
	case 0:	return sf::Color::Green;
	case 1:	return sf::Color::Blue;
	case 2:	return sf::Color::Red;
	case 3:	return sf::Color::Yellow;
	case 4:	return sf::Color::White;
	case 5:	return sf::Color::Magenta;
	case 6: return sf::Color::Cyan;
	}

	return sf::Color::Black;
}

int Block::GetCellSize()
{
	return nCellSize;
}
