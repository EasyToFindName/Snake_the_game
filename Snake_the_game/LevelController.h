#pragma once

#include "Map.h"
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class LevelController {
public:
	LevelController(Map& m);
	
	void run(const sf::Time& elapsed);
	void draw();
	void catchInput(const sf::Keyboard::Key&);
private:
	Map& m_map;

}; 

