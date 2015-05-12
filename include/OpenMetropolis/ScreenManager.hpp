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
#ifndef SCREENMANAGER_HPP
#define SCREENMANAGER_HPP

#include <OpenMetropolis/ScreenController.hpp>
#include <vector>

namespace sf
{
	class Time;
}

class ScreenManager
	: public ScreenController
{
public:
	ScreenManager(sf::RenderWindow& window);
	
	virtual void PushScreen(std::shared_ptr<Screen>& screen, Modality modality = Modality::Exclusive) override;
	virtual void PopScreen() override;
	void Clear();
	
	void Update(const sf::Time& timeElapsed);
	void Draw();
private:
	void RebuildLists();

	typedef std::pair<std::shared_ptr<Screen>, Modality> ModalPair;
	std::vector<ModalPair> m_screens;
	std::vector<Screen*> m_screenQueue;
};

#endif