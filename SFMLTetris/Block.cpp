#include "Block.h"

void Block::CreateNewBlock()
{
	nBlockType = std::rand() % 7;
	nPosx = 5; //Corresponds to the middle of the game board.
	nPosy = 0; //Board Height
}

int Block::GetCellSize()
{
	return nCellSize;
}

void Block::DrawBlock(sf::RenderWindow &window, sf::RectangleShape &cell)
{
	//Color of cell is set according to the current type.
	cell.setFillColor(block_color[nBlockType]);
	
	for (int y = 0; y < 4; y++) for (int x = 0; x < 4; x++)
		if (tetrominos[nBlockType][y][x]) //If a 0 is not found in the tetrominos array at the given coordinates
		{
			cell.setPosition(sf::Vector2f((nPosx + x)*nCellSize, (nPosy + y)*nCellSize));
			window.draw(cell);
		}
}