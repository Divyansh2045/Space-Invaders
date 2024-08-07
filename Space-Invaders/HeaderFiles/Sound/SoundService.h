#pragma once

#include "SFML/Audio.hpp"
namespace Sound
{
	class SoundService
	{
		enum class SoundType
		{
			BUTTONCLICK
		};

	private:

		const int backgroundMusicVolume = 30;
		sf::Music backgroundMusic;
		sf::Sound soundEffects;
		sf::SoundBuffer buttonClick;

		void loadBackgroundMusic();
		void loadSoundEffects();


	public:
		SoundService();
		~SoundService();

		void playSound(SoundType soundType);
		void playBackgroundMusic();
		void initialize();


		

	};
}
