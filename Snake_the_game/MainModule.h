#pragma once

#include "Module.h"
#include "GameObject.h"
#include "Cubeckiy.h"
#include "TestMenuModule.h" 

class MainModule : public Module {
public:
	MainModule();
	virtual ~MainModule();
	virtual void processInput(const sf::Keyboard::Key& key) override;
	virtual void run(const sf::Time& dt) override;

private:
	GameObject* m_object;

	std::vector<std::unique_ptr<GameObject>> m_gameObjects;
};

