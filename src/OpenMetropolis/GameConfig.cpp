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

#include <OpenMetropolis/GameConfig.hpp>
#include <fstream>
#include <boost/algorithm/string/trim.hpp>

bool GameConfig::Load(std::string filename)
{
	std::ifstream file(filename);

	if (!file.is_open() || file.fail())
		return false;

	std::string line;
	ConfigSection* currentSection = nullptr;
	while (std::getline(file, line))
	{
		// Scan first char.
		if (line[0] == '#' || line[0] == ';') // Assume Comment
		{
			continue;
		}
		else if (line[0] == '[') // Assume section
		{
			int endIndex = line.find_first_of(']');

			// Can't find end!
			if (endIndex == std::string::npos)
			{
				// Syntax Error:
				return false;
			}
			else if (endIndex == 1) // Empty Section name...
			{
				return false;
			}

			// Get Name
			std::string name = line.substr(1, endIndex - 1);

			// Trim and uppercase.
			boost::trim(name);
			std::transform(name.begin(), name.end(), name.begin(), toupper);

			// Test if valid name.

			// We already have a section with this name so we have a duplication issue.
			if (SectionExists(name))
			{
				return false;
			}

			// Add section to vector and set it as the current one for the kv pairs.
			ConfigSection section;
			section.m_name = name;
			m_sections.push_back(section);
			currentSection = &m_sections.back();
		}
		else // Key-value pair?
		{
			// No sections... issue.
			if (currentSection == nullptr)
			{
				return false;
			}

			int keyEnd = line.find_first_of('=');

			if (keyEnd == std::string::npos)
			{
				return false;
			}

			std::string keyName = line.substr(0, keyEnd);

			// Trim and uppercase
			boost::trim(keyName);
			std::transform(keyName.begin(), keyName.end(), keyName.begin(), toupper);

			if (KeyExists(currentSection->m_name, keyName))
			{
				return false;
			}

			// TODO: Check for comment within.
			std::string value = line.substr(keyEnd + 1, line.size());
			boost::trim(value);

			// Insert into current section.
			currentSection->m_kv.insert(std::pair<std::string, std::string>(keyName, value));
		}
	}

	return true;
}

bool GameConfig::Save(std::string filename)
{
	std::ofstream file(filename);

	if (!file.is_open() || file.fail())
		return false;

	for (auto& section : m_sections)
	{
		file << "[" << section.m_name << "]\n";

		for (auto& kp : section.m_kv)
		{
			file << kp.first << "=" << kp.second << "\n";
		}
	}

	file.close();
	return true;
}

std::string GameConfig::GetString(std::string section, std::string key, std::string defaultVal) const
{
	if (!KeyExists(section, key))
		return defaultVal;

	// Key to upper
	std::transform(section.begin(), section.end(), section.begin(), toupper);
	std::transform(key.begin(), key.end(), key.begin(), toupper);

	auto p = std::find_if(m_sections.begin(), m_sections.end(), [&](const ConfigSection& sect) { return sect.m_name == section; });

	return p->m_kv.at(key);
}

bool GameConfig::SectionExists(std::string section) const
{
	// Section to uppercase
	std::transform(section.begin(), section.end(), section.begin(), toupper);
	auto p = std::find_if(m_sections.begin(), m_sections.end(), [&](const ConfigSection& sect) { return sect.m_name == section; });
	return (p != m_sections.end());
}

bool GameConfig::KeyExists(std::string section, std::string key) const
{
	// Key name to uppercase
	std::transform(section.begin(), section.end(), section.begin(), toupper);
	std::transform(key.begin(), key.end(), key.begin(), toupper);

	// Get the requested sections index.
	auto& sectionIdx = std::find_if(m_sections.begin(), m_sections.end(), [&](const ConfigSection& sect) { return sect.m_name == section; });

	// Section doesn't exist if we made it to the end of the loop.
	if (sectionIdx == m_sections.end())
		return false;

	// Check if the key exists within the section.
	for (auto kp : sectionIdx->m_kv)
	{
		if (kp.first == key)
			return true;
	}

	return false;
}