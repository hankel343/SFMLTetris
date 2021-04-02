#include "Menu.h"

Menu::Menu()
	: window(VideoMode(640, 800), "Tetris", sf::Style::Titlebar | sf::Style::Close)
{
	//Centering window
	sf::Vector2i centerWindowCoordinates((sf::VideoMode::getDesktopMode().width / 2) - 445, (sf::VideoMode::getDesktopMode().height / 2) - 400);
	window.setPosition(centerWindowCoordinates);

	//Loading font from working directory of the project
	Chunk.loadFromFile("ChunkFive-Regular.otf");
	MenuTextFont.loadFromFile("Tetris.ttf");

	/*Setting fonts and positions for buttons*/
	playButton.SetFont(Chunk);
	playButton.SetPosition({ 220, 300 });

	optionsButton.SetFont(Chunk);
	optionsButton.SetPosition({ 220, 400 });

	scoreboardButton.SetFont(Chunk);
	scoreboardButton.SetPosition({ 220, 500 });

	quitButton.SetFont(Chunk);
	quitButton.SetPosition({ 220, 600 });

	/*Menu Text*/
	t_MenuText.setString("Tetris");
	t_MenuText.setFillColor(Color::Black);
	t_MenuText.setFont(MenuTextFont);
	t_MenuText.setPosition(150, 100);
	t_MenuText.setCharacterSize(100);

	/*Background picture*/
	tex_background.loadFromFile("Assets/tetris.png");
	sp_background.setTexture(tex_background);
	sp_background.setScale({ 4, 5 });

	/*Menu music*/
	MenuMusic.openFromFile("music_menu.ogg");
	MenuMusic.setVolume(nVolume);
	MenuMusic.setLoop(true);
}

void Menu::Start()
{
	MenuMusic.play();
	while (window.isOpen())
	{
		Event gameEvent;

		if (window.pollEvent(gameEvent))
		{
			switch (gameEvent.type)
			{
			case Event::Closed:
				window.close();
				break;

			case Event::MouseMoved:
				RecolorButtons();
				break;

			case Event::MouseButtonPressed:
				ProcessClick();
				break;
			}

			if (gameEvent.type == Event::KeyPressed)
			{
				switch (gameEvent.key.code)
				{
				case Keyboard::Escape:	window.close();
										break;

				case Keyboard::P:		MenuMusic.pause();
										Tetris game(nVolume, bHasSFX);
										game.Start(window);
										MenuMusic.play();
										break;
				}
			}
		}

		window.clear();
		DrawMenu();
		window.display();
	}

	MenuMusic.stop();
}

void Menu::RecolorButtons()
{
	if (playButton.isMouseOver(window))
		playButton.SetButtonColor(Color::White);
	else
		playButton.SetButtonColor(Color::Black);

	if (optionsButton.isMouseOver(window))
		optionsButton.SetButtonColor(Color::White);
	else
		optionsButton.SetButtonColor(Color::Black);

	if (scoreboardButton.isMouseOver(window))
		scoreboardButton.SetButtonColor(Color::White);
	else
		scoreboardButton.SetButtonColor(Color::Black);

	if (quitButton.isMouseOver(window))
		quitButton.SetButtonColor(Color::White);
	else
		quitButton.SetButtonColor(Color::Black);
}

void Menu::ProcessClick()
{
	if (playButton.isMouseOver(window)) {
		MenuMusic.pause();
		Tetris game(nVolume, bHasSFX);
		game.Start(window);
		MenuMusic.play();
	} else if (optionsButton.isMouseOver(window)) {
		OptionsMenu();
	} else if (scoreboardButton.isMouseOver(window)) {
	
	} else if (quitButton.isMouseOver(window)) {
		window.close();
	}
}

void Menu::DrawMenu()
{
	window.draw(sp_background);
	playButton.DrawButton(window);
	optionsButton.DrawButton(window);
	scoreboardButton.DrawButton(window);
	quitButton.DrawButton(window);
	window.draw(t_MenuText);
}

