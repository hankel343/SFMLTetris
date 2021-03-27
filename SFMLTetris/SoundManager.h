#ifndef SOUND_MANAGER_H
#define SOUND_MANAGER_H

#include <SFML/Audio.hpp>
#include <iostream>

class SoundManager
{
public:
	SoundManager();

	void PlayPlaceBlock();
	void PlayMove();
	void PlayLineRemoved();
	void PlayGameOver();
	void PlayLevelUp();
	void PlayMusic();
	void StopMusic();
	void AdjustTempo();

private:
	sf::SoundBuffer sb_PlaceBlock;
	sf::SoundBuffer sb_Move;
	sf::SoundBuffer sb_LineRemoved;
	sf::SoundBuffer sb_GameOver;
	sf::SoundBuffer sb_LevelUp;
	sf::Music m_Theme;
	float fPitch = 1;

	sf::Sound s_PlaceBlock;
	sf::Sound s_Move;
	sf::Sound s_LineRemoved;
	sf::Sound s_GameOver;
	sf::Sound s_LevelUp;


};

#endif SOUND_MANAGER_H