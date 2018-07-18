#pragma once
#include <SFML\System.hpp>

#include "RenderManager.h"
#include "PhysicsManager.h"

#include "Camera.h"

class GameObject;

class BaseScene {
public:
	explicit BaseScene(sf::RenderWindow& window, const sf::Vector2u& size = {0, 0});
	virtual ~BaseScene();
	virtual void processInput(const sf::Keyboard::Key& key) = 0;
	virtual void run(const sf::Time& dt);
	void physicsUpdate();

	template<typename OBJECT_TYPE>
	OBJECT_TYPE* Instantiate(const sf::Vector2f& position = { 0.0f, 0.0f }, float angle = 0.0f);

	void Destroy(GameObject* obj);
	
	RenderManager renderManager;
	PhysicsManager physicsManager;

	Camera& mainCamera() const;
	sf::Vector2u screenSize() const;
	
	sf::Vector2u sceneSize() const;
	void setSceneSize(const sf::Vector2u& size);

protected:
	std::vector<std::unique_ptr<GameObject>> m_gameObjects;

private:
	sf::RenderWindow* m_window;
	std::unique_ptr<Camera> m_camera;
	sf::Vector2u m_sceneSize;
};

template<typename OBJECT_TYPE>
inline OBJECT_TYPE * BaseScene::Instantiate(const sf::Vector2f& position, float angle)
{
	m_gameObjects.emplace_back(std::make_unique<OBJECT_TYPE>(this, position, angle));
	//m_gameObjects.back()->transform()->setPosition(position);
	return (OBJECT_TYPE*)m_gameObjects.back().get();
}