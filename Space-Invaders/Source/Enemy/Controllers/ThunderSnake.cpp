#include "../../HeaderFiles/Enemy/Controllers/ThunderSnake.h"
#include "../../HeaderFiles/Enemy/EnemyModel.h"
#include "../../HeaderFiles/Global/ServiceLocator.h"
#include "../../HeaderFiles/Enemy/Controllers/EnemyConfig.h"

namespace Enemy
{
	using namespace Global;
	namespace Controllers
	{
		ThunderSnake::ThunderSnake(EnemyType setType) : EnemyController(setType)
		{

		}

		ThunderSnake::~ThunderSnake()
		{

		}

		void ThunderSnake::moveRightDiagonal()
		{
			sf::Vector2f currentPosition = enemyModel->getEnemyPosition();
			currentPosition.x += diagonalMovementSpeed * ServiceLocator::getInstance()->GetTimeService()->getDeltaTime();
			currentPosition.y +=  diagonalMovementSpeed * ServiceLocator::getInstance()->GetTimeService()->getDeltaTime();

			if (currentPosition.x >= enemyModel->rightScreenSide.x ) //|| currentPosition.y >= enemyModel->bottomScreenSide.y)
			{
				enemyModel->setMovementDirection(MovementDirection::LEFT);
				enemyModel->setReferencePosition(currentPosition);
			}
			else
			{
				enemyModel->setEnemyPosition(currentPosition);
			}

		}
		void ThunderSnake::moveLeftDiagonal()
		{
			sf::Vector2f currentPosition = enemyModel->getEnemyPosition();
			currentPosition.x -= diagonalMovementSpeed * ServiceLocator::getInstance()->GetTimeService()->getDeltaTime();
			currentPosition.y += diagonalMovementSpeed * ServiceLocator::getInstance()->GetTimeService()->getDeltaTime();

			if (currentPosition.x <= enemyModel->leftScreenSide.x )// || currentPosition.y >= enemyModel->bottomScreenSide.y//)
			{
				enemyModel->setMovementDirection(MovementDirection::RIGHT);
				enemyModel->setReferencePosition(currentPosition);
			}
			else
			{
				enemyModel->setEnemyPosition(currentPosition);
			}

		}
		void ThunderSnake::initialize()
	    {
			EnemyController::initialize();
		}

		void ThunderSnake::move()
		{
			switch (enemyModel->getMovementDirection())
			{
			case Enemy::MovementDirection::RIGHT:
				moveRightDiagonal();
				break;
			case Enemy::MovementDirection::LEFT:
				moveLeftDiagonal();
				break;
			}
		}


	}
}
