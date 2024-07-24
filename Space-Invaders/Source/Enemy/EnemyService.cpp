#include "../../HeaderFiles/Enemy/EnemyService.h"
#include "../../HeaderFiles/Enemy/EnemyController.h"
#include "../../HeaderFiles/Global/ServiceLocator.h"

namespace Enemy {
	using namespace Global;


	EnemyService::EnemyService()
	{
		enemy = nullptr;
	}

	EnemyService::~EnemyService() {
		destroy();
	}

	void EnemyService::initialize() {
		spawnEnemy();
	}

	void EnemyService::update() {
		enemy->update();
	}

	void EnemyService::render() {
		enemy->render();
	}

	void EnemyService::destroy() {
		delete(enemy);
	}

	EnemyController * EnemyService::spawnEnemy() {

		enemy = new EnemyController();
		enemy->initialize();

		return enemy;
	}
}