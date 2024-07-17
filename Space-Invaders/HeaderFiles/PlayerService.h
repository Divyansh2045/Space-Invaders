#pragma once

#include <SFML/Graphics.hpp>
#include "../../HeaderFiles/Player/PlayerController.h"


class PlayerService
{

private:

	PlayerController* playerController;



public:

	PlayerService();
	~PlayerService();

	void update();
	void render(); 
	void initialize();







};