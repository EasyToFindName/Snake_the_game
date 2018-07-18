#include "MainScene.h"
#include "Apple.h"
#include "Block.h"
#include "Saw.h"

MainScene::MainScene(sf::RenderWindow& window, const sf::Vector2u& size) : BaseScene(window, size) {
	m_snakeHead = Instantiate<SnakeHead>();

	for (int i = 0; i < 10; ++i) {
		Instantiate<Apple>();
	}

	/*CREATE WALLS*/
	for (int i = 0; i < this->sceneSize().x; i += 32) {
		Instantiate<Block>({ (float)i, 0.0f });
		Instantiate<Block>({ (float)i, (float)sceneSize().y - 32 });
	}
	for (int i = 0; i < this->sceneSize().y; i += 32) {
		Instantiate<Block>({ 0.0f, (float)i });
		Instantiate<Block>({ (float)sceneSize().x - 32, (float)i });
	}
	/*************/

	Instantiate<Saw>({256, 256});


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
