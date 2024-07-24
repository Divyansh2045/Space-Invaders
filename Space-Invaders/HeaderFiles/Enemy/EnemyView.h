#pragma once
#include <SFML/Graphics.hpp>


namespace Enemy {
	class EnemyController;
	class EnemyView
	{
	private:

		const sf::String enemy_texture_path = "assets/textures/subzero.png";
		const float enemySpriteWidth = 60.f;
		const float enemySpriteHeight = 60.f;

		sf::RenderWindow* gameWindow;
		sf::Texture enemyTexture;
		sf::Sprite enemySprite;

		EnemyController* enemyController;

		void initializeEnemySprites();
		void scaleEnemySprites();


	public:
		EnemyView();
		~EnemyView();

		//Lifecycle
		
		void initialize(EnemyController * controller);
		void update();
		void render();

	};

}

