#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Tetris.h"

using namespace std;
using namespace sf;

int main()
{
	srand(time(0));

	Tetris game;

	game.Start();

	return 0;
}