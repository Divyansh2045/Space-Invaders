#pragma once
#include <SFML/Graphics.hpp>

namespace Enemy {

	class EnemyModel
	{
	private:
		sf::Vector2f referencePosition = (sf::Vector2f(50.0f, 50.f));
		sf::Vector2f enemyPosition;

	public:
		EnemyModel();
		~EnemyModel();

		//Lifecycle

		void initialize();
		//void update();
		//void render();

		//setters and getters
		sf::Vector2f getReferencePosition();
		void setReferencePosition(sf::Vector2f position);

		sf::Vector2f getEnemyPosition();
		void setEnemyPosition(sf::Vector2f position);

	};

}
