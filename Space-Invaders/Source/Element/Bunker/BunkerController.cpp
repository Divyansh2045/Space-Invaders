#include "../../HeaderFiles/Element/Bunker/BunkerController.h"
#include "../../HeaderFiles/Element/Bunker/BunkerView.h"



namespace Element
{
	namespace Bunker
	{
		BunkerController::BunkerController()
		{
			bunkerView = new BunkerView();
		}

		BunkerController::~BunkerController()
		{
			delete(bunkerView);
		}

		void BunkerController::initialize(BunkerData data)
		{
			bunkerData = data;
			bunkerView->initialize(this);
		}
		void BunkerController::update()
		{
			bunkerView->update();
		}

		void BunkerController::render()
		{
			bunkerView->render();
		}

		sf::Vector2f BunkerController::getBunkerPosition()
		{
			return bunkerData.position;
		}
	}
}