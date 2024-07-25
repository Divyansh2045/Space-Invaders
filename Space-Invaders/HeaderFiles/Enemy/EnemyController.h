#pragma once
#include <SFML/Graphics.hpp>

namespace Enemy {

	class EnemyModel;
	class EnemyView;

	class EnemyController 
	{
	private:

		EnemyView* enemyView;
		EnemyModel* enemyModel;

		void move();
		void moveRight();
		void moveLeft();
		void moveDown();

	public:
		EnemyController();
		~EnemyController();

		//Lifecycle

		void initialize();
		void update();
		void render();

		sf::Vector2f getEnemyPosition();

	
	};

}
