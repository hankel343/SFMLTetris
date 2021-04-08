#include "Tetris.h"

//Constructor initializes the render window and cell used for drawing shapes on screen.
Tetris::Tetris()
	:currentCell(sf::Vector2f(25, 25)), nextCell(sf::Vector2f(25, 25)), heldCell(sf::Vector2f(25, 25))
{
	font.loadFromFile("Assets/fonts/ChunkFive-Regular.otf");
	MenuButton.SetFont(font);
	MenuButton.SetPosition({ 300, 300 });

	outFile.open("scores.txt", ios::app);
}

Tetris::Tetris(int nVolume, bool bHasSFX)
	:currentCell(sf::Vector2f(25, 25)), nextCell(sf::Vector2f(25, 25)), heldCell(sf::Vector2f(25, 25))
{
	font.loadFromFile("Assets/fonts/ChunkFive-Regular.otf");
	MenuButton.SetFont(font);
	MenuButton.SetPosition({ 300, 300 });

	this->nVolume = nVolume;
	this->bHasSFX = bHasSFX;

	outFile.open("scores.txt", ios::app);
}

void Tetris::Start(RenderWindow& gameWindow)
{
	bGameOver = false;
	SoundManager.PlayMusic(nVolume);
	Tetromino.CreateNewBlock();
	RenderManager.InitializeBorderVertexArray();
	RenderManager.InitializeText(GameBoard.GetScore(), nLevel, GameBoard.GetLinesCleared());
	RenderManager.LoadImages();

	while (!bGameOver)
	{
		GameTick();

		if (gameWindow.pollEvent(gameEvent))
			ProcessGameEvent(gameWindow);

		RenderManager.UpdateCounters(GameBoard.GetScore(), nLevel, GameBoard.GetLinesCleared());

		DrawScreen(gameWindow);
	}

	SoundManager.PlayGameOver(bHasSFX);
	SoundManager.StopMusic();

	gameWindow.clear();
	GameOverScreen(gameWindow, GameBoard);
}

void Tetris::ProcessGameEvent(RenderWindow& gameWindow)
{
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

		case Keyboard::Down:	if (GameBoard.PushDown(bLineRemoved, Tetromino, bLevelHold) == false)
								{
									CheckDifficulty();
									SoundManager.PlayPlaceBlock(bHasSFX);

									if (bLineRemoved)
									{
										SoundManager.PlayLineRemoved(bHasSFX);
										bLineRemoved = false;
									}
								}
								break;

		case Keyboard::Up:		Tetromino.Rotate();
								SoundManager.PlayMove(bHasSFX);
								break;

		//Drop block
		case Keyboard::Space:	while (GameBoard.PushDown(bLineRemoved, Tetromino, bLevelHold) == true);
								CheckDifficulty();
								SoundManager.PlayPlaceBlock(bHasSFX);
								break;

		case Keyboard::C:		Tetromino.SwapBlocks(gameWindow, currentCell);
								break;

		//Exit game
		case Keyboard::Escape:	bGameOver = true;
								break;

		case Keyboard::P:		PauseMenu(gameWindow, gameEvent);
								break;
		}

	if (gameEvent.type == Event::MouseMoved)
		if (MenuButton.isMouseOver(gameWindow))
			MenuButton.SetButtonColor(Color::White);
		else
			MenuButton.SetButtonColor(Color::Red);

	if (gameEvent.type == Event::MouseButtonPressed)
		if (MenuButton.isMouseOver(gameWindow))
			bGameOver = true;
}

void Tetris::GameTick()
{
	static float prev = clock.getElapsedTime().asSeconds();
	if (clock.getElapsedTime().asSeconds() - prev >= fDifficulty)
	{
		clock.restart();
		prev = clock.getElapsedTime().asSeconds();
		if (GameBoard.PushDown(bLineRemoved, Tetromino, bLevelHold) == false)
		{
			SoundManager.PlayPlaceBlock(bHasSFX);
			CheckDifficulty();

			if (Tetromino.GetY() == 0 && GameBoard.PushDown(bLineRemoved, Tetromino, bLevelHold) == false)
				bGameOver = true;

			if (bLineRemoved)
			{
				SoundManager.PlayLineRemoved(bHasSFX);
				bLineRemoved = false;
			}
		}
	}
}

