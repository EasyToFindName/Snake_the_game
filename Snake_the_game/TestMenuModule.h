#pragma once
#include "Module.h"
//#include "Cubeckiy.h"

class TestMenuModule : public Module
{
public:
	TestMenuModule();
	virtual ~TestMenuModule();

	virtual void processInput(const sf::Keyboard::Key& key) override;
	virtual void run(const sf::Time& dt) override;

private:

};