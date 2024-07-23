#include "../../HeaderFiles/Enemy/EnemyView.h"
#include "../../HeaderFiles/Graphic/GraphicService.h"
#include "../../HeaderFiles/Enemy/EnemyController.h"
#include "../../HeaderFiles/Global/ServiceLocator.h"

#include <iostream>
using namespace std;

namespace Enemy
{
	using namespace Global;
	using namespace Graphic;

	EnemyView::EnemyView() 
	{

	}

	EnemyView::~EnemyView() {

	}

	void EnemyView::initialize(EnemyController * controller) 
	{
		enemyController = controller;
		gameWindow = ServiceLocator::getInstance()->GetGraphicService()->GetGameWindow();
		initializeEnemySprites();
	}

	void EnemyView::initializeEnemySprites() 
	{
		if (enemyTexture.loadFromFile(enemy_texture_path))
		{
			enemySprite.setTexture(enemyTexture);
			scaleEnemySprites();
		}
	}

	void EnemyView::scaleEnemySprites()
	{
		enemySprite.setScale(
			static_cast<float>(enemySpriteWidth) / enemySprite.getTexture()->getSize().x,
			static_cast<float>(enemySpriteHeight) / enemySprite.getTexture()->getSize().y);
	}
	void EnemyView::update() {
		enemySprite.setPosition(enemyController->getEnemyPosition());
	}

	void EnemyView::render() {
		gameWindow->draw(enemySprite);
	}


}