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
#ifndef GAMESCREEN_HPP
#define GAMESCREEN_HPP

#include <OpenMetropolis/Screen.hpp>

class GameScreen
	: public Screen
{
public:
	GameScreen(std::shared_ptr<ScreenController> controller);

	virtual void OnEnter() override;
	virtual void OnLeave() override;

	virtual void Update(const sf::Time& timeElapsed) override;
	virtual void Draw() override;

private:

};

#endif
