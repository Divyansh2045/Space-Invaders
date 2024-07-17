#pragma once

#include <SFML/Graphics.hpp>

class PlayerController;


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