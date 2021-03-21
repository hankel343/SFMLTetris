#ifndef BOARD_H
#define BOARD_H
#include <SFML\Graphics.hpp>
#include "Block.h"



class Board
{
private:
	static const int nBOARD_WIDTH = 10;
	static const int nBOARD_HEIGHT = 20;
	int PlayField[nBOARD_HEIGHT][nBOARD_WIDTH];

public:
	Board();
	int GetBoardWidth() const;
	int GetBoardHeight() const;
	void CopyBlockToBoard(Block &Tetromino);
	void DisplayField(sf::RenderWindow &window, Block &tetromino, sf::RectangleShape &cell) const;
	bool DoesBlockFit(Block& Tetromino);
};

#endif BOARD_H