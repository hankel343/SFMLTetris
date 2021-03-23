#ifndef TETRIS_H
#define TETRIS_H
#include <SFML/Graphics.hpp>
#include "Block.h"
#include "Board.h"

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
	Music Theme;
	SoundBuffer sBuffer;
	Sound gameSound;
	Event gameEvent;
	VertexArray Lines;
	bool bLineRemoved = false;
	bool bGameOver = false;

public:
	Tetris();
	void Start();
	void ProcessGameEvent();
	void GameTick();
	void InitializeVertexArray();
	void GameOver();
};

#endif TETRIS_H