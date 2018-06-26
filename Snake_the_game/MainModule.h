#pragma once

#include "Module.h"
#include "GameObject.h"

//#include "Cubeckiy.h"
//#include "TestMenuModule.h" 

#include "SnakeHead.h"

class MainModule : public Module {
public:
	MainModule();
	virtual ~MainModule();
	virtual void processInput(const sf::Keyboard::Key& key) override;
	virtual void run(const sf::Time& dt) override;

	
private:
	SnakeHead* m_snakeHead;
};

