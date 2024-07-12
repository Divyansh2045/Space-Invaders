#include "../HeaderFiles/PlayerService.h"
#include "../HeaderFiles/ServiceLocator.h"


PlayerService::PlayerService()
{
	gameWindow = nullptr;
}
PlayerService::~PlayerService() = default;

void PlayerService::initialize() {

	gameWindow = ServiceLocator::getInstance()->GetGraphicService()->GetGameWindow();
	initializePlayerSprite();
}
void PlayerService::update() {
	processPlayerInput();

	playerSprite.setPosition(getPlayerPosition());
}
void PlayerService::render() {
	gameWindow->draw(playerSprite);
}

void PlayerService::processPlayerInput()
{
	EventService* eventservice = ServiceLocator::getInstance()->GetEventService();

	if (eventservice->isKeyboardEvent())
	{
		if (eventservice->pressedLeftKey())
		{
			moveLeft();
		}
		if (eventservice->pressedRightKey())
		{
			moveRight();
		}
	}
}


 void PlayerService::initializePlayerSprite()
{

	if (playerTexture.loadFromFile(player_texture_path))
	{
		playerSprite.setTexture(playerTexture);
	}
}

 void PlayerService::moveLeft() {
	position.x -= movementSpeed * ServiceLocator::getInstance()->GetTimeService()->getDeltaTime();
 }
 void PlayerService::moveRight() {
	 position.x += movementSpeed * ServiceLocator::getInstance()->GetTimeService()->getDeltaTime();
 }

void PlayerService::move(float offsetX) {
	position.x += offsetX * ServiceLocator::getInstance()->GetTimeService()->getDeltaTime();
}

//helper functions
sf::Vector2f PlayerService::getPlayerPosition() { return position; }
int PlayerService::getMoveSpeed() { return movementSpeed; }
