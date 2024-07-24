#pragma once
//#include "../../HeaderFiles/Enemy/EnemyController.h"
#include <vector>


namespace Enemy {

	class EnemyController;

	class EnemyService {

	private:
		std::vector<EnemyController*> enemyList;
		void destroy();

		const float enemySpawnDelay = 3.0f;
		float spawnTimer;
		void updateSpawnTimer();
		void processEnemySpawn();
	public:

		EnemyService();
		virtual ~EnemyService();

		
		void initialize();
		void update();
		void render();
		
		void spawnEnemy();
		
	};
}