#include "MainScene.h"
#include "Apple.h"

MainScene::MainScene(sf::RenderWindow& window) : BaseScene(window) {
	m_snakeHead = Instantiate<SnakeHead>();
	Instantiate<Apple>();

	mainCamera().setTarget(m_snakeHead);
}

void MainScene::processInput(const sf::Keyboard::Key& key) {

	m_snakeHead->processKey(key); //lifehook, huyna voobchem

	/*if (key == sf::Keyboard::I) {
		_GameManager.pushModule(std::make_unique<TestMenuModule>());
	}

	if (key == sf::Keyboard::D) {
		m_object->transform()->move(4.0f, 0.0f);
	}*/
}

void MainScene::run(const sf::Time& dt) {
	float deltaTime = static_cast<float>(dt.asMicroseconds()) / 100000.0f;

	for (auto& object : m_gameObjects) {
		object->run(deltaTime);
	}

	BaseScene::run(dt);
}


MainScene::~MainScene() {
	
}
