#include "SFML\Graphics.hpp"
using namespace sf;

int main()
{
	//Creates an object of the window class. VideoMode sets the dimensions of the window.
	RenderWindow window(VideoMode(640, 840), "Baby's first window");

	//This is the render/game loop. isOpen will return true if the window's state is currently open.
	while (window.isOpen())
	{
		Event event; //Creating an event object

		//Event processing loop. pollEvent will return true as long as there was an unprocessed event. False if none.
		while (window.pollEvent(event))
		{
			//If the user closes the window
			if (event.type == Event::Closed)
				window.close(); //Set the window object to closed as well.
		}
	}


	return 0;
}