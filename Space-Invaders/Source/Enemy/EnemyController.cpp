#include "../../HeaderFiles/Enemy/EnemyController.h"
#include "../../HeaderFiles/Enemy/EnemyModel.h"
#include "../../HeaderFiles/Enemy/EnemyView.h"
#include "../../HeaderFiles/Global/ServiceLocator.h"
#include "../../HeaderFiles/Event/EventService.h"
#include <iostream>
using namespace std;

namespace Enemy
{
	using namespace Global;
	using namespace Time;
	using namespace Event;

	EnemyController::EnemyController() {
		enemyModel = new EnemyModel();
		enemyView = new EnemyView();
	}

	EnemyController::~EnemyController() {
		delete (enemyView);
		delete (enemyModel);
	}

	void EnemyController::initialize() {
		enemyModel->initialize();
		enemyView->initialize(this);
	}

	void EnemyController::update() {
		move();
		enemyView->update();
	}
	void EnemyController::render() {
		enemyView->render();
	}

	sf::Vector2f EnemyController::getEnemyPosition() {
		return enemyModel->getEnemyPosition();
	}

	void EnemyController::move() {

		switch (enemyModel->getMovementDirection())
		{
		case::Enemy::MovementDirection::RIGHT:
		
			moveRight();
			break;

		case::Enemy::MovementDirection::LEFT:
		
           moveLeft();
		   break;

		case::Enemy::MovementDirection::DOWN:
		
			moveDown();
			break;
		
		}
	}

	void EnemyController::moveRight()
	{
		sf::Vector2f currentPosition = enemyModel->getEnemyPosition();
		currentPosition.x += enemyModel->enemyMovementSpeed * ServiceLocator::getInstance()->GetTimeService()->getDeltaTime();

		if (currentPosition.x >= enemyModel->rightScreenSide.x)
		{
			enemyModel->setMovementDirection(MovementDirection::DOWN);
			enemyModel->setReferencePosition(currentPosition);
		}
		else (enemyModel->setEnemyPosition(currentPosition));
	}

	void EnemyController::moveLeft()
	{
		sf::Vector2f currentPosition = enemyModel->getEnemyPosition();
		currentPosition.x -= enemyModel->enemyMovementSpeed * ServiceLocator::getInstance()->GetTimeService()->getDeltaTime();

		if (currentPosition.x <= enemyModel->leftScreenSide.x)
		{
			enemyModel->setMovementDirection(MovementDirection::DOWN);
			enemyModel->setReferencePosition(currentPosition);
		}
		else (enemyModel->setEnemyPosition(currentPosition));
	}

	void EnemyController::moveDown()
	{
		sf::Vector2f currentPosition = enemyModel->getEnemyPosition();
		currentPosition.y += enemyModel->enemyVerticalDistance * ServiceLocator::getInstance()->GetTimeService()->getDeltaTime();

		if (currentPosition.y >= enemyModel->getReferencePosition().y + enemyModel->enemyVerticalDistance)
		{
			if (enemyModel->getReferencePosition().x <= enemyModel->leftScreenSide.x)
			{
				enemyModel->setMovementDirection(MovementDirection::RIGHT);
			}
			else (enemyModel->setMovementDirection(MovementDirection::LEFT));
		}
				else (enemyModel->setEnemyPosition(currentPosition));

		

	}
}