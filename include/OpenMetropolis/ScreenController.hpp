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

#pragma once
#ifndef SCREENCONTROLLER_HPP
#define SCREENCONTROLLER_HPP

#include <memory>
#include <OpenMetropolis/Modality.hpp>

namespace sf
{
	class RenderWindow;
}
class Screen;
class ScreenController
{
public:
	ScreenController(sf::RenderWindow& window)
		: m_window(window)
	{
	}
	virtual ~ScreenController() {}
	
	virtual void PushScreen(std::shared_ptr<Screen>& screen, Modality modality = Modality::Exclusive) = 0;
	virtual void PopScreen() = 0;

	void Quit() { m_isQuitting = true; }
	bool IsQuitting() const { return m_isQuitting; }
	
	sf::RenderWindow& GetWindow() const { return m_window; }
	
protected:
	bool m_isQuitting{ false };
private:
	sf::RenderWindow& m_window;
};

#endif