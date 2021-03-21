#ifndef BLOCK_H
#define BLOCK_H
#include <cstdlib>
#include <iostream>
#include <SFML\Graphics.hpp>

class Block
{
private:
	int nCellSize = 25;
	const int nBoardWidth = 10;
	const int nBoardHeight = 20;
	int nBlockType;	//Stores the integer code for each tetromino.
	int nPosx; //Current x position of block
	int nPosy; //Current y position of block

public:

	void CreateNewBlock();
	void DrawBlock(sf::RenderWindow &window, sf::RectangleShape &cell);
	void MoveBlockLeft();
	void MoveBlockRight();
	void MoveBlockDown();
	void MoveBlockUp();
	int GetBlockType();
	int GetX();
	int GetY();
	sf::Color GetColor(int nType);
	int GetCellSize();
	void Rotate();

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

};

#endif BLOCK_H