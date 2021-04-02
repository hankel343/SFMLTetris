#include "Menu.h"

Menu::Menu()
	: window(VideoMode(640, 800), "Tetris", sf::Style::Titlebar | sf::Style::Close)
{
	//Centering window
	sf::Vector2i centerWindowCoordinates((sf::VideoMode::getDesktopMode().width / 2) - 445, (sf::VideoMode::getDesktopMode().height / 2) - 400);
	window.setPosition(centerWindowCoordinates);

	//Loading font from working directory of the project
	font.loadFromFile("ChunkFive-Regular.otf");

	/*Setting fonts and positions for buttons*/
	playButton.SetFont(font);
	playButton.SetPosition({ 220, 300 });

	optionsButton.SetFont(font);
	optionsButton.SetPosition({ 220, 400 });

	scoreboardButton.SetFont(font);
	scoreboardButton.SetPosition({ 220, 500 });

	quitButton.SetFont(font);
	quitButton.SetPosition({ 220, 600 });
}

void Menu::Start()
{
	while (window.isOpen())
	{
		Event event;

		if (window.pollEvent(event))
		{
			switch (event.type)
			{
			case Event::Closed:
				window.close();
				break;

			case Event::MouseMoved:
				RecolorButtons();
				break;

			case Event::MouseButtonPressed:
				ProcessClick();
				break;

			}
		}

		window.clear();
		DrawMenu();
		window.display();
	}
}

void Menu::RecolorButtons()
{
	if (playButton.isMouseOver(window))
		playButton.SetButtonColor(Color::White);
	else
		playButton.SetButtonColor(Color::Green);

	if (optionsButton.isMouseOver(window))
		optionsButton.SetButtonColor(Color::White);
	else
		optionsButton.SetButtonColor(Color::Green);

	if (scoreboardButton.isMouseOver(window))
		scoreboardButton.SetButtonColor(Color::White);
	else
		scoreboardButton.SetButtonColor(Color::Green);

	if (quitButton.isMouseOver(window))
		quitButton.SetButtonColor(Color::White);
	else
		quitButton.SetButtonColor(Color::Green);
}

void Menu::ProcessClick()
{
	if (playButton.isMouseOver(window)) {
		Tetris game;
		game.Start(window);
	} else if (optionsButton.isMouseOver(window)) {
	
	} else if (scoreboardButton.isMouseOver(window)) {
	
	} else if (quitButton.isMouseOver(window)) {
		window.close();
	}
}

void Menu::DrawMenu()
{
	playButton.DrawButton(window);
	optionsButton.DrawButton(window);
	scoreboardButton.DrawButton(window);
	quitButton.DrawButton(window);
}