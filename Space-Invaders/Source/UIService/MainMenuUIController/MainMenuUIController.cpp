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
			initializeBGImage();
			initializeButtonSprites();
		
		}

		void MainMenuUIController::initializeBGImage() {
			
			if (bgTexture.loadFromFile(bgTexture_Path))
			{
				bgSprite.setTexture(bgTexture);
				scaleBGImage();
			}
		}
		void MainMenuUIController::scaleBGImage() 
		{
					// Don't worry about the static_cast we will discuss it later. For now know that this function is
					// just scaling our background image based on the size of the game window
		
			bgSprite.setScale(
				static_cast<float>(gameWindow->getSize().x) / bgSprite.getTexture()->getSize().x,
				static_cast<float>(gameWindow->getSize().y) / bgSprite.getTexture()->getSize().y
			);
		}

		bool MainMenuUIController::loadButtonTexturesFromFile()
		{
			return playButtonTexture.loadFromFile(playButtonTexture_Path) &&
				instructionTexture.loadFromFile(instructionTexture_Path) &&
				quitButtonTexture.loadFromFile(quitButtonTexture_Path);

		}


		void MainMenuUIController::initializeButtonSprites() {
			if (loadButtonTexturesFromFile())
			{
				setButtonSprites();
				scaleAllButtons();
				positionButtonSprites();
			}

		}

		void MainMenuUIController::setButtonSprites() 
		{
			playButtonSprite.setTexture(playButtonTexture);
			instructionSprite.setTexture(instructionTexture);
			quitButtonSprite.setTexture(quitButtonTexture);

		}

		void MainMenuUIController::positionButtonSprites()
		{
			float xPosition = (static_cast<float>(gameWindow->getSize().x) / 2) - buttonWidth / 2;

			playButtonSprite.setPosition( {  xPosition, 500.0f });
			quitButtonSprite.setPosition( {  xPosition, 900.0f });
			instructionSprite.setPosition({  xPosition, 700.0f });

		}

		void  MainMenuUIController::scaleAllButtons() 
		{
			scaleButton(&playButtonSprite);
			scaleButton(&instructionSprite);
			scaleButton(&quitButtonSprite);

		}

		void  MainMenuUIController::scaleButton(sf::Sprite* buttonToScale) 
		{
			buttonToScale->setScale
				(   buttonWidth / buttonToScale->getTexture()->getSize().x,
					buttonHeight/ buttonToScale->getTexture()->getSize().y
				);


		}

		void MainMenuUIController::update() {

		}

		void MainMenuUIController::render() 
		{
			gameWindow->draw(bgSprite);
			gameWindow->draw(quitButtonSprite);
			gameWindow->draw(instructionSprite);
			gameWindow->draw(playButtonSprite);


		}

	}


}