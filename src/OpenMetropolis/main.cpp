/*
This file is part of OpenMetropolis.

OpenMetropolis is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

OpenMetropolis is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with OpenMetropolis.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <iostream>
#include <SFML/Graphics.hpp>

#include <OpenMetropolis/ScreenManager.hpp>
#include <OpenMetropolis/GameScreen.hpp>
#include <OpenMetropolis/GameConfig.hpp>

int main(int argc, char** argv)
{
   GameConfig config;
   config.Load("assets/settings.ini");
   
   auto windowWidth = config.Get<unsigned int>("graphics", "windowwidth", 800);
   auto windowHeight = config.Get<unsigned int>("graphics", "windowheight", 600);

	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Open Metropolis");
	window.setFramerateLimit(60);

	auto manager = std::make_shared<ScreenManager>(window);

	std::shared_ptr<Screen> initialScreen = std::make_shared<GameScreen>(manager);
	manager->PushScreen(initialScreen);
   
	sf::Clock gameClock;
	while (window.isOpen())
	{
		sf::Event ev;
		while (window.pollEvent(ev))
		{
			if (ev.type == sf::Event::Closed)
				window.close();
		}
		// Update
		manager->Update(gameClock.getElapsedTime());

		// Draw
		window.clear();
		manager->Draw();
		window.display();
	}

	return 0;
}
