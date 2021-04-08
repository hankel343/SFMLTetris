#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>
#include "Button.h"
#include "Tetris.h"
#include "ScoreBoard.h"

using namespace sf;

class Menu
{
private:
	//SFML window objects:
	RenderWindow window;
	Event gameEvent;

	//Buttons and text:
	Button playButton = Button("Play", { 200, 50 }, 15, sf::Color::Black, sf::Color::Red);
	Button optionsButton = Button("Options", { 200, 50 }, 15, sf::Color::Black, sf::Color::Red);
	Button scoreboardButton = Button("Score", { 200, 50 }, 15, sf::Color::Black, sf::Color::Red);
	Button quitButton = Button("Quit", { 200, 50 }, 15, sf::Color::Black, sf::Color::Red);
	Font Chunk;
	Font MenuTextFont;
	Text t_MenuText;

	//Background image and texture:
	Texture tex_background;
	Sprite sp_background;

	//Sound objects and identifers:
	Music MenuMusic;
	int nVolume = 50;
	bool bHasSFX = true;

	ScoreBoard TetrisScoreBoard;

	//GUI logic:
	void RecolorButtons();
	//Pre: None
	//Post: Button color is changed to its highlighted color.

	void ProcessClick();
	//Pre: None
	//Post: The appropriate action is taken depending on where the user clicked.
	
public:
	Menu();
	void Start();
	//Pre: None
	//Post: The menu screen is rendered.

	void OptionsMenu();
	//Pre: SFML RenderWindow and GameEvent objects have been created.
	//Post: The user was able to make the desired changes to the options menu.

	void DisplayLeaderBoard();
	//Pre: A ScoreBoard object has been instantiated.
	//Post: The scoreboard is rendered to the screen.

	void DrawMenu();
	//Pre: Button objects have been instantiated.
	//Post: The main menu is rendered to the screen.
};

#endif MENU_H
