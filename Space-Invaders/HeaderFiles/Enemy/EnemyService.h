#pragma once
//#include "../../HeaderFiles/Enemy/EnemyController.h"


namespace Enemy {

	class EnemyController;

	class EnemyService {

	private:
		EnemyController* enemy;
		void destroy();

	public:

		EnemyService();
		virtual ~EnemyService();

		
		void initialize();
		void update();
		void render();
		EnemyController* spawnEnemy();
		
	};
}