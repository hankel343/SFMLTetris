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
	int nLinesCleared = 0;

public:
	Board();
	int GetBoardWidth() const;
	//Pre: None
	//Post: The width dimension of the board is returned.

	int GetBoardHeight() const;
	//Pre: None
	//Post: The height dimension of the board is returned.

	void CopyBlockToBoard(Block &Tetromino);
	//Pre: None
	//Post: Currently falling block is copied to the playfield in its appropriate orientation

	void DisplayField(sf::RenderWindow &window, Block &tetromino, sf::RectangleShape &cell) const;
	//Pre: A RenderWindow, Block, and RectangleShape object have been instantiated.
	//Post: The current configuration of blocks in the playfield is rendered to the SFML window.

	bool DoesBlockFit(Block& Tetromino);
	//Pre: A Block object has been instantiated.
	//Post: A boolean value testing the condition that the currently falling block can fit in the specified location 

	bool PushDown(bool& bLineRemoved, Block& Tetromino, bool& bLevelHold);
	//Pre: A block object has been instantiated and the relevant parameter IDs are initialized.
	//Post: The currently falling block is translated down by one position in the playfield.

	void RemoveLine(bool &bLineRemoved, bool& bLevelHold);
	//Pre: The relevant parameter ids have been initialized.
	//Post: A new version of the playfield is rendered to the screen without completed lines.

	void CalcScoreIncrease(int nLinesRemoved, bool& bLevelHold);
	//Pre: The relevant parameter ids have been initailized.
	//Post: The appropriate number of points are credited to the player.

	int GetScore();
	//Pre: None
	//Post: The integer value representing the score is returned.

	int GetLinesCleared();
	//Pre: None
	//Post: The integer value representing the number of cleared lines is returned.
};

#endif BOARD_H