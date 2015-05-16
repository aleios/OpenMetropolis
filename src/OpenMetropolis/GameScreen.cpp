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
}

void GameScreen::Draw()
{
}
