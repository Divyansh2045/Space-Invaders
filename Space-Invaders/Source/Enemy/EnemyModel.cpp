#include "../../HeaderFiles/Enemy/Controllers/EnemyConfig.h"
#include "../../HeaderFiles/Enemy/EnemyModel.h"
#include <iostream>
using namespace std;

namespace Enemy
{

	EnemyModel::EnemyModel(EnemyType type) {
		enemyType = type;
	}

	EnemyModel::~EnemyModel() {

	}

	void EnemyModel::initialize()
	{
		movementDirection = MovementDirection::RIGHT;
		enemyPosition = referencePosition;
		enemyState = EnemyState::PATROLLING;
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

	MovementDirection EnemyModel::getMovementDirection() {
		return movementDirection;
	}

	void EnemyModel::setMovementDirection(MovementDirection direction)
	{
		movementDirection = direction;
	}

	EnemyState EnemyModel::getEnemyState()
	{
		return enemyState;
	}

	void EnemyModel::setEnemyState(EnemyState state)
	{
		enemyState = state;
	}

	EnemyType EnemyModel::getEnemyType()
	{
		return enemyType;
	}

	void EnemyModel::setEnemyType(EnemyType setType)
	{
		enemyType = setType;
	}


	
}