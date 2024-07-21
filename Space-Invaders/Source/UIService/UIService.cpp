#include <iostream>
#include "../../HeaderFiles/UIService/UIService.h"
//#include "../../HeaderFiles/UIService/MainMenuUIController/MainMenuUIController.h"
#include "../../HeaderFiles/Main/GameService.h"


namespace UI
{
	using namespace MainMenu;
	using namespace Main;

	UIService::UIService()
	{
		mainMenuUIController = nullptr;
		createUIControllers();
	}

	UIService::~UIService() 
	{
		destroy();
	}
	void UIService::createUIControllers()
	{
		mainMenuUIController = new MainMenuUIController();
	}
	void UIService::initializeControllers()
	{
		mainMenuUIController->initialize();
	}

	void UIService::update() {
		
	}

	void UIService::render()
	{
		
	}

	void UIService::initialize()
	{
		createUIControllers();
	}

	void UIService::destroy()
	{
		delete (mainMenuUIController);
	}
}