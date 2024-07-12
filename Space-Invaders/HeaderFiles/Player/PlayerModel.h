#pragma once
#include <SFML/Graphics.hpp>
//TO maintain and store data of the player

class PlayerModel {

private:
	
	const sf::Vector2f initialPlayerPosition = sf::Vector2f(500.0f, 500.0f);
	sf::Vector2f playerPosition;

	bool isPlayerAlive;
	int playerScore;

public:
	
	const float playerMovementSpeed = 200.0f;
	PlayerModel();
	~PlayerModel();
	void Reset();

	//getters and setters
	sf::Vector2f getPlayerPosition();
	void setPlayerPosition(sf::Vector2f position);
	bool getPlayerAlive();
	void setPlayerAlive(bool alive);

	void initialize();
//	void destroy();

	const sf::Vector2f leftScreenSide = sf::Vector2f(50.0f, 0.0f);
	const sf::Vector2f rightScreenSide = sf::Vector2f(700.0f, 0.0f);



};
