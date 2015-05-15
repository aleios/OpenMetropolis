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
#ifndef GAMECONFIG_HPP
#define GAMECONFIG_HPP

#include <string>
#include <map>
#include <vector>
#include <boost/lexical_cast.hpp>
#include <algorithm> 
#include <functional> 
#include <cctype>
#include <locale>

class GameConfig
{
public:
	bool Load(std::string filename);
	bool Save(std::string filename);

	std::string GetString(std::string section, std::string key, std::string defaultVal = "") const;

	bool SectionExists(std::string section) const;
	bool KeyExists(std::string section, std::string key) const;

	template<typename T>
	T Get(std::string section, std::string key, T defaultVal) const
	{
		std::string val = GetString(section, key, "");
		if (val == "")
			return defaultVal;

		T rval;
		try
		{
			rval = boost::lexical_cast<T>(val);
		}
		catch (boost::bad_lexical_cast)
		{
			return defaultVal;
		}

		return rval;
	}

	
	bool GetBool(std::string section, std::string key, bool defaultVal) const
	{
		std::string val = GetString(section, key, "");
		if (val == "")
			return defaultVal;

		std::transform(val.begin(), val.end(), val.begin(), ::toupper);

		int numVal = 0;
		try
		{
			numVal = boost::lexical_cast<int>(val);
		}
		catch (boost::bad_lexical_cast)
		{
			numVal = 0;
		}

		if (val == "TRUE" || numVal > 0)
			return true;
		return false;
	}
private:
	struct ConfigSection
	{
		std::string m_name;
		std::map<std::string, std::string> m_kv;
	};

	// Section, Key, Value
	std::vector<ConfigSection> m_sections;
};

#endif
