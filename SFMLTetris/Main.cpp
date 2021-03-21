#include <SFML/Graphics.hpp>
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

	//Creates first block pseudo-randomly:
	Tetromino.CreateNewBlock();

	while (gameWindow.isOpen())
	{
		static float prev = clock.getElapsedTime().asSeconds();
		if (clock.getElapsedTime().asSeconds() - prev >= 0.5)
		{
			prev = clock.getElapsedTime().asSeconds();

			Tetromino.MoveBlockDown();
			if (GameBoard.DoesBlockFit(Tetromino) == false)
			{
				Tetromino.MoveBlockUp();
				GameBoard.CopyBlockToBoard(Tetromino);
				Tetromino.CreateNewBlock();
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
				case Keyboard::Left:	Tetromino.MoveBlockLeft();
										if (GameBoard.DoesBlockFit(Tetromino) == false)
											Tetromino.MoveBlockRight();
										break;

				case Keyboard::Right:	Tetromino.MoveBlockRight();
										if (GameBoard.DoesBlockFit(Tetromino) == false)
											Tetromino.MoveBlockLeft();
										break;

				case Keyboard::Down:	Tetromino.MoveBlockDown();
										if (GameBoard.DoesBlockFit(Tetromino) == false)
										{
											Tetromino.MoveBlockUp();
											GameBoard.CopyBlockToBoard(Tetromino);
											Tetromino.CreateNewBlock();
										}
										break;

				case Keyboard::Up:		Tetromino.Rotate();
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