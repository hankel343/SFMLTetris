#include "Tetris.h"

//Constructor initializes the render window and cell used for drawing shapes on screen.
Tetris::Tetris()
	: gameWindow(sf::VideoMode(500, 750), "Tetris"), cell(sf::Vector2f(25, 25)), Lines(LineStrip, 4)
{
	Theme.openFromFile("Tetris.ogg");
	Theme.setVolume(50);
	Theme.setLoop(true);
}

void Tetris::Start()
{
	InitializeVertexArray();
	Theme.play();
	Tetromino.CreateNewBlock();

	while (gameWindow.isOpen())
	{
		GameTick();

		if (gameWindow.pollEvent(gameEvent))
			ProcessGameEvent();

		gameWindow.clear();
		GameBoard.DisplayField(gameWindow, Tetromino, cell);
		Tetromino.DrawBlock(gameWindow, cell);
		gameWindow.draw(Lines);
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
									sBuffer.loadFromFile("piece_placed.ogg");
									gameSound.setBuffer(sBuffer);
									gameSound.play();

									if (bLineRemoved)
									{
										sBuffer.loadFromFile("line_removed.ogg");
										gameSound.setBuffer(sBuffer);
										gameSound.play();
										bLineRemoved = false;
									}
								}
								break;

		case Keyboard::Up:		Tetromino.Rotate();
								sBuffer.loadFromFile("move.ogg");
								gameSound.setBuffer(sBuffer);
								gameSound.play();
								break;

		//Drop block
		case Keyboard::Space:	while (GameBoard.PushDown(bLineRemoved, Tetromino) == true);
								break;

		//Exit game
		case Keyboard::Escape:	gameWindow.close();
								break;
		}
}

void Tetris::GameTick()
{
	static float prev = clock.getElapsedTime().asSeconds();
	if (clock.getElapsedTime().asSeconds() - prev >= 0.5)
	{
		prev = clock.getElapsedTime().asSeconds();
		if (GameBoard.PushDown(bLineRemoved, Tetromino) == false)
		{
			sBuffer.loadFromFile("piece_placed.ogg");
			gameSound.setBuffer(sBuffer);
			gameSound.play();

			if (bLineRemoved)
			{
				sBuffer.loadFromFile("line_removed.ogg");
				gameSound.setBuffer(sBuffer);
				gameSound.play();
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