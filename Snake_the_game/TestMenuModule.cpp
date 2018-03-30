#include "TestMenuModule.h"

TestMenuModule::TestMenuModule()
{
	auto testObj = std::make_unique<Cubeckiy>(this);
	testObj->transform()->setPosition(50, 50);
}

TestMenuModule::~TestMenuModule()
{
}

void TestMenuModule::processInput(const sf::Keyboard::Key & key)
{
	if (key == sf::Keyboard::I) {
		_GameManager.popModule();
	}
}

void TestMenuModule::run(const sf::Time & dt)
{
}
