#ifndef TETRIS_H
#define TETRIS_H
#include <SFML/Graphics.hpp>
#include "Block.h"
#include "Board.h"
#include "Button.h"
#include "SoundManager.h"
#include "RenderManager.h"
#include "TextBox.h"
#include <fstream>
#include <iostream>

using namespace sf;
using namespace std;



class Tetris
{
private:
	ofstream outFile;
	Block Tetromino;
	Board GameBoard;
	RectangleShape currentCell;
	RectangleShape nextCell;
	RectangleShape heldCell;
	Font font;
	Button MenuButton = Button("Menu", { 100, 100 }, 15, Color::Red, Color::Black);
	TextBox ScoreTextBox = TextBox(30, Color::White, true);
	Clock clock;
	SoundManager SoundManager;
	RenderManager RenderManager;
	Event gameEvent;
	bool bLineRemoved = false;
	bool bGameOver = false;
	bool bLevelHold = false;
	bool bPaused = false;
	int nVolume = 50;
	bool bHasSFX = true;
	float fDifficulty = 0.5;
	int nLevel = 0;

public:
	Tetris();
	Tetris(int nVolume, bool bHasSFX);
	~Tetris();

	void Start(RenderWindow& gameWindow);
	void ProcessGameEvent(RenderWindow& gameWindow);
	void GameTick();
	void CheckDifficulty();
	void DrawScreen(RenderWindow& gameWindow);
	void PauseMenu(RenderWindow& gameWindow, Event& gameEvent);
	void GameOverScreen(RenderWindow& gameWindow, Board& GameBoard);
};

#endif TETRIS_H