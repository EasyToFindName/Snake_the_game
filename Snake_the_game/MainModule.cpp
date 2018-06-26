#include "MainModule.h"

#include "Apple.h"

MainModule::MainModule() {
	m_snakeHead = Instantiate<SnakeHead>();
	Instantiate<Apple>();
}

void MainModule::processInput(const sf::Keyboard::Key& key) {

	m_snakeHead->processKey(key); //lifehook, huyna voobchem

	/*if (key == sf::Keyboard::I) {
		_GameManager.pushModule(std::make_unique<TestMenuModule>());
	}

	if (key == sf::Keyboard::D) {
		m_object->transform()->move(4.0f, 0.0f);
	}*/
}

void MainModule::run(const sf::Time& dt) {
	for (auto& object : m_gameObjects) {
		object->run((float)dt.asMicroseconds() / 100000.0f);
	}
}


MainModule::~MainModule() {
	
}
