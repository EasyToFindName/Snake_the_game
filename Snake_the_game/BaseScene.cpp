#include "BaseScene.h"
#include "GameObject.h"


BaseScene::BaseScene(sf::RenderWindow& window, const sf::Vector2u& size) : m_window(&window)
{
	setSceneSize(size);
	m_camera = std::make_unique<Camera>(window, *this);
}

BaseScene::~BaseScene()
{

}

void BaseScene::run(const sf::Time & dt)
{
	float deltaTime = static_cast<float>(dt.asMicroseconds()) / 100000.0f;

	m_camera->update(deltaTime);
}

void BaseScene::physicsUpdate()
{
	physicsManager.update();
}

void BaseScene::Destroy(GameObject * obj)
{
	for (auto it = m_gameObjects.begin(); it != m_gameObjects.end(); it++) {
		if (it->get() == obj) {
			m_gameObjects.erase(it);
			return;
		}
	}
}

Camera & BaseScene::mainCamera() const
{
	return *m_camera.get();
}

sf::Vector2u BaseScene::screenSize() const
{
	return m_window->getSize();
}

sf::Vector2u BaseScene::sceneSize() const
{
	return m_sceneSize;
}

void BaseScene::setSceneSize(const sf::Vector2u & size)
{
	m_sceneSize = size == sf::Vector2u(0, 0) ? m_window->getSize() : size;
}

