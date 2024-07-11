#pragma once

#include <SFML/Graphics.hpp>


class PlayerService
{

private:
	int health = 3;
	int movementSpeed = 50;
	int playerScore = 0;
	sf::Vector2f position = sf::Vector2f(200.0f, 100.0f);
	
	const sf::String player_texture_path = "assets/textures/player_ship.png";
	
	sf::Texture player_texture;
	sf::Sprite player_sprite;
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
	int getMoveSpeed();
	sf::Vector2f getPlayerPosition();
	//int GetScore() const;
	//void SetScore(int newScore);





};