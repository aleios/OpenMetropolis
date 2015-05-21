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
#include <OpenMetropolis/GameScreen.hpp>
#include <OpenMetropolis/ScreenController.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/System/Time.hpp>

GameScreen::GameScreen(std::shared_ptr<ScreenController> controller)
	: Screen(controller)
{
}

void GameScreen::OnEnter()
{  
   m_defaultFont.loadFromFile("assets/fonts/Oxygen-Regular.ttf");
   m_text.setFont(m_defaultFont);
   m_text.setString("Hello, World");

   m_view = m_controller->GetWindow().getDefaultView();
   
}

void GameScreen::OnLeave()
{    
}

void GameScreen::Update(const sf::Time& timeElapsed)
{
   auto& window = m_controller->GetWindow();
   sf::Event ev;
   while(window.pollEvent(ev))
   {
      if(ev.type == sf::Event::Closed)
         m_controller->Quit();
   }

   // Mouse Position
   sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

   if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
   {
      sf::Vector2i mouseTileIndex(mousePos.x / m_city.GetTileWidth(), mousePos.y / m_city.GetTileHeight());

      unsigned int idx = mouseTileIndex.y * m_city.GetWidth() + mouseTileIndex.x;
      m_city.SetBackgroundTile(idx, 0);
   }

   
   // Update View
   window.setView(m_view);
   
}

void GameScreen::Draw()
{
   auto& window = m_controller->GetWindow();
   window.draw(m_text);
}
