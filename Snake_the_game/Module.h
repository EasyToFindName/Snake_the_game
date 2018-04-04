#pragma once
#include <SFML\System.hpp>

#include "RenderManager.h"
#include "PhysicsManager.h"

class Module {
public:
	explicit Module(Module* parent = nullptr);
	virtual ~Module();
	virtual void processInput(const sf::Keyboard::Key& key) = 0;
	virtual void run(const sf::Time& dt) = 0;
	void physicsUpdate();
	
	RenderManager renderManager;
	PhysicsManager physicsManager;
private:
	Module* m_parent;
};

