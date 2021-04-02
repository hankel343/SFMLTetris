#include "SoundManager.h"

SoundManager::SoundManager()
{
	if (!sb_PlaceBlock.loadFromFile("piece_placed.ogg"))
		std::cout << "ERROR: Assets/Sounds/piece_placed.ogg failed to load" << std::endl;
	else
		s_PlaceBlock.setBuffer(sb_PlaceBlock);

	if (!sb_Move.loadFromFile("move.ogg"))
		std::cout << "ERROR: Assets/Sounds/move.ogg failed to load" << std::endl;
	else
		s_Move.setBuffer(sb_Move);

	if (!sb_LineRemoved.loadFromFile("line_removed.ogg"))
		std::cout << "ERROR: Assets/Sounds/line_removed.ogg failed to load" << std::endl;
	else
		s_LineRemoved.setBuffer(sb_LineRemoved);

	if (!sb_GameOver.loadFromFile("gameOver.ogg"))
		std::cout << "ERROR: Assets/Sounds/gameOver.ogg failed to load" << std::endl;
	else
		s_GameOver.setBuffer(sb_GameOver);

	if (!sb_LevelUp.loadFromFile("LevelUp.ogg"))
		std::cout << "ERROR: Assets/Sounds/LevelUp.ogg failed to load" << std::endl;
	else
		s_LevelUp.setBuffer(sb_LevelUp);

	if (!m_Theme.openFromFile("Tetris.ogg"))
		std::cout << "ERROR: Assets/Sounds/Tetris.ogg failed to load" << std::endl;
	else
	{
		m_Theme.setLoop(true);
		m_Theme.setVolume(100);
		m_Theme.setPitch(fPitch);
	}
}

void SoundManager::PlayPlaceBlock(bool bHasSound)
{
	if (bHasSound)
		s_PlaceBlock.play();
}

void SoundManager::PlayMove(bool bHasSound)
{
	if (bHasSound)
		s_Move.play();
}

void SoundManager::PlayLineRemoved(bool bHasSound)
{
	if (bHasSound)
		s_LineRemoved.play();
}

void SoundManager::PlayGameOver(bool bHasSound)
{
	if (bHasSound)
		s_GameOver.play();
}

void SoundManager::PlayLevelUp(bool bHasSound)
{
	if (bHasSound)
		s_LevelUp.play();
}

void SoundManager::PlayMusic(int nVolume)
{
	m_Theme.setVolume(nVolume);
	m_Theme.play();
}

void SoundManager::StopMusic()
{
	m_Theme.stop();
}

void SoundManager::AdjustTempo()
{
	fPitch = fPitch + 0.01;
	m_Theme.setPitch(fPitch);
}