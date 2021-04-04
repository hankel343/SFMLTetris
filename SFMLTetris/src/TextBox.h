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

	Text BoxText;
	ostringstream text;
	bool bIsSelected = false;
	bool bHasLimit = false;
	int nLimit;

	void ProcessInput(int nCharTyped);
	void DeletePrevChar();

public:
	TextBox(int nSize, Color TextColor, bool bSelected);

	void SetFont(sf::Font& font);
	void SetPosition(Vector2f pos);
	void SetLimit(bool bHasLimit);
	void SetLimit(bool bHasLimit, int nLimit);
	void SetSelected(bool bSelected);
	string GetText();
	void DrawTo(RenderWindow& window);
	void TypedOn(Event gameEvent);

};

#endif TEXTBOX_H