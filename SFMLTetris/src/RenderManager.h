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
	sf::VertexArray Border;

	sf::Texture tex_UpArrow;
	sf::Texture tex_DownArrow;
	sf::Texture tex_LeftArrow;
	sf::Texture tex_RightArrow;
	sf::Texture tex_Swap;
	sf::Texture tex_Drop;

	sf::Sprite sp_UpArrow;
	sf::Sprite sp_DownArrow;
	sf::Sprite sp_LeftArrow;
	sf::Sprite sp_RightArrow;
	sf::Sprite sp_Drop;
	sf::Sprite sp_Swap;

public:
	RenderManager();
	void InitializeText(int nScore, int nLevel, int nLinesCleared);
	void InitializeBorderVertexArray();
	void DrawText(sf::RenderWindow& gameWindow);
	void DrawBorder(sf::RenderWindow& gameWindow);
	void DrawSprites(sf::RenderWindow& gameWindow);
	void UpdateCounters(int nScore, int nLevel, int nLinesCleared);
	void LoadImages();
};

#endif RENDER_MANAGER_H