void Tetris::CheckDifficulty()
{
	if (GameBoard.GetLinesCleared() % 10 == 0 && GameBoard.GetLinesCleared() != 0 && !bLevelHold)
	{
		nLevel++;
		fDifficulty -= .05;
		SoundManager.AdjustTempo();
		SoundManager.PlayLevelUp(bHasSFX);
		bLevelHold = true;
	}
}

void Tetris::DrawScreen(RenderWindow& gameWindow)
{
	gameWindow.clear();
	GameBoard.DisplayField(gameWindow, Tetromino, currentCell);
	Tetromino.DrawBlock(gameWindow, currentCell, nextCell, heldCell);
	RenderManager.DrawBorder(gameWindow);
	RenderManager.DrawText(gameWindow);
	RenderManager.DrawSprites(gameWindow);
	MenuButton.DrawButton(gameWindow);
	gameWindow.display();
}

void Tetris::PauseMenu(RenderWindow& gameWindow, Event& gameEvent)
{
	RectangleShape Background(Vector2f(250, 500));
	Background.setFillColor(Color::Black);
	Background.setPosition(0, 0);
	gameWindow.draw(Background);

	Text pauseText;
	pauseText.setFont(font);
	pauseText.setPosition(75, 50);
	pauseText.setString("Paused");
	gameWindow.draw(pauseText);
	gameWindow.display();

	bPaused = true;
	while (bPaused)
	{
		if (gameWindow.pollEvent(gameEvent))
		{
			if (gameEvent.type == Event::KeyPressed)
				if (gameEvent.key.code == Keyboard::P)
					bPaused = false;
		}
	}
}

void Tetris::GameOverScreen(RenderWindow& gameWindow, Board& gameBoard)
{

	Text GameOverText;
	GameOverText.setFont(font);
	GameOverText.setFillColor(Color::Red);
	GameOverText.setPosition({ 220, 300 });
	GameOverText.setString("Game Over!!!");
	gameWindow.draw(GameOverText);

	Text ScoreText;
	ScoreText.setFont(font);
	ScoreText.setFillColor(Color::Red);
	ScoreText.setPosition({ 100, 350 });
	ScoreText.setString("Your final score was: ");

	Text NumericalScore;
	NumericalScore.setFont(font);
	NumericalScore.setFillColor(Color::White);
	NumericalScore.setPosition({ 450, 350 });
	NumericalScore.setString(to_string(gameBoard.GetScore()));

	Text PromptText;
	PromptText.setFont(font);
	PromptText.setFillColor(Color::Red);
	PromptText.setPosition({ 100, 400 });
	PromptText.setString("Enter your name: ");
	gameWindow.draw(PromptText);

	ScoreTextBox.SetFont(font);
	ScoreTextBox.SetPosition({ 375, 400 });
	ScoreTextBox.SetLimit(true, 3);

	bool bEnteredScore = false;

	while (!bEnteredScore)
	{
		if (gameWindow.pollEvent(gameEvent))
		{
			if (gameEvent.type == Event::TextEntered)
				ScoreTextBox.TypedOn(gameEvent);

			if (gameEvent.type == Event::KeyPressed)
				if (gameEvent.key.code == Keyboard::Enter)
					bEnteredScore = true;
		}

		gameWindow.clear();
		gameWindow.draw(GameOverText);
		gameWindow.draw(PromptText);
		gameWindow.draw(ScoreText);
		gameWindow.draw(NumericalScore);
		ScoreTextBox.DrawTo(gameWindow);
		gameWindow.display();
	}

	/*Writing score and name to score file*/
	if (outFile)
		cout << "Output file opened succesfully.\n";
	else
		cout << "Output file failed to open.\n";
	string strScoreEntry = ScoreTextBox.GetText() + "		" + to_string(gameBoard.GetScore()) + "\n";
	outFile << strScoreEntry;
}

Tetris::~Tetris()
{
	outFile.close();
}