#pragma once
#include "Module.h"

#include <SFML/System.hpp>
#include <memory>

class Game {
public:
	void run(const sf::Time& dt);
	void switchModule(std::unique_ptr<Module>&);
	
private:
	std::unique_ptr<Module> m_selectedModule;
};

