#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

class EventService {
	
private:
	sf::Event gameEvent;
	sf::RenderWindow* gameWindow;

	bool isGameWindowOpen();
	bool gameWindowWasClosed();
	bool hasQuitGame();

public:
   EventService();
   ~EventService();

   void initialize();
   void update();
   void processEvents();
   bool pressedEscapeKey();
   bool isKeyboardEvent();

};