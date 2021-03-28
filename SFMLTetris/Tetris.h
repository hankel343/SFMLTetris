#ifndef TETRIS_H
#define TETRIS_H
#include <SFML/Graphics.hpp>
#include "Block.h"
#include "Board.h"
#include "SoundManager.h"
#include "RenderManager.h"

using namespace sf;
using namespace std;

class Tetris
{
private:
	Block Tetromino;
	Board GameBoard;
	RenderWindow gameWindow;
	RectangleShape currentCell;
	RectangleShape nextCell;
	RectangleShape heldCell;
	Clock clock;
	SoundManager SoundManager;
	RenderManager RenderManager;
	Event gameEvent;
	bool bLineRemoved = false;
	bool bGameOver = false;
	bool bLevelHold = false;
	float fDifficulty = 0.5;
	int nLevel = 0;

public:
	Tetris();
	void Start();
	void ProcessGameEvent();
	void GameTick();
	void GameOver();
	void CheckDifficulty();
	void DrawScreen();
};

#endif TETRIS_H