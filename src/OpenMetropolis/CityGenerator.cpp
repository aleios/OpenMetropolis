#include <OpenMetropolis/CityGenerator.hpp>
#include <fstream>

void CityGenerator::Generate(unsigned int seed, unsigned int width, unsigned int height)
{
   // Setup tile array
   m_width = width;
   m_height = height;
   //m_tiles.clear();
   m_tiles.resize(width * height, 0);

   // Load tile parameter files.
   
   // Get IDs for groups grass, water, and dirt_tile
   
   // Generate based on seed
   
}

bool CityGenerator::Save(const std::string& filename)
{
   std::ofstream fs(filename);
   
   // Check if the file was opened.
   if(fs.bad() || !fs.is_open())
      return false;

   // Header
   fs << m_width << " " << m_height << "\n";

   // Write starting parameters
   

   // Save background layer 
   for(unsigned int y = 0; y < m_height; y++)
   {
      for(unsigned int x = 0; x < m_width; x++)
      {
         unsigned int idx = y * m_width + x;
         fs << m_tiles[idx] << " ";
      }
      fs << "\n";
   }
   
   // Save Object, road/rail, power and water layers with defaults.
   static const unsigned int unassignedLayers = 4;
   static const unsigned int defaultValue = 0;
   for(unsigned int y = 0; y < (m_height * unassignedLayers); y++)
   {
      for(unsigned int x = 0; x < m_width; x++)
      {
         fs << defaultValue << " ";
      }
      fs << "\n";
   }

   // Write per object data
   

   // Save successful.
   return true;  
}
