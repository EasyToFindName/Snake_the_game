#include "BaseScene.h"
#include "GameObject.h"


BaseScene::BaseScene(sf::RenderWindow& window) : m_window(&window)
{
	m_camera = std::make_unique<Camera>(window);
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

