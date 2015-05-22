#pragma once
#ifndef CITYGENERATOR_HPP
#define CITYGENERATOR_HPP

#include <string>
#include <vector>

// Generate terrain
class CityGenerator
{
public:
   void Generate(unsigned int seed, unsigned int width, unsigned int height);

   bool Save(const std::string& filename);
private:
   unsigned int m_width{ 0 }, m_height{ 0 };
   std::vector<unsigned int> m_tiles;
};

#endif
