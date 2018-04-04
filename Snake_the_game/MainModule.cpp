#include "MainModule.h"

MainModule::MainModule() {
	m_object = new Cubeckiy(this);

	m_gameObjects.emplace_back(std::make_unique<Cubeckiy>(this));
	m_gameObjects.back()->transform()->setPosition(100.0f, 0.0f);
}

void MainModule::processInput(const sf::Keyboard::Key& key) {
	if (key == sf::Keyboard::I) {
		_GameManager.pushModule(std::make_unique<TestMenuModule>());
	}

	if (key == sf::Keyboard::D) {
		m_object->transform()->move(4.0f, 0.0f);
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
