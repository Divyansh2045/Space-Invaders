#include <iostream>
#include "../../HeaderFiles/Player/PlayerController.h"
#include "../../HeaderFiles/ServiceLocator.h"
#include "../../HeaderFiles/EventService.h"
#include <algorithm>

PlayerController::PlayerController() {
	playerView = new PlayerView;
	playerModel = new PlayerModel;

}
PlayerController::~PlayerController() {
	delete playerView;
	delete playerModel;
}

void PlayerController::moveLeft() {

	sf::Vector2f currentPosition = playerModel->getPlayerPosition();
	currentPosition.x -= playerModel->playerMovementSpeed* ServiceLocator::getInstance()->GetTimeService()->getDeltaTime();
	currentPosition.x = std::max(currentPosition.x, playerModel->leftScreenSide.x);
	playerModel->setPlayerPosition(currentPosition);

}

void PlayerController::moveRight()  {
	sf::Vector2f currentPosition = playerModel->getPlayerPosition();
	currentPosition.x += playerModel->playerMovementSpeed* ServiceLocator::getInstance()->GetTimeService()->getDeltaTime();
	currentPosition.x = std::min(currentPosition.x, playerModel->rightScreenSide.x);
	playerModel->setPlayerPosition(currentPosition);
}

void PlayerController::ProcessPlayerInput(){

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		moveLeft();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		moveRight();
	}



}
void PlayerController::initialize() {

	playerModel->initialize();
	playerView->initialize(this);


}

void PlayerController::update() {

	playerView->update();


}

void PlayerController::render() {
	playerView->render();

}

sf::Vector2f getPlayerPosition() {
	return playerModel->getPlayerPosition();
}

