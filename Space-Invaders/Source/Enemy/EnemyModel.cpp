#include "../../HeaderFiles/Enemy/EnemyModel.h"
#include <iostream>
using namespace std;

namespace Enemy
{

	EnemyModel::EnemyModel() {

	}

	EnemyModel::~EnemyModel() {

	}

	void EnemyModel::initialize() 
	{
		enemyPosition = referencePosition;
	}


	void EnemyModel::setEnemyPosition(sf::Vector2f position)
	{
		enemyPosition = position;
	}

	sf::Vector2f EnemyModel::getEnemyPosition() {
		return enemyPosition;
	}

	void EnemyModel::setReferencePosition(sf::Vector2f position) {
		referencePosition = position;
	}

	sf::Vector2f EnemyModel::getReferencePosition() {
		return referencePosition;
	}
}