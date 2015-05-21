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
#include <SFML/Graphics/RenderTarget.hpp>

City::City()
{
   //m_powerGrid.resize(width * height, 0);
   //m_waterGrid.resize(width * height, 0);

   m_background.setPrimitiveType(sf::PrimitiveType::Quads);
   //m_background.resize(width * height * 4);
}

void City::Update(const sf::Time& timeElapsed)
{
   
}

void City::SetBackgroundTile(unsigned int index, unsigned int tileID)
{
   static const unsigned int texCols = m_backgroundTex.getSize().x / m_tileWidth;
   float tu = (tileID % texCols) * m_tileWidth;
   float tv = (tileID / texCols) * m_tileHeight;

   m_background[index].texCoords = sf::Vector2f(tu, tv);
   m_background[index + 1].texCoords = sf::Vector2f(tu + m_tileWidth, tv);
   m_background[index + 2].texCoords = sf::Vector2f(tu + m_tileWidth, tv + m_tileHeight);
   m_background[index + 3].texCoords = sf::Vector2f(tu, tv + m_tileHeight);
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

void City::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
   // Draw background
   states.texture = &m_backgroundTex;
   target.draw(m_background, states);

   // Draw objects

   // Draw power grid
}
