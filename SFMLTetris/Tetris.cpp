#include "Tetris.h"

//Constructor initializes the render window and cell used for drawing shapes on screen.
Tetris::Tetris()
	:currentCell(sf::Vector2f(25, 25)), nextCell(sf::Vector2f(25, 25)), heldCell(sf::Vector2f(25, 25))
{
}

void Tetris::Start(RenderWindow& gameWindow)
{
	bGameOver = false;
	SoundManager.PlayMusic();
	Tetromino.CreateNewBlock();
	RenderManager.InitializeBorderVertexArray();
	RenderManager.InitializeText(GameBoard.GetScore(), nLevel, GameBoard.GetLinesCleared());
	RenderManager.LoadImages();

	while (!bGameOver)
	{
		GameTick();

		if (gameWindow.pollEvent(gameEvent))
			ProcessGameEvent(gameWindow);

		RenderManager.UpdateCounters(GameBoard.GetScore(), nLevel, GameBoard.GetLinesCleared());

		DrawScreen(gameWindow);
	}

	SoundManager.PlayGameOver();
	SoundManager.StopMusic();
}

void Tetris::ProcessGameEvent(RenderWindow& gameWindow)
{
	if (gameEvent.type == Event::KeyPressed)
		switch (gameEvent.key.code)
		{
		case Keyboard::Left:	Tetromino.MoveBlockLeft();
								if (GameBoard.DoesBlockFit(Tetromino) == false)
									Tetromino.MoveBlockRight();
								break;

		case Keyboard::Right:	Tetromino.MoveBlockRight();
								if (GameBoard.DoesBlockFit(Tetromino) == false)
									Tetromino.MoveBlockLeft();
								break;

		case Keyboard::Down:	if (GameBoard.PushDown(bLineRemoved, Tetromino, bLevelHold) == false)
								{
									CheckDifficulty();
									SoundManager.PlayPlaceBlock();

									if (bLineRemoved)
									{
										SoundManager.PlayLineRemoved();
										bLineRemoved = false;
									}
								}
								break;

		case Keyboard::Up:		Tetromino.Rotate();
								SoundManager.PlayMove();
								break;

		//Drop block
		case Keyboard::Space:	while (GameBoard.PushDown(bLineRemoved, Tetromino, bLevelHold) == true);
								CheckDifficulty();
								SoundManager.PlayPlaceBlock();
								break;

		case Keyboard::C:		Tetromino.SwapBlocks(gameWindow, currentCell);
								break;

		//Exit game
		case Keyboard::Escape:	bGameOver = true;
								break;
		}
}

void Tetris::GameTick()
{
	static float prev = clock.getElapsedTime().asSeconds();
	if (clock.getElapsedTime().asSeconds() - prev >= fDifficulty)
	{
		prev = clock.getElapsedTime().asSeconds();
		if (GameBoard.PushDown(bLineRemoved, Tetromino, bLevelHold) == false)
		{
			SoundManager.PlayPlaceBlock();
			CheckDifficulty();

			if (Tetromino.GetY() == 0 && GameBoard.PushDown(bLineRemoved, Tetromino, bLevelHold) == false)
				bGameOver = true;

			if (bLineRemoved)
			{
				SoundManager.PlayLineRemoved();
				bLineRemoved = false;
			}
		}
	}
}

void Tetris::CheckDifficulty()
{
	if (GameBoard.GetLinesCleared() % 10 == 0 && GameBoard.GetLinesCleared() != 0 && !bLevelHold)
	{
		nLevel++;
		fDifficulty -= .05;
		SoundManager.AdjustTempo();
		SoundManager.PlayLevelUp();
		bLevelHold = true;
	}
}

void Tetris::DrawScreen(RenderWindow& gameWindow)
{
	gameWindow.clear();
	GameBoard.DisplayField(gameWindow, Tetromino, currentCell);
	Tetromino.DrawBlock(gameWindow, currentCell, nextCell, heldCell);
	RenderManager.DrawBorder(gameWindow);
	RenderManager.DrawText(gameWindow);
	RenderManager.DrawSprites(gameWindow);
	gameWindow.display();
}