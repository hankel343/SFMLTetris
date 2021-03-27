#include "Tetris.h"

//Constructor initializes the render window and cell used for drawing shapes on screen.
Tetris::Tetris()
	: gameWindow(sf::VideoMode(500, 750), "Tetris"), cell(sf::Vector2f(25, 25)), Lines(LineStrip, 4)
{
	//Loading font files
	font.loadFromFile("Assets/Sounds/ChunkFive-Regular.otf");

	windowText.setFont(font);
	windowText.setCharacterSize(30);
	windowText.setFillColor(Color::Red);
	windowText.setStyle(Text::Regular);
}

void Tetris::Start()
{
	bGameOver = false;
	InitializeVertexArray();
	SoundManager.PlayMusic();
	Tetromino.CreateNewBlock();

	//Displaying text:
	windowText.setString("UP");
	windowText.setPosition(0, 550);

	while (!bGameOver)
	{
		GameTick();

		if (bGameOver)
			GameOver();

		if (gameWindow.pollEvent(gameEvent))
			ProcessGameEvent();

		gameWindow.clear();
		GameBoard.DisplayField(gameWindow, Tetromino, cell);
		Tetromino.DrawBlock(gameWindow, cell);
		gameWindow.draw(Lines);
		gameWindow.draw(windowText);
		gameWindow.display();
	}
}

void Tetris::ProcessGameEvent()
{
	if (gameEvent.type == Event::Closed)
		gameWindow.close();

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

		case Keyboard::Down:	if (GameBoard.PushDown(bLineRemoved, Tetromino) == false)
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
		case Keyboard::Space:	while (GameBoard.PushDown(bLineRemoved, Tetromino) == true);
								CheckDifficulty();
								SoundManager.PlayPlaceBlock();
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
		if (GameBoard.PushDown(bLineRemoved, Tetromino) == false)
		{
			CheckDifficulty();

			if (Tetromino.GetY() == 0 && GameBoard.PushDown(bLineRemoved, Tetromino) == false)
				bGameOver = true;

			SoundManager.PlayPlaceBlock();

			if (bLineRemoved)
			{
				SoundManager.PlayLineRemoved();
				bLineRemoved = false;
			}
		}
	}
}

void Tetris::InitializeVertexArray()
{
	Lines[0].position = Vector2f(0, 0);
	Lines[0].color = Color::Blue;
	Lines[1].position = Vector2f(250, 0);
	Lines[1].color = Color::Blue;
	Lines[2].position = Vector2f(250, 500);
	Lines[2].color = Color::Blue;
	Lines[3].position = Vector2f(0, 500);
	Lines[3].color = Color::Blue;
}

void Tetris::GameOver()
{
	std::cout << "Game over!!!\n";
	SoundManager.StopMusic();
	SoundManager.PlayGameOver();
	std::cout << "Press any key to continue.\n";
	std::cin.get();
	gameWindow.close();
}

void Tetris::CheckDifficulty()
{
	nPieceCount++;
	if (nPieceCount % 10 == 0 && nPieceCount >= 10)
	{
		nLevel++;
		fDifficulty -= .02;
		SoundManager.AdjustTempo();

		SoundManager.PlayLevelUp();
	}
}