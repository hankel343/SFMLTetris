#ifndef TEXTBOX_H
#define TEXTBOX_H

#include <iostream>
#include <SFML\Graphics.hpp>
#include <sstream>

#define DELETE_KEY 8
#define ENTER_KEY 13
#define ESCAPE_KEY 27

using namespace std;
using namespace sf;

class TextBox
{
private:

	/*Text Object*/
	Text BoxText; //Renders text to the SFML window
	ostringstream text; //String stream stores characters (character buffer)

	/*Text Box Logic*/
	bool bIsSelected = false;
	bool bHasLimit = false;
	int nLimit;

	/*Private Processing of Data*/
	void ProcessInput(int nCharTyped);
	//Pre: nCharTyped has been initialized.
	//Post: The appropriate action is taken for the entered character.

	void DeletePrevChar();
	//Pre: None
	//Post: A new string with one less character is saved to the text variable

public:
	TextBox(int nSize, Color TextColor, bool bSelected);

	void SetFont(sf::Font& font);
	//Pre: The font file has been successfully read from file
	//Post:  The text box text font has been set

	void SetPosition(Vector2f pos);
	//Pre: The float values specified in the arguement are valid coordinates for the SFML window.
	//Post: The position of the textbox in the SFML window is set.

	void SetLimit(bool bHasLimit);
	//Pre: The relevant parameter has been initialized
	//Post: The maximum number of elements in the text box is set

	void SetLimit(bool bHasLimit, int nLimit);
	//Pre: The relevant parametrs have been initialized.
	//Post: The maximum limit is set.

	void SetSelected(bool bSelected);
	//Pre: The relevant parameter has been initialized.
	//Post: Text box has been selected and can be typed in

	string GetText();
	//Pre: The text attribute has been initialized
	//Post: string value of the text attribute is returned

	void DrawTo(RenderWindow& window);
	//Pre: A RenderWindow object has been instantiated
	//Post: The text box is drawn to the SFML RenderWindow

	void TypedOn(Event gameEvent);
	//Pre: An SFML Event object has been instantiated
	//Post: Entered text is rendered to the SFML window
};

#endif TEXTBOX_H
