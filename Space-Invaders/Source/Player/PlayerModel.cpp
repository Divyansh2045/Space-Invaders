#include <iostream>
using namespace std;
#include "../../HeaderFiles/Player/PlayerModel.h"

PlayerModel::PlayerModel(){

}
PlayerModel::~PlayerModel() {

}

void PlayerModel::Reset() {
	isPlayerAlive = true;
	playerPosition = initialPlayerPosition;
	playerScore = 0;

}
void PlayerModel::initialize()
{       
	Reset();
}
sf::Vector2f PlayerModel::getPlayerPosition() 
{
	return playerPosition;

}
void PlayerModel::setPlayerPosition(sf::Vector2f position) {
	playerPosition = position;
}
bool PlayerModel::getPlayerAlive() {
	return isPlayerAlive;
}

void PlayerModel::setPlayerAlive(bool alive) {
	isPlayerAlive = true;
}
