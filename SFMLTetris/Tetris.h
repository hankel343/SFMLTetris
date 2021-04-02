#ifndef TETRIS_H
#define TETRIS_H
#include <SFML/Graphics.hpp>
#include "Block.h"
#include "Board.h"
#include "Button.h"
#include "SoundManager.h"
#include "RenderManager.h"

using namespace sf;
using namespace std;

class Tetris
{
private:
	Block Tetromino;
	Board GameBoard;
	RectangleShape currentCell;
	RectangleShape nextCell;
	RectangleShape heldCell;
	Font font;
	Button MenuButton = Button("Menu", { 100, 100 }, 15, Color::Green, Color::Black);
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
	void Start(RenderWindow& gameWindow);
	void ProcessGameEvent(RenderWindow& gameWindow);
	void GameTick();
	void CheckDifficulty();
	void DrawScreen(RenderWindow& gameWindow);
};

#endif TETRIS_H