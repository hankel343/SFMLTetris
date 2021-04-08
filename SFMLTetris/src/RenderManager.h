#ifndef RENDER_MANAGER_H
#define RENDER_MANAGER_H

#include <SFML\Graphics.hpp>
#include <iostream>
#include "Block.h"
#include "Board.h"

class RenderManager
{
private:

	Block Tetromino;
	Board GameBoard;

	/*Text objects*/
	sf::Text t_UpText;
	sf::Text t_DownText;
	sf::Text t_LeftText;
	sf::Text t_RightText;
	sf::Text t_ScoreText;
	sf::Text t_LevelText;
	sf::Text t_LinesCleared;
	sf::Text t_NextBlock;
	sf::Text t_HeldBlock;
	sf::Text t_Swap;
	sf::Text t_Drop;
	sf::Font font;

	//VertexArray containing the color and position of the game border.
	sf::VertexArray Border;

	/*Texture objects for loading in images*/
	sf::Texture tex_UpArrow;
	sf::Texture tex_DownArrow;
	sf::Texture tex_LeftArrow;
	sf::Texture tex_RightArrow;
	sf::Texture tex_Swap;
	sf::Texture tex_Drop;

	/*Sprite objects for applying textures and rendering them to the screen*/
	sf::Sprite sp_UpArrow;
	sf::Sprite sp_DownArrow;
	sf::Sprite sp_LeftArrow;
	sf::Sprite sp_RightArrow;
	sf::Sprite sp_Drop;
	sf::Sprite sp_Swap;

public:
	RenderManager();
	void InitializeText(int nScore, int nLevel, int nLinesCleared);
	//Pre: Text assets opened successfully.
	//Post: Dimensions, color, and positions of text objects are set.

	void InitializeBorderVertexArray();
	//Pre: None
	//Post: The color and position of the game border has been set.

	void DrawText(sf::RenderWindow& gameWindow);
	//Pre: Text objects have been initialized successfully.
	//Post: Text objects are drawn to the SFML screen buffer.

	void DrawBorder(sf::RenderWindow& gameWindow);
	//Pre: VertexArray data has been initialized for the border.
	//Post: The game border is rendered to the screen.

	void DrawSprites(sf::RenderWindow& gameWindow);
	//Pre: Texture assets have been initailized.
	//Post: Textures are rendered to the screen.

	void UpdateCounters(int nScore, int nLevel, int nLinesCleared);
	//Pre: nScore, nLevel, and nLinesCleared have all been initialized.
	//Post: Text objects displaying counters are updated.

	void LoadImages();
	//Pre: Files to be loaded exist in the appropriate file path and are labeled with the right names.
	//Post: Texture objects have had images loaded to them.
};

#endif RENDER_MANAGER_H
