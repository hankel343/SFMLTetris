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
	Block Tetrominos;
	Board GameBoard;
	RenderWindow gameWindow(VideoMode(250, 500), "Tetris");
	RectangleShape cell(Vector2f(25, 25));

	//Creates first block pseudo-randomly:
	Tetrominos.CreateNewBlock();

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
				case Keyboard::Left:	Tetrominos.MoveBlockLeft();
										if (Tetrominos.DoesBlockFit() == false)
											Tetrominos.MoveBlockRight();
										break;

				case Keyboard::Right:	Tetrominos.MoveBlockRight();
										if (Tetrominos.DoesBlockFit() == false)
											Tetrominos.MoveBlockLeft();
										break;

				case Keyboard::Down:	Tetrominos.MoveBlockDown();
										if (Tetrominos.DoesBlockFit() == false)
											Tetrominos.MoveBlockUp();
										break;
				}
			}
				
		}
		gameWindow.clear();
		Tetrominos.DrawBlock(gameWindow, cell);
		gameWindow.display();
	}

	return 0;
}