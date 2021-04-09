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

	//File output stream:
	ofstream outFile;
	
	/*SFML Render Objects*/
	RectangleShape currentCell;
	RectangleShape nextCell;
	RectangleShape heldCell;
	
	/*SFML Text Objects*/
	Font font;
	TextBox ScoreTextBox = TextBox(30, Color::White, true);
	Button MenuButton = Button("Menu", { 100, 100 }, 15, Color::Red, Color::Black);

	/*Game logic objects*/
	Block Tetromino;
	Board GameBoard;
	Clock clock;
	SoundManager SoundManager;
	RenderManager RenderManager;
	Event gameEvent;

	/*Game logic identifiers*/
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
	Tetris(int nVolume, bool bHasSFX); //Parameterized constructor to start game with no sound effects
	~Tetris();

	void Start(RenderWindow& gameWindow);
	//Pre: An SFML RenderWindow object has been instantiated
	//Post: The Tetris game loop has completed.

	void ProcessGameEvent(RenderWindow& gameWindow);
	//Pre: An SFML RenderWindow object has been instantiated 
	//Post: SFML Event queue has been delt with
	
	void GameTick();
	//Pre: An SFML clock object has been instantiated
	//Post: A single game tick has completed

	void CheckDifficulty();
	//Pre: None
	//Post: Difficulty is increased if conditions are met.

	void DrawScreen(RenderWindow& gameWindow);
	//Pre: A SFML RenderWindow has been instantiated.
	//Post: Text/button/block/board objects are written to the screen

	void PauseMenu(RenderWindow& gameWindow, Event& gameEvent);
	//Pre: SFML RenderWindow and Event objects have been instantiated
	//Post: The player has unpaused

	void GameOverScreen(RenderWindow& gameWindow, Board& GameBoard);
	//Pre: SFML RenderWindow and Board objects have been instantiated
	//Post: The game over screen has been presented and the user has entered their name for their score
};

#endif TETRIS_H
