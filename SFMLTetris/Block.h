#ifndef BLOCK_H
#define BLOCK_H
#include <cstdlib>
#include <iostream>
#include <SFML\Graphics.hpp>

class Block
{
private:
	int nCellSize = 25; //Width in pixels in the SFML window of a single cell that makes up a tetromino block.
	const int nBoardWidth = 10;
	const int nBoardHeight = 20;
	int nCurrentBlockType;	//Stores the integer code for each tetromino.
	int nNextBlockType = 0;
	int nHeldBlockType = -1;
	int nPieceCount = 0;
	int nPosx; //Current x position of block
	int nPosy; //Current y position of block

	void Swap(int& num1, int& num2);
	//Pre: The tetrominos array has been initialized
	//Post: The data of the two memory locations has been swapped.

public:

	void CreateNewBlock();
	//Pre: A block object has been created.
	//Post: A new block and next block are randomly generated. The new block's coordinates are set to the middle of the screen.

	void DrawBlock(sf::RenderWindow& window, sf::RectangleShape& cell, sf::RectangleShape& nextCell, sf::RectangleShape& heldCell);
	//Pre: Objects of classes RenderWindow and RectangleShape have been instansiated and passed as arguments.
	//Post: The falling block, next block, and held block are rendered to the SFML window.

	void MoveBlockLeft();
	//Pre: The CreateNewBlock() method has been called to initialize nCurrentBlockType
	//Post: The x position of the current block is translated one space to the left in the playfield.

	void MoveBlockRight();
	//Pre: The CreateNewBlock() method has been called to initialize nCurrentBlockType
	//Post: The x position of the current block is translated one space to the right in the playfield.

	void MoveBlockDown();
	//Pre: The CreateNewBlock() method has been called to initialize nCurrentBlockType
	//Post: The y position of the current block is translated one space down (nPosy++) in the playfield.

	void MoveBlockUp();
	//Pre: The CreateNewBlock() method has been called to initialize nCurrentBlockType
	//Post: The y position of the current block is tranlated one space up (nPosy--) in the playfield.

	int GetBlockType();
	//Pre: The CreateNewBlock() method has been called to initialize nCurrentBlockType
	//Post: Value of nCurrentBlock is returned to caller.

	int GetX();
	//Pre: The CreateNewBlock() method has been called to initialize nCurrentBlockType
	//Post: The x position of the block in the playfield is returned to the caller.

	int GetY();
	//Pre: The CreateNewBlock() method has been called to initialize nCurrentBlockType
	//Post:: The y position of the block in the playfield is returned to the caller.

	sf::Color GetColor(int nType);
	//Pre: The CreateNewBlock() method has been called to initialize nCurrentBlockType
	//Post: A value representing the SFML color enum is returned based off of the value of the block's type. 

	int GetCellSize();
	//Pre: Cell size has been initialized.
	//Post: The integer value representing the size in pixels of a SFML window cell is returned.

	void Rotate();
	//Pre: The CreateNewBlock() method has been called to initialize nCurrentBlockType
	//Post: The current block is rotated 90 degrees to the right of its original position.

	void SwapBlocks(sf::RenderWindow& window, sf::RectangleShape& cell);
	//Pre: The CreateNewBlock() method has been called to initialize nCurrentBlockType
	//Post: The nCurrentBlock is saved to nHeldBlock, and nHeldBlock becomes nCurrentBlock.

	void RenderSwaped(sf::RenderWindow& window, int nType, sf::RectangleShape& cell);
	//Pre: The CreateNewBlock() method has been called to initialize nCurrentBlockType
	//Post:: Previously nHeldBlock (nCurrentBlock at call time) is rendered to the screen.

	//Three dimensional array that serves as the logical representation of tetrominos in the playfield.
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