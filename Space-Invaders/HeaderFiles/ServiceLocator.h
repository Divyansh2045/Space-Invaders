#pragma once
#include "../HeaderFiles/GameService.h"
#include <iostream>
#include "../HeaderFiles/GraphicService.h"



class ServiceLocator {

private:
	GraphicService* graphic_service{ nullptr };
	static ServiceLocator* instance;

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

};