void Menu::OptionsMenu()
{
	int nSelected = 0;
	bool bActive = false;

	RectangleShape OptionsBackGround(Vector2f(350, 400));
	OptionsBackGround.setFillColor(Color::Black);
	OptionsBackGround.setPosition(150, 300);

	/*Initializing options text*/
	Text VolumeText;
	VolumeText.setCharacterSize(25);
	VolumeText.setFillColor(Color::Red);
	VolumeText.setPosition({ 175, 350 });
	VolumeText.setString("Volume: ");
	VolumeText.setFont(Chunk);
	
	Text VolumeCounter;
	VolumeCounter.setCharacterSize(25);
	VolumeCounter.setFillColor(Color::Red);
	VolumeCounter.setPosition({ 300, 350 });
	VolumeCounter.setString(std::to_string(nVolume));
	VolumeCounter.setFont(Chunk);

	Text SfXText;
	SfXText.setCharacterSize(25);
	SfXText.setFillColor(Color::Red);
	SfXText.setPosition({ 175, 375 });
	SfXText.setString("SfX: ");
	SfXText.setFont(Chunk);

	Text ToFtext;
	ToFtext.setCharacterSize(25);
	ToFtext.setFillColor(Color::Red);
	ToFtext.setPosition({ 300, 375 });
	ToFtext.setString("True");
	ToFtext.setFont(Chunk);
	
	

	bool bExit = false;
	while (!bExit)
	{
		if (window.pollEvent(gameEvent))
		{
			if (gameEvent.type == Event::KeyPressed)
			{
				switch (gameEvent.key.code)
				{
				case Keyboard::Up: nSelected++;
									if (nSelected > 1)
										nSelected = 0;
									break;

				case Keyboard::Down: nSelected--;
									if (nSelected < 0)
										nSelected = 1;
									break;

				case Keyboard::Enter: 
				if (nSelected == 0)
				{
					VolumeCounter.setFillColor(Color::White);
					bActive = true;
					while (bActive)
					{
						if (window.pollEvent(gameEvent))
						{
							if (gameEvent.type == Event::KeyPressed)
							{
								switch (gameEvent.key.code)
								{
								case Keyboard::Up:	if (nVolume < 100)
														MenuMusic.setVolume(nVolume++);
													VolumeCounter.setString(std::to_string(nVolume));
													break;

								case Keyboard::Down:if (nVolume > 0)
														MenuMusic.setVolume(nVolume--);
													VolumeCounter.setString(std::to_string(nVolume));
													break;

								case Keyboard::Escape:	bActive = false;
														VolumeCounter.setFillColor(Color::Red);
														break;
								}
							}
						}

						window.clear();
						DrawMenu();
						window.draw(OptionsBackGround);
						window.draw(VolumeText);
						window.draw(VolumeCounter);
						window.draw(SfXText);
						window.draw(ToFtext);
						window.display();
					}
				} 
				else 
				{
					ToFtext.setFillColor(Color::White);
					bActive = true;
					while (bActive)
					{
						if (window.pollEvent(gameEvent))
						{
							if (gameEvent.type == Event::KeyPressed)
							{
								switch (gameEvent.key.code)
								{
								case Keyboard::Down:	bHasSFX = false;
														ToFtext.setString("False");
														break;

								case Keyboard::Up:		bHasSFX = true;
														ToFtext.setString("True");
														break;

								case Keyboard::Escape:	ToFtext.setFillColor(Color::Red);
														bActive = false;
														break;
								}
							}
						}
						window.clear();
						DrawMenu();
						window.draw(OptionsBackGround);
						window.draw(VolumeText);
						window.draw(VolumeCounter);
						window.draw(SfXText);
						window.draw(ToFtext);
						window.display();
					}
				}
				break;

				case Keyboard::Escape:	bExit = true;
										break;
				}
			}
		}
		
		if (nSelected == 0) {
			VolumeText.setFillColor(Color::White);
			SfXText.setFillColor(Color::Red);
		} else {
			VolumeText.setFillColor(Color::Red);
			SfXText.setFillColor(Color::White);
		}
			

		DrawMenu();
		window.draw(OptionsBackGround);
		window.draw(VolumeText);
		window.draw(VolumeCounter);
		window.draw(SfXText);
		window.draw(ToFtext);
		window.display();
	}
}