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

#include <OpenMetropolis/City.hpp>

City::City()
{
   //m_powerGrid.resize(width * height, 0);
   //m_waterGrid.resize(width * height, 0);

   m_background.setPrimitiveType(sf::PrimitiveType::Quads);
   //m_background.resize(width * height * 4);
}

bool City::Load(const std::string& filename)
{
   // Load map
   
   // Load City data
   return true;
}

bool City::Save(const std::string& filename)
{
   return true;
}
