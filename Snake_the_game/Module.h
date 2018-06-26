#pragma once
#include <SFML\System.hpp>

#include "RenderManager.h"
#include "PhysicsManager.h"

class GameObject;

class Module {
public:
	explicit Module(Module* parent = nullptr);
	virtual ~Module();
	virtual void processInput(const sf::Keyboard::Key& key) = 0;
	virtual void run(const sf::Time& dt) = 0;
	void physicsUpdate();

	template<typename OBJECT_TYPE>
	OBJECT_TYPE* Instantiate(/*sf::Vector2f position = sf::Vector2f()*/);

	void Destroy(GameObject* obj);
	
	RenderManager renderManager;
	PhysicsManager physicsManager;

protected:
	std::vector<std::unique_ptr<GameObject>> m_gameObjects;

private:
	Module* m_parent;
};

template<typename OBJECT_TYPE>
inline OBJECT_TYPE * Module::Instantiate(/*sf::Vector2f position*/)
{
	m_gameObjects.emplace_back(std::make_unique<OBJECT_TYPE>(this));
	//m_gameObjects.back()->transform()->setPosition(position);
	return (OBJECT_TYPE*)m_gameObjects.back().get();
}