#include "../HeaderFiles/PlayerService.h"
#include "../../HeaderFiles/Player/PlayerController.h"



PlayerService::PlayerService()
{
	playerController = new PlayerController();
}

PlayerService::~PlayerService() 
{
	delete (playerController) ;
}

void PlayerService::initialize() 
{
	playerController->initialize();
}

void PlayerService::update()
{
	playerController->update();
}

void PlayerService::render() 
{
	playerController->render();
}

