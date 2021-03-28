#include "RenderManager.h"

RenderManager::RenderManager()
	:Border(sf::LineStrip, 4)
{
	/*Initializing text attributes*/
	font.loadFromFile("ChunkFive-Regular.otf");
}

void RenderManager::InitializeText(int nScore, int nLevel, int nLinesCleared)
{
	t_UpText.setFont(font);
	t_UpText.setCharacterSize(30);
	t_UpText.setFillColor(sf::Color::Red);
	t_UpText.setStyle(sf::Text::Regular);
	t_UpText.setString("Up");
	t_UpText.setPosition(300, 550);

	sp_UpArrow.setPosition(400, 550);
	sp_UpArrow.setScale(.15, .15);

	t_LeftText.setFont(font);
	t_LeftText.setCharacterSize(30);
	t_LeftText.setFillColor(sf::Color::Red);
	t_LeftText.setStyle(sf::Text::Regular);
	t_LeftText.setString("Left");
	t_LeftText.setPosition(300, 650);

	sp_LeftArrow.setPosition(400, 650);
	sp_LeftArrow.setScale(.15, .15);

	t_DownText.setFont(font);
	t_DownText.setCharacterSize(30);
	t_DownText.setFillColor(sf::Color::Red);
	t_DownText.setStyle(sf::Text::Regular);
	t_DownText.setString("Down");
	t_DownText.setPosition(300, 600);

	sp_DownArrow.setPosition(400, 600);
	sp_DownArrow.setScale(.15, .15);

	t_RightText.setFont(font);
	t_RightText.setCharacterSize(30);
	t_RightText.setFillColor(sf::Color::Red);
	t_RightText.setStyle(sf::Text::Regular);
	t_RightText.setString("Right");
	t_RightText.setPosition(300, 700);

	sp_RightArrow.setPosition(400, 700);
	sp_RightArrow.setScale(.15, .15);

	t_ScoreText.setFont(font);
	t_ScoreText.setCharacterSize(30);
	t_ScoreText.setFillColor(sf::Color::Red);
	t_ScoreText.setStyle(sf::Text::Regular);
	std::string ScoreStr = std::to_string(nScore);
	t_ScoreText.setString("Score: " + ScoreStr);
	t_ScoreText.setPosition(0, 600);

	t_LevelText.setFont(font);
	t_LevelText.setCharacterSize(30);
	t_LevelText.setFillColor(sf::Color::Red);
	t_LevelText.setStyle(sf::Text::Regular);
	std::string LevelStr = std::to_string(nLevel);
	t_LevelText.setString("Level: " + LevelStr);
	t_LevelText.setPosition(0, 650);

	t_LinesCleared.setFont(font);
	t_LinesCleared.setCharacterSize(30);
	t_LinesCleared.setFillColor(sf::Color::Red);
	t_LinesCleared.setStyle(sf::Text::Regular);
	std::string LinesStr = std::to_string(nLinesCleared);
	t_LinesCleared.setString("Lines Cleared: " + LinesStr);
	t_LinesCleared.setPosition(0, 700);

	t_NextBlock.setFont(font);
	t_NextBlock.setCharacterSize(30);
	t_NextBlock.setFillColor(sf::Color::Red);
	t_NextBlock.setStyle(sf::Text::Regular);
	t_NextBlock.setString("Next Block:");
	t_NextBlock.setPosition(250, 0);

	t_HeldBlock.setFont(font);
	t_HeldBlock.setCharacterSize(30);
	t_HeldBlock.setFillColor(sf::Color::Red);
	t_HeldBlock.setStyle(sf::Text::Regular);
	t_HeldBlock.setString("Held Block:");
	t_HeldBlock.setPosition(250, 150);
}

void RenderManager::UpdateCounters(int nScore, int nLevel, int nLinesCleared)
{
	std::string ScoreStr = std::to_string(nScore);
	t_ScoreText.setString("Score: " + ScoreStr);

	std::string LevelStr = std::to_string(nLevel);
	t_LevelText.setString("Level: " + LevelStr);

	std::string LineStr = std::to_string(nLinesCleared);
	t_LinesCleared.setString("Lines Cleared: " + LineStr);
}

void RenderManager::InitializeBorderVertexArray()
{
	Border[0].position = sf::Vector2f(0, 0);
	Border[0].color = sf::Color::Blue;
	Border[1].position = sf::Vector2f(250, 0);
	Border[1].color = sf::Color::Blue;
	Border[2].position = sf::Vector2f(250, 500);
	Border[2].color = sf::Color::Blue;
	Border[3].position = sf::Vector2f(0, 500);
	Border[3].color = sf::Color::Blue;
}

void RenderManager::DrawText(sf::RenderWindow& gameWindow)
{
	gameWindow.draw(t_UpText);
	gameWindow.draw(t_DownText);
	gameWindow.draw(t_LeftText);
	gameWindow.draw(t_RightText);
	gameWindow.draw(t_ScoreText);
	gameWindow.draw(t_LevelText);
	gameWindow.draw(t_LinesCleared);
	gameWindow.draw(t_NextBlock);
	gameWindow.draw(t_HeldBlock);
}

void RenderManager::DrawBorder(sf::RenderWindow& gameWindow)
{
	gameWindow.draw(Border);
}

void RenderManager::LoadImages()
{
	if (!tex_UpArrow.loadFromFile("Assets/Up.png"))
		std::cout << "ERROR: Failed to load Assets/Up.png" << std::endl;
	else
		sp_UpArrow.setTexture(tex_UpArrow);

	if (!tex_DownArrow.loadFromFile("Assets/Down.png"))
		std::cout << "ERROR: Failed to load Assets/Down.png" << std::endl;
	else
		sp_DownArrow.setTexture(tex_DownArrow);

	if (!tex_LeftArrow.loadFromFile("Assets/Left.png"))
		std::cout << "ERROR: Failed to load Assets/Left.png" << std::endl;
	else
		sp_LeftArrow.setTexture(tex_LeftArrow);

	if (!tex_RightArrow.loadFromFile("Assets/Right.png"))
		std::cout << "ERROR: Failed to load Assets/Right.png" << std::endl;
	else
		sp_RightArrow.setTexture(tex_RightArrow);
	
}

void RenderManager::DrawSprites(sf::RenderWindow& gameWindow)
{
	gameWindow.draw(sp_UpArrow);
	gameWindow.draw(sp_DownArrow);
	gameWindow.draw(sp_LeftArrow);
	gameWindow.draw(sp_RightArrow);
}