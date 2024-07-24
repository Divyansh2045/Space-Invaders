#include "../../HeaderFiles/Enemy/EnemyController.h"
#include "../../HeaderFiles/Enemy/EnemyModel.h"
#include "../../HeaderFiles/Enemy/EnemyView.h"
#include "../../HeaderFiles/Global/ServiceLocator.h"
#include <iostream>
using namespace std;

namespace Enemy
{
	using namespace Global;

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
		enemyView->update();
	}
	void EnemyController::render() {
		enemyView->render();
	}

	sf::Vector2f EnemyController::getEnemyPosition() {
		return enemyModel->getEnemyPosition();
	}

}