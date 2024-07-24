#pragma once
//#include "../../HeaderFiles/Enemy/EnemyModel.h"
#include <SFML/Graphics.hpp>

namespace Enemy {

	class EnemyModel;
	class EnemyView;

	class EnemyController 
	{
	private:

		EnemyView* enemyView;
		EnemyModel* enemyModel;

	public:
		EnemyController();
		~EnemyController();

		//Lifecycle

		void initialize();
		void update();
		void render();

		sf::Vector2f getEnemyPosition();

		void move();
		void moveRight();
		void moveLeft();
		void moveDown();
	};

}
