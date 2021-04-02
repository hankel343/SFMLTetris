#include "Button.h"

Button::Button(std::string t, sf::Vector2f size, int nCharSize, sf::Color buttonColor, sf::Color textColor)
{
	t_ButtonText.setFillColor(textColor);
	t_ButtonText.setCharacterSize(nCharSize);
	t_ButtonText.setString(t);

	button.setFillColor(buttonColor);
	button.setSize(size);
}

void Button::SetFont(sf::Font& font)
{
	t_ButtonText.setFont(font);
}

void Button::SetButtonColor(sf::Color color)
{
	button.setFillColor(color);
}

void Button::SetTextColor(sf::Color color)
{
	t_ButtonText.setFillColor(color);
}

void Button::SetPosition(sf::Vector2f position)
{
	button.setPosition(position);

	float nPosX = (position.x + button.getLocalBounds().width / 4) - (t_ButtonText.getLocalBounds().width / 2);
	float nPosY = (position.y + button.getLocalBounds().height / 2) - (t_ButtonText.getLocalBounds().height / 2);
	t_ButtonText.setPosition(nPosX, nPosY);
}

void Button::DrawButton(sf::RenderWindow& window)
{
	window.draw(t_ButtonText);
	window.draw(button);
}

bool Button::isMouseOver(sf::RenderWindow& window)
{
	//Ids to track position of mouse as floats
	float fMouseX = sf::Mouse::getPosition(window).x;
	float fMouseY = sf::Mouse::getPosition(window).y;

	//Ids to track position of button.
	float fButtonPosX = button.getPosition().x;
	float fButtonPosY = button.getPosition().y;

	//Ids to track dimensions of the button				//getLocalBounds() returns end x coordinate
	float fButtonXPosWidth = button.getPosition().x + button.getLocalBounds().width;
	float fButtonYPosHeight = button.getPosition().y + button.getLocalBounds().height;

	if (fMouseX < fButtonXPosWidth && fMouseX > fButtonPosX && fMouseY < fButtonYPosHeight && fMouseY > fButtonPosY) {
		return true; 
	}

	return false;
}