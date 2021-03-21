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

	//Creates first block pseudo-randomly:
	Tetromino.CreateNewBlock();

	while (gameWindow.isOpen())
	{
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
										if (Tetromino.DoesBlockFit() == false)
											Tetromino.MoveBlockRight();
										break;

				case Keyboard::Right:	Tetromino.MoveBlockRight();
										if (Tetromino.DoesBlockFit() == false)
											Tetromino.MoveBlockLeft();
										break;

				case Keyboard::Down:	Tetromino.MoveBlockDown();
										if (Tetromino.DoesBlockFit() == false)
										{
											Tetromino.MoveBlockUp();
											GameBoard.CopyBlockToBoard(Tetromino);
											Tetromino.CreateNewBlock();
										}
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