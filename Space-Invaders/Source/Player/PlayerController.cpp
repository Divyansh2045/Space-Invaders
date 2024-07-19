#include <iostream>
#include "../../HeaderFiles/Player/PlayerController.h"
#include "../../HeaderFiles/Global/ServiceLocator.h"
#include "../../HeaderFiles/Event/EventService.h"
#include "../../HeaderFiles/Player/PlayerModel.h"
#include"../../HeaderFiles/Player/PlayerView.h"
#include <algorithm>

namespace Player {

	using namespace Player;

	PlayerController::PlayerController() {
		playerView = new Player::PlayerView; 
		playerModel = new Player::PlayerModel; 
	}
	PlayerController::~PlayerController() {
		delete (playerView);
		delete (playerModel);
	}

	void PlayerController::initialize() {

		playerModel->initialize();
		playerView->initialize(this);
	}

	void PlayerController::update() {

		playerView->update();
		ProcessPlayerInput();

	}

	void PlayerController::render() {
		playerView->render();

	}
	sf::Vector2f PlayerController::getPlayerPosition() {
		return playerModel->getPlayerPosition();
	}


	void PlayerController::ProcessPlayerInput() {

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			moveLeft();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			moveRight();
		}

	}

	void PlayerController::moveLeft() {

		sf::Vector2f currentPosition = playerModel->getPlayerPosition();
		currentPosition.x -= playerModel->playerMovementSpeed * Global::ServiceLocator::getInstance()->GetTimeService()->getDeltaTime();

		currentPosition.x = std::max(currentPosition.x, playerModel->leftScreenSide.x);
		playerModel->setPlayerPosition(currentPosition);


	}

	void PlayerController::moveRight() {
		sf::Vector2f currentPosition = playerModel->getPlayerPosition();
		currentPosition.x += playerModel->playerMovementSpeed * Global::ServiceLocator::getInstance()->GetTimeService()->getDeltaTime();

		currentPosition.x = std::min(currentPosition.x, playerModel->rightScreenSide.x);
		playerModel->setPlayerPosition(currentPosition);
	}
}





