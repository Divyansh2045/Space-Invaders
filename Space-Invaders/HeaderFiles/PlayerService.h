#pragma once

#include <SFML/Graphics.hpp>


class PlayerService
{

private:
	int health = 3;
	float movementSpeed = 5.0f;
	int playerScore = 0;
	sf::Vector2f position = sf::Vector2f(200.0f, 100.0f);
	
	const sf::String player_texture_path = "assets/textures/player_ship.png";
	
	sf::Texture playerTexture;
	sf::Sprite playerSprite;
	sf::RenderWindow* gameWindow;

	void initializePlayerSprite();

	void processPlayerInput();



public:

	PlayerService();
	~PlayerService();

	void update();
	void render(); 
	void initialize();

	void move(float offsetX);
	void moveLeft();
	void moveRight();
	int getMoveSpeed();
	sf::Vector2f getPlayerPosition();
	//int GetScore() const;
	//void SetScore(int newScore);





};