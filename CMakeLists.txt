cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

macro(set_option var default type docstring)
	if(NOT DEFINED %{var})
		set(${var} ${default})
	endif()
	set(${var} ${${var}} CACHE ${type} ${docstring} FORCE)
endmacro()

project("OpenMetropolis")

set(VERSION_MAJOR 0)
set(VERSION_MINOR 1)
set(VERSION_PATCH 0)

find_package(SFML 2 COMPONENTS system graphics audio window REQUIRED)

if(UNIX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++0x")
endif()

add_subdirectory(src/${PROJECT_NAME})
