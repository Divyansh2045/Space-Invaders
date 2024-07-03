
#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>

int main (){

    GameService* gameservice = new GameService();
    gameservice->ignite();

    while (gameservice->isRunning())
    {
<<<<<<< Updated upstream
        return playerScore;
    }
    void setScore(int newScore) {
        playerScore = newScore;
    }
    int getMoveSpeed()
    {
        return movementSpeed;
    }
    void setMoveSpeed(int newMoveSpeed)
    {
        movementSpeed = newMoveSpeed;
    }

    void takeDamage() {

        cout << "Player took damage" << endl;
    };

    void move(float offsetX) {
        position.x += offsetX;
    };

    void shootBullets() {
        cout << "Player is shooting bullets" << endl;
    };

    sf::Vector2f getPosition()
    {
        return position;
    }


   
};  */

int main()
{
   
        gameservice->update();
        gameservice->render();
    }


>>>>>>> Stashed changes
    return 0;
}