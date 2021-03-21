#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Block.h"
#include "Board.h"
#include <time.h>

using namespace std;
using namespace sf;

int main()
{
	srand(time(0));

	/*Creating game objects*/
	Block Tetromino;
	Board GameBoard;
	RenderWindow gameWindow(VideoMode(250, 500), "Tetris");
	RectangleShape cell(Vector2f(25, 25));
	Clock clock;

	/*Plays Tetris theme on repeat*/
	Music Theme;
	Theme.openFromFile("Tetris.ogg");
	Theme.setVolume(100);
	Theme.setLoop(true);
	Theme.play();

	/*Sound buffer for temporary sound effects*/
	SoundBuffer sBuffer;
	Sound gameSound;

	/*Game logic identifiers*/
	Tetromino.CreateNewBlock();

	while (gameWindow.isOpen())
	{
		static float prev = clock.getElapsedTime().asSeconds();
		if (clock.getElapsedTime().asSeconds() - prev >= 0.5)
		{
			prev = clock.getElapsedTime().asSeconds();
			if (GameBoard.PushDown(Tetromino) == false)
			{
				sBuffer.loadFromFile("piece_placed.ogg");
				gameSound.setBuffer(sBuffer);
				gameSound.play();
			}
		}

		Event gameEvent;

		/*Process user input and game events*/
		if (gameWindow.pollEvent(gameEvent))
		{
			if (gameEvent.type == Event::Closed)
				gameWindow.close();

			if (gameEvent.type == Event::KeyPressed)
			{
				switch (gameEvent.key.code)
				{
				case Keyboard::Left:	
										Tetromino.MoveBlockLeft();
										if (GameBoard.DoesBlockFit(Tetromino) == false)
											Tetromino.MoveBlockRight();
										break;

				case Keyboard::Right:	Tetromino.MoveBlockRight();
										if (GameBoard.DoesBlockFit(Tetromino) == false)
											Tetromino.MoveBlockLeft();
										break;

				case Keyboard::Down:	if (GameBoard.PushDown(Tetromino) == false)
										{
											sBuffer.loadFromFile("piece_placed.ogg");
											gameSound.setBuffer(sBuffer);
											gameSound.play();
										}
										break;
				
				//Rotate block:
				case Keyboard::Up:		Tetromino.Rotate();
										sBuffer.loadFromFile("move.ogg");
										gameSound.setBuffer(sBuffer);
										gameSound.play();
										break;
				
				//Drop block
				case Keyboard::Space:	while (GameBoard.PushDown(Tetromino) == true);
										break;
				}
			}
				
		}


		gameWindow.clear();
		GameBoard.DisplayField(gameWindow, Tetromino, cell);
		Tetromino.DrawBlock(gameWindow, cell);
		gameWindow.display();
	}

	return 0;
}