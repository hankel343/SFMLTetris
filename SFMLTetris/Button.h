#ifndef BUTTON_H
#define BUTTON_H

#include <SFML\graphics.hpp>

class Button
{
private:

	sf::RectangleShape button;
	sf::Text t_ButtonText;

public:

	Button(std::string t, sf::Vector2f size, int nCharSize, sf::Color buttonColor, sf::Color textColor);
	void SetFont(sf::Font& font);
	void SetButtonColor(sf::Color color);
	void SetTextColor(sf::Color color);
	void SetPosition(sf::Vector2f pos);
	void DrawButton(sf::RenderWindow& window);
	bool isMouseOver(sf::RenderWindow& window);
};

#endif BUTTON_H