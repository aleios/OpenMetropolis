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
#ifndef CITY_HPP
#define CITY_HPP

#include <string>
#include <vector>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Time.hpp>

enum TileType
{
   RESIDENTIAL,
   COMMERCIAL,
   INDUSTRIAL,
   POLICE,
   FIRE,
   HEALTH,
   POWER,
   WATER
};

struct TileData
{
   TileType m_type;

   int m_numPeople; // Residents/Employees
   unsigned int m_level; // Current state of the building.

   float m_powerUsage, m_waterUsage; // Power and Water supply requirement.
   float m_production; // Output of the building.
   float m_storedProducts; // Products waiting for pickup.


};

class City
   : public sf::Drawable
{
public:
   City();

   void Update(const sf::Time& timeElapsed);

   void SetBackgroundTile(unsigned int index, unsigned int tileID);

   bool Load(const std::string& filename);
   bool Save(const std::string& filename);

   unsigned int GetWidth() const { return m_width; }
   unsigned int GetHeight() const { return m_height; }
   unsigned int GetTileWidth() const { return m_tileWidth; }
   unsigned int GetTileHeight() const { return m_tileHeight; }

   virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
private:
   int m_cash{ 50000 }, m_loan{ 0 };

   // Budgets percentage
   unsigned int m_roadBudget{ 100 }, m_railBudget{ 100 }, m_powerBudget{ 100 }, m_waterBudget{ 100 }, m_fireBudget{ 100 }, m_policeBudget{ 100 }, m_healthBudget{ 100 };
   
   // Water and Power connections
   std::vector<char> m_powerGrid, m_waterGrid;
  
   // Textures
   sf::Texture m_backgroundTex;

   // Map data
   unsigned int m_width{ 0 }, m_height{ 0 }, m_tileWidth{ 0 }, m_tileHeight{ 0 };
   sf::VertexArray m_background, m_objectTiles, m_waterTiles, m_powerTiles;
};

#endif
