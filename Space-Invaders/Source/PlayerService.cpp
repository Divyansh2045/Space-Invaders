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

	player_sprite.setPosition(getPlayerPosition());
}
void PlayerService::render() {
	gameWindow->draw(player_sprite);
}

void PlayerService::processPlayerInput()
{
	EventService* eventservice = ServiceLocator::getInstance()->GetEventService();

	if (eventservice->isKeyboardEvent())
	{
		if (eventservice->pressedLeftKey())
		{
			move(-1.0f * getMoveSpeed());
		}
		if (eventservice->pressedRightKey())
		{
			move(1.0f * getMoveSpeed());
		}
	}
}


 void PlayerService::initializePlayerSprite()
{

	if (player_texture.loadFromFile(player_texture_path))
	{
		player_sprite.setTexture(player_texture);
	}
}

void PlayerService::move(float offsetX) {
	position.x += offsetX;
}

//helper functions
sf::Vector2f PlayerService::getPlayerPosition() { return position; }
int PlayerService::getMoveSpeed() { return movementSpeed; }
