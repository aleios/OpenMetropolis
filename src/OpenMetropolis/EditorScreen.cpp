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

#include <OpenMetropolis/EditorScreen.hpp>
#include <OpenMetropolis/ScreenController.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/System/Time.hpp>

EditorScreen::EditorScreen(std::shared_ptr<ScreenController> controller)
   : Screen(controller)
{
}

void EditorScreen::OnEnter()
{
}

void EditorScreen::OnLeave()
{
}

void EditorScreen::Update(const sf::Time& timeElapsed)
{
   auto& window = m_controller->GetWindow();
   
   sf::Event ev;
   while(window.pollEvent(ev))
   {
      if(ev.type == sf::Event::Closed)
         m_controller->Quit();
   }
}

void EditorScreen::Draw()
{
}
