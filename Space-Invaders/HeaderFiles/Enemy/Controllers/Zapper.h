#pragma once
#include "../../HeaderFiles/Enemy/EnemyController.h"
namespace Enemy
{
	namespace Controllers
	{

		class Zapper : public EnemyController
		{
		private:

			float verticalTravelDistance = 10.0f;
			void moveLeft();
			void moveRight();
			void moveDown();
			void move() override;
		public:
			Zapper();
			~Zapper() override;

			void initialize() override;

		
		};



	}

		
}