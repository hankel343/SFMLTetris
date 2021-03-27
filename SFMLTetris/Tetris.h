#ifndef TETRIS_H
#define TETRIS_H
#include <SFML/Graphics.hpp>
#include "Block.h"
#include "Board.h"
#include "SoundManager.h"

using namespace sf;
using namespace std;

class Tetris
{
private:
	Block Tetromino;
	Board GameBoard;
	RenderWindow gameWindow;
	RectangleShape cell;
	Clock clock;
	SoundManager SoundManager;
	Event gameEvent;
	VertexArray Lines;
	Font font;
	Text windowText;
	bool bLineRemoved = false;
	bool bGameOver = false;
	int nPieceCount = 0;
	float fDifficulty = 0.5;
	int nLevel = 0;

public:
	Tetris();
	void Start();
	void ProcessGameEvent();
	void GameTick();
	void InitializeVertexArray();
	void GameOver();
	void CheckDifficulty();
};

#endif TETRIS_H