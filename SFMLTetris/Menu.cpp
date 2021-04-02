#include "Menu.h"

Menu::Menu()
	: window(VideoMode(640, 800), "Tetris", sf::Style::Titlebar | sf::Style::Close)
{
	//Centering window
	sf::Vector2i centerWindowCoordinates((sf::VideoMode::getDesktopMode().width / 2) - 445, (sf::VideoMode::getDesktopMode().height / 2) - 400);
	window.setPosition(centerWindowCoordinates);

	//Loading font from working directory of the project
	Chunk.loadFromFile("ChunkFive-Regular.otf");
	MenuTextFont.loadFromFile("Tetris.ttf");

	/*Setting fonts and positions for buttons*/
	playButton.SetFont(Chunk);
	playButton.SetPosition({ 220, 300 });

	optionsButton.SetFont(Chunk);
	optionsButton.SetPosition({ 220, 400 });

	scoreboardButton.SetFont(Chunk);
	scoreboardButton.SetPosition({ 220, 500 });

	quitButton.SetFont(Chunk);
	quitButton.SetPosition({ 220, 600 });

	/*Menu Text*/
	t_MenuText.setString("Tetris");
	t_MenuText.setFillColor(Color::Black);
	t_MenuText.setFont(MenuTextFont);
	t_MenuText.setPosition(150, 100);
	t_MenuText.setCharacterSize(100);

	/*Background picture*/
	tex_background.loadFromFile("Assets/tetris.png");
	sp_background.setTexture(tex_background);
	sp_background.setScale({ 4, 5 });
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

			if (event.type == Event::KeyPressed)
			{
				switch (event.key.code)
				{
				case Keyboard::Escape:	window.close();
										break;

				case Keyboard::P:		Tetris game;
										game.Start(window);
										break;
				}
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
		playButton.SetButtonColor(Color::Black);

	if (optionsButton.isMouseOver(window))
		optionsButton.SetButtonColor(Color::White);
	else
		optionsButton.SetButtonColor(Color::Black);

	if (scoreboardButton.isMouseOver(window))
		scoreboardButton.SetButtonColor(Color::White);
	else
		scoreboardButton.SetButtonColor(Color::Black);

	if (quitButton.isMouseOver(window))
		quitButton.SetButtonColor(Color::White);
	else
		quitButton.SetButtonColor(Color::Black);
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
	window.draw(sp_background);
	playButton.DrawButton(window);
	optionsButton.DrawButton(window);
	scoreboardButton.DrawButton(window);
	quitButton.DrawButton(window);
	window.draw(t_MenuText);
}