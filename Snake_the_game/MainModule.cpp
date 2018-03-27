#include "MainModule.h"

MainModule::MainModule() {
	m_object = new Cubeckiy(this);
}

void MainModule::processInput(const sf::Keyboard::Key& key) {
	if (key == sf::Keyboard::D) {
		m_object->transform()->move(4.0f, 0.0f);
	}
	else if (key == sf::Keyboard::W) {
		m_object->transform()->rotate(2.0f);
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
