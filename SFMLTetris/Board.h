#ifndef BOARD_H
#define BOARD_H
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include "Block.h"



class Board
{
private:
	static const int nBOARD_WIDTH = 10;
	static const int nBOARD_HEIGHT = 20;
	int PlayField[nBOARD_HEIGHT][nBOARD_WIDTH];
	int nScore = 0;

public:
	Board();
	int GetBoardWidth() const;
	int GetBoardHeight() const;
	void CopyBlockToBoard(Block &Tetromino);
	void DisplayField(sf::RenderWindow &window, Block &tetromino, sf::RectangleShape &cell) const;
	bool DoesBlockFit(Block& Tetromino);
	bool PushDown(bool& bLineRemoved, Block& Tetromino);
	void RemoveLine(bool &bLineRemoved);
	void CalcScoreIncrease(int nLinesRemoved);
};

#endif BOARD_H