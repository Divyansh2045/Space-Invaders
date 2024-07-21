#pragma once
#include <SFML/Graphics.hpp>


namespace UI {

	namespace MainMenu
	{
		class MainMenuUIController
		{
		private:

			sf::RenderWindow* gameWindow;

		public:

			MainMenuUIController();
			~MainMenuUIController();


			void initialize();
			void render();
			void update();
			void destroy();
		};

	}
}
