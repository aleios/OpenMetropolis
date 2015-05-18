# Set root directories for source and includes.
set(INC_ROOT ${CMAKE_SOURCE_DIR}/include/${PROJECT_NAME})
set(SRC_ROOT ${CMAKE_SOURCE_DIR}/src/${PROJECT_NAME})

include_directories(${CMAKE_SOURCE_DIR}/include)

# SFML includes
include_directories(${SFML_INCLUDE_DIR})

# Boost includes
include_directories(${Boost_INCLUDE_DIR})

# Sources and Includes for the project
set(SRC 
	${SRC_ROOT}/main.cpp
	
	${SRC_ROOT}/ScreenManager.cpp
	${SRC_ROOT}/GameConfig.cpp

   ${SRC_ROOT}/EditorScreen.cpp
	${SRC_ROOT}/GameScreen.cpp

   ${SRC_ROOT}/City.cpp
	)

set(INC 
	${INC_ROOT}/Screen.hpp
	${INC_ROOT}/ScreenController.hpp
	${INC_ROOT}/ScreenManager.hpp
	${INC_ROOT}/Modality.hpp
	${INC_ROOT}/GameConfig.hpp

	${INC_ROOT}/EditorScreen.hpp
	${INC_ROOT}/GameScreen.hpp

   ${INC_ROOT}/City.hpp
	)

add_executable(${PROJECT_NAME} ${SRC} ${INC})
target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES})
