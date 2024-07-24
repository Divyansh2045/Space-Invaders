#include "../../HeaderFiles/Enemy/EnemyService.h"
#include "../../HeaderFiles/Enemy/EnemyController.h"
#include "../../HeaderFiles/Global/ServiceLocator.h"
#include "../../HeaderFiles/Time/TimeService.h"

namespace Enemy {
	using namespace Global;
	using namespace Time;


	EnemyService::EnemyService()
	{
		
	}

	EnemyService::~EnemyService() {
		destroy();
	}

	void EnemyService::initialize() {
		spawnTimer = enemySpawnDelay;
		//spawnEnemy();
	}

	void EnemyService::update() {
		updateSpawnTimer();
		processEnemySpawn();

		for (int i = 0; i < enemyList.size(); i++)
		{
			enemyList[i]->update();
		}
	}

	void EnemyService::render() {
		for (int i = 0; i < enemyList.size(); i++)
		{
			enemyList[i]->render();
		}
	}

	void EnemyService::destroy() {
		for (int i = 0; i < enemyList.size(); i++)
		{
			delete enemyList[i];
		}
	}

    void EnemyService::spawnEnemy() {

		EnemyController* enemyController = new EnemyController;
		enemyController->initialize();

		enemyList.push_back(enemyController);
	
	}
	void EnemyService::updateSpawnTimer() {
		spawnTimer += ServiceLocator::getInstance()->GetTimeService()->getDeltaTime();
	}

	// Inside the method to process enemy spawn, we will spawn an enemy if the spawn timer is more than the the interval. Then  we will set time timer back to 0.
	void EnemyService::processEnemySpawn() 
	{
		if (spawnTimer >= enemySpawnDelay)
		{
			spawnEnemy();
			spawnTimer = 0.0f;
		}
	}
}