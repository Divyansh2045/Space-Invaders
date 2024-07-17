#pragma once
#include "../../HeaderFiles/Main/GameService.h"
#include <iostream>
#include "../../HeaderFiles/Graphic/GraphicService.h"
#include "../../HeaderFiles/Event/EventService.h"
#include "../../HeaderFiles/Player/PlayerService.h"
#include "../../HeaderFiles/Time/TimeService.h"



class ServiceLocator {

private:
	GraphicService* graphic_service{ nullptr };
	static ServiceLocator* instance;
	EventService* event_service{ nullptr };
	PlayerService* player_service{ nullptr };
	TimeService* time_service{ nullptr };

	ServiceLocator();

	~ServiceLocator();

	void createServices(); 			// Creates instances of all services.
	void clearAllServices(); 		//	Deletes and deallocates memory for all services.


public:
	static ServiceLocator* getInstance();  // Provides a method to access the unique ServiceLocator instance (object)
	void update();
	void initialize();
	void render();

	// Methods to Get Specific Services: 
	GraphicService* GetGraphicService();
	EventService* GetEventService();
	PlayerService* GetPlayerService();
	TimeService* GetTimeService();

};


