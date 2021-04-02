#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Tetris.h"
#include "Button.h"

using namespace std;
using namespace sf;

int main()
{
	srand(time(0));

	RenderWindow window;

	Vector2i centerWindow((VideoMode::getDesktopMode().width / 2) - 445, (VideoMode::getDesktopMode().height / 2) - 400);

	window.create(VideoMode(900, 900), "SFML Project", Style::Titlebar | Style::Close);
	window.setPosition(centerWindow);

	window.setKeyRepeatEnabled(true);

	sf::Font chunk;

	chunk.loadFromFile("ChunkFive-Regular.otf");

	Button btn1("My Button", { 200, 50 }, 20, sf::Color::Green, sf::Color::Black);
	btn1.SetPosition({ 100, 300 });
	btn1.SetFont(chunk);

	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();

			case sf::Event::MouseMoved:
				if (btn1.isMouseOver(window)) { //If mouse is over the button
					btn1.SetButtonColor(sf::Color::White); //set to white.
				} else { //If mouse is not over the button
					btn1.SetButtonColor(sf::Color::Red); //set to red.
				}
				break;

			case sf::Event::MouseButtonPressed:
				if (btn1.isMouseOver(window)) {
					cout << "You pressed my button.\n";
				}
			}
		}

		window.clear();
		btn1.DrawButton(window);
		window.display();
	}


	/*Tetris game;
	game.Start();*/



	return 0;
}