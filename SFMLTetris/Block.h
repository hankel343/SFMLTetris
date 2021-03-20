#ifndef BLOCK_H
#define BLOCK_H
#include <cstdlib>
#include <SFML\Graphics.hpp>

const sf::Color block_color[] =
{
	sf::Color::Green, sf::Color::Blue, sf::Color::Yellow,
	sf::Color::White, sf::Color::Magenta, sf::Color::Cyan
};

class Block
{
private:
	int nCellSize = 25;
	const int nBoardWidth = 10;
	const int nBoardHeight = 20;
	int nBlockType = 0;	//Stores the integer code for each tetromino.
	int nPosx = 5; //Current x position of block
	int nPosy = 0; //Current y position of block
	int tetrominos[7][4][4] =
	{
		//I block
		0,0,1,0,
		0,0,1,0,
		0,0,1,0,
		0,0,1,0,

		//Z block
		0,1,0,0,
		0,1,1,0,
		0,0,1,0,
		0,0,0,0,

		//N block
		0,0,1,0,
		0,1,1,0,
		0,1,0,0,
		0,0,0,0,

		//Square block
		0,1,1,0,
		0,1,1,0,
		0,0,0,0,
		0,0,0,0,

		//T block
		0,1,0,0,
		0,1,1,0,
		0,1,0,0,
		0,0,0,0,

		//L block
		0,1,0,0,
		0,1,0,0,
		0,1,1,0,
		0,0,0,0,

		//J block
		0,1,0,0,
		0,1,0,0,
		1,1,0,0,
		0,0,0,0,
	};

public:

	void CreateNewBlock();
	void CreateCell();
	void DrawBlock(sf::RenderWindow &window, sf::RectangleShape &cell);
	void MoveBlockLeft();
	void MoveBlockRight();
	void MoveBlockDown();
	void MoveBlockUp();
	bool DoesBlockFit();

};

#endif BLOCK_H