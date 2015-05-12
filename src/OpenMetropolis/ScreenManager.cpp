/*
This file is part of OpenMetropolis.

OpenMetropolis is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

OpenMetropolis is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with OpenMetropolis.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <OpenMetropolis/ScreenManager.hpp>
#include <OpenMetropolis/Screen.hpp>

void ScreenManager::PushScreen(std::shared_ptr<Screen>& screen, Modality modality)
{
	screen->OnEnter();
	
	if(modality == Modality::Exclusive)
		m_screenQueue.clear();
		
	m_screenQueue.push_back(screen.get());
	
	m_screens.push_back(ModalPair(screen, modality));
}

void ScreenManager::PopScreen()
{
	auto& screen = m_screens.back();
	screen.first->OnLeave();
	
	if(screen.second == Modality::Exclusive)
		RebuildLists();
	else
		m_screenQueue.pop_back();
		
	m_screens.pop_back();
}

void ScreenManager::Clear()
{
	m_screenQueue.clear();
	m_screens.clear();
}

void ScreenManager::RebuildLists()
{
	m_screenQueue.clear();
	
	if(m_screens.empty())
		return;
		
	size_t index = m_screens.size() - 1;
	while(index > 0)
	{
		if(m_screens[index].second == Modality::Exclusive)
			break;
		--index;
	}
	
	while(index < m_screens.size())
	{
		m_screenQueue.push_back(m_screens[index].first.get());
		++index;
	}
}