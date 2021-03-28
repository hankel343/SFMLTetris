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
	int nCurrentBlockType;	//Stores the integer code for each tetromino.
	int nNextBlockType = 0;
	int nHeldBlockType = -1;
	int nPieceCount = 0;
	int nPosx; //Current x position of block
	int nPosy; //Current y position of block

public:

	void CreateNewBlock();
	void DrawBlock(sf::RenderWindow &window, sf::RectangleShape &cell, sf::RectangleShape &nextCell, sf::RectangleShape& heldCell);
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
	void SwapBlocks(sf::RenderWindow& window, sf::RectangleShape& cell);
	void RenderSwaped(sf::RenderWindow& window, int nType, sf::RectangleShape &cell);

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