#include <iostream>
using namespace std;
#include "../HeaderFiles/GameService.h"


	void GameService::initialize() // initialization of game 
	{
		service_locator->initialize();
		initializeVariables();//INitialize variables
		cout << "initialize" << endl;

	}
	void GameService::destroy() // Destroys game objects when destroyed 
	{
		delete(gameWindow);
	}
	void GameService::initializeVariables() {
		gameWindow = service_locator->GetGraphicService()->GetGameWindow(); //set game window (it was null before this)

	}
	GameService::GameService() // Default Constructor 
	{
		service_locator = nullptr; 
		gameWindow = nullptr; // Initializes game window pointer to null
		//gameloop
	}
	GameService::~GameService() // Deconstructor
	{
		// end of game when player exits
		destroy();
	}

	void GameService::update() //Updates the game objects each frame 
	{
		service_locator->GetEventService()->processEvents();
		service_locator->update();
		cout << "update" << endl;
	}
	void GameService::ignite(){ // Initiates the game 
		service_locator = ServiceLocator::getInstance();
		initialize();
		cout << "ignite" << endl;
	
	}
	void GameService::render() { //Renders each object each frame
		gameWindow->clear(service_locator->GetGraphicService()->GetWindowColor());
		service_locator->render();
		gameWindow->display();
		cout << "render" << endl;

	}
	bool GameService::isRunning() // Keeps on checking if the game is running
	{

		return gameWindow ->isOpen();
	}


	

	
