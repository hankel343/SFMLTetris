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
	//Pre: The constructor is passed button text, dimensions, text size, its color, and text color
	//Post: A button object with specified parameters is instantiated.

	void SetFont(sf::Font& font);
	//Pre: A font object exists and has been properly initialized from a file.
	//Post: The text font for the button has been set.

	void SetButtonColor(sf::Color color);
	//Pre: None
	//Post: The button color has been set.

	void SetTextColor(sf::Color color);
	//Pre: A text object has been instantiated.
	//Post: The button's text color has been set.

	void SetPosition(sf::Vector2f pos);
	//Pre: The button object was instantiated successfully.
	//Post: The button's position (in pixel coordinates) is set in the SFML window.

	void DrawButton(sf::RenderWindow& window);
	//Pre: A SFML RenderWindow and button object have both been instantiated.
	//Post: The button object is rendered to the SFML render window.

	bool isMouseOver(sf::RenderWindow& window);
	//Pre: A SFML RenderWindow has been instantiated.
	//Post: Returns a bool after testing the condition to see if the mouse is over a button.
};

#endif BUTTON_H
