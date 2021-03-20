#include <SFML/Graphics.hpp>
#include "Block.h"
#include "Board.h"
#include <time.h>

using namespace std;
using namespace sf;

int main()
{
	/*Creating game objects*/
	Block Tetrominos;
	Board GameBoard;

	srand(time(0));
	RenderWindow gameWindow(VideoMode(GameBoard.GetBoardWidth()*Tetrominos.GetCellSize(), GameBoard.GetBoardHeight()*Tetrominos.GetCellSize()), "Tetris");
	RectangleShape cell(Vector2f(25, 25));
	Tetrominos.CreateNewBlock();

	while (gameWindow.isOpen())
	{
		Event gameEvent;

		if (gameWindow.pollEvent(gameEvent))
		{
			if (gameEvent.type == Event::Closed)
				gameWindow.close();

			if (gameEvent.type == Keyboard::Space)
				Tetrominos.CreateNewBlock();
		}

		Tetrominos.DrawBlock(gameWindow, cell);
		gameWindow.display();
	}

	return 0;
}