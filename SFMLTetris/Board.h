#ifndef BOARD_H
#define BOARD_H
#include <SFML\Graphics.hpp>

class Board
{
private:
	static const int nBOARD_WIDTH = 10;
	static const int nBOARD_HEIGHT = 20;
	int PlayField[nBOARD_WIDTH][nBOARD_HEIGHT];

public:
	Board();
	int GetBoardWidth() const;
	int GetBoardHeight() const;

};

#endif BOARD_H