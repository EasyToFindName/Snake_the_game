#pragma once
#include <SFML\System.hpp>

#include "RenderManager.h"
#include "PhysicsManager.h"

#include "Camera.h"

class GameObject;

class BaseScene {
public:
	explicit BaseScene(sf::RenderWindow& window);
	virtual ~BaseScene();
	virtual void processInput(const sf::Keyboard::Key& key) = 0;
	virtual void run(const sf::Time& dt);
	void physicsUpdate();

	template<typename OBJECT_TYPE>
	OBJECT_TYPE* Instantiate(/*sf::Vector2f position = sf::Vector2f()*/);

	void Destroy(GameObject* obj);
	
	RenderManager renderManager;
	PhysicsManager physicsManager;

	Camera& mainCamera() const;

protected:
	std::vector<std::unique_ptr<GameObject>> m_gameObjects;

private:
	sf::RenderWindow* m_window;
	std::unique_ptr<Camera> m_camera;
};

template<typename OBJECT_TYPE>
inline OBJECT_TYPE * BaseScene::Instantiate(/*sf::Vector2f position*/)
{
	m_gameObjects.emplace_back(std::make_unique<OBJECT_TYPE>(this));
	//m_gameObjects.back()->transform()->setPosition(position);
	return (OBJECT_TYPE*)m_gameObjects.back().get();
}