#ifndef SOUND_MANAGER_H
#define SOUND_MANAGER_H

#include <SFML/Audio.hpp>
#include <iostream>

class SoundManager
{
public:
	SoundManager();

	void PlayPlaceBlock(bool bHasSound);
	//Pre: Relevant sound file has been succesfully loaded from file.
	//Post: The placed block sound file is played.

	void PlayMove(bool bHasSound);
	//Pre: Relevant sound file has been succesfully loaded from file.
	//Post: The block placed sound file is played.

	void PlayLineRemoved(bool bHasSound);
	//Pre: Relevant sound file has been succesfully loaded from file.
	//Post: The line removed sound file is played.

	void PlayGameOver(bool bHasSound);
	//Pre: Relevant sound file has been succesfully loaded from file.
	//Post: The gameover sound file is played.

	void PlayLevelUp(bool bHasSound);
	//Pre: Relevant sound file has been succesfully loaded from file.
	//Post: The level up sound file is played.

	void PlayMusic(int nVolume);
	//Pre: Relevant sound file has been succesfully loaded from file.
	//Post: The music buffer has been initialized and loops for the game duration.

	void StopMusic();
	//Pre: Relevant sound file has been succesfully loaded from file.
	//Post: The music buffer stops playing

	void AdjustTempo();
	//Pre: Relevant sound file has been succesfully loaded from file.
	//Post: The tempo of the Tetris theme has increased along with the difficulty of the game.

private:

	/*Sound Effect Buffers*/
	sf::SoundBuffer sb_PlaceBlock;
	sf::SoundBuffer sb_Move;
	sf::SoundBuffer sb_LineRemoved;
	sf::SoundBuffer sb_GameOver;
	sf::SoundBuffer sb_LevelUp;

	/*Music object and identifier*/
	sf::Music m_Theme;
	float fPitch = 1;

	/*Sound Effect Objects*/
	sf::Sound s_PlaceBlock;
	sf::Sound s_Move;
	sf::Sound s_LineRemoved;
	sf::Sound s_GameOver;
	sf::Sound s_LevelUp;
};

#endif SOUND_MANAGER_H