#pragma once

#include "RenderManager.h"
#include <SFML\System.hpp>

class Module {
public:
	explicit Module(Module* parent = nullptr);
	virtual ~Module();
	virtual void processInput(const sf::Keyboard::Key& key) = 0;
	virtual void run(const sf::Time& dt) = 0;
	RenderManager renderManager;
private:
	Module* m_parent;
};

