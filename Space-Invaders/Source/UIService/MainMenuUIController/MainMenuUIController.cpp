#include "../../HeaderFiles/UIService/MainMenuUIController/MainMenuUIController.h"
#include "../../HeaderFiles/Main/GameService.h"
#include "../../HeaderFiles/Graphic/GraphicService.h"
#include "../../HeaderFiles/Global/ServiceLocator.h"

namespace UI {

	namespace MainMenu {

		using namespace Global;
		using namespace Main;
		using namespace Graphic;
		using namespace Event;

		MainMenuUIController::MainMenuUIController()
		{
			gameWindow = nullptr;
		}

		MainMenuUIController::~MainMenuUIController() 
		{

		}

	    void MainMenuUIController::initialize() 
		{
			gameWindow = ServiceLocator::getInstance()->GetGraphicService()->GetGameWindow();
		}

		void MainMenuUIController::update() {

		}

		void MainMenuUIController::render() {

		}
	}

}