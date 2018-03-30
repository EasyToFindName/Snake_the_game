#include "MainModule.h"

MainModule::MainModule() {
	m_object = new Cubeckiy(this);
}

void MainModule::processInput(const sf::Keyboard::Key& key) {
	if (key == sf::Keyboard::I) {
		_GameManager.pushModule(std::make_unique<TestMenuModule>());
	}
}

void MainModule::run(const sf::Time& dt) {
	for (auto& object : m_gameObjects) {
		object->run(dt);
	}
}


MainModule::~MainModule() {
	delete m_object;
}
