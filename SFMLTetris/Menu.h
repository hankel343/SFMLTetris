#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>
#include "Button.h"
#include "Tetris.h"

using namespace sf;

class Menu
{
private:
	RenderWindow window;
	Button playButton = Button("Play", { 200, 50 }, 15, sf::Color::Black, sf::Color::Red);
	Button optionsButton = Button("Options", { 200, 50 }, 15, sf::Color::Black, sf::Color::Red);
	Button scoreboardButton = Button("Score", { 200, 50 }, 15, sf::Color::Black, sf::Color::Red);
	Button quitButton = Button("Quit", { 200, 50 }, 15, sf::Color::Black, sf::Color::Red);
	Font Chunk;
	Font MenuTextFont;
	Text t_MenuText;
	Texture tex_background;
	Sprite sp_background;

	void RecolorButtons();
	void ProcessClick();
	
public:
	Menu();
	void Start();
	void DrawMenu();
};

#endif MENU_H