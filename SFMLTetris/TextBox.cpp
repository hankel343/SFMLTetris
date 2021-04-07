#include "TextBox.h"

TextBox::TextBox(int nSize, sf::Color color, bool bSelected)
{
	BoxText.setCharacterSize(nSize);
	BoxText.setFillColor(color);
	bIsSelected = bSelected;

	if (bSelected)
		BoxText.setString("_");
	else
		BoxText.setString("");
}

void TextBox::SetFont(Font& font)
{
	BoxText.setFont(font);
}

void TextBox::SetPosition(sf::Vector2f pos)
{
	BoxText.setPosition(pos);
}

void TextBox::SetLimit(bool ToF)
{
	bHasLimit = ToF;
}

void TextBox::SetLimit(bool ToF, int nLimit)
{
	bHasLimit = ToF;
	this->nLimit = nLimit - 1;
}

void TextBox::SetSelected(bool bSelected)
{
	bIsSelected = bSelected;

	if (!bSelected)
	{
		string t = text.str();
		string newT = "";
		
		//String is copied to a new string object and displayed
		for (int i = 0; i < t.length(); i++)
		{
			newT += t[i];
		}

		BoxText.setString(newT);
	}
}

string TextBox::GetText()
{
	return text.str();
}

void TextBox::DrawTo(RenderWindow& window)
{
	window.draw(BoxText);
}

void TextBox::TypedOn(Event gameEvent)
{
	if (bIsSelected)
	{
		int nCharTyped = gameEvent.text.unicode;

		//If entered value has an ascii code less than 128
		if (nCharTyped < 128)
		{
			if (bHasLimit) //If there is a limit to the number of characters in the textbox
			{
				if (text.str().length() <= nLimit) { //Verify that the current length is less than the limit
					ProcessInput(nCharTyped);
				} else if (text.str().length() > nLimit && nCharTyped == DELETE_KEY) { //Delete previously typed character
					DeletePrevChar();
				}
			} else {
				ProcessInput(nCharTyped);
			}
		}
	}
}

void TextBox::ProcessInput(int nCharTyped)
{
	if (nCharTyped != DELETE_KEY && nCharTyped != ENTER_KEY && nCharTyped != ESCAPE_KEY) //If anything other than delete, enter, or escape
		text << char(nCharTyped);
	else if (nCharTyped == DELETE_KEY) //If delete is pressed
	{
		if (text.str().length() > 0) {
			DeletePrevChar(); //Remove last character
		}
	}

	BoxText.setString(text.str() + "_");
}

void TextBox::DeletePrevChar()
{
	string t = text.str();
	string newT = "";

	//Copy the current string with one less character
	for (int i = 0; i < t.length()-1; i++)
	{
		newT += t[i];
	}

	text.str("");
	text << newT;

	BoxText.setString(text.str());
}