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
#ifndef SCREEN_HPP
#define SCREEN_HPP

#include <memory>

namespace sf
{
	class Time;
	class Event;
}

class ScreenController;
class Screen
{
public:
	Screen(std::shared_ptr<ScreenController> controller)
		: m_controller(controller)
	{
	}

	virtual ~Screen() {}
	
	virtual void OnEnter() = 0;
	virtual void OnLeave() = 0;
	
	virtual void Update(const sf::Time& timeElapsed) = 0;
	virtual void Draw() = 0;
protected:
	std::shared_ptr<ScreenController> m_controller;
};

#endif