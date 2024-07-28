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

		virtual void move() = 0;
		void moveRight();
		void moveLeft();
		void moveDown();

	public:
		EnemyController();
	    virtual ~EnemyController();

		//Lifecycle

		virtual void initialize();
		void update();
		void render();

		sf::Vector2f getEnemyPosition();

	
	};

}
