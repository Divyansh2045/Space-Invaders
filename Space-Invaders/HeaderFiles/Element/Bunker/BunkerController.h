#pragma once
#include <SFML/Graphics.hpp>
#include "../../HeaderFiles/Element/Bunker/BunkerModel.h"

namespace Element
{
	class BunkerView;
	namespace Bunker
	{

class BunkerController

{
    private:

		BunkerData bunkerData;
		BunkerView* bunkerView;

    public:
		
		BunkerController();
		~BunkerController();

		void update();
		void initialize(BunkerData data);
		void render();

		sf::Vector2f getBunkerPosition();

};
	}
}
