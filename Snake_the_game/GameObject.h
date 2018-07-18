#pragma once
#include <vector>
#include <unordered_map>
#include <memory>

#include "Transform.h"
#include "Renderer.h"

#include <iostream>


class GameObject
{
public:
	GameObject(BaseScene* mod, const sf::Vector2f& position = {0.0f, 0.0f}, float angle = 0.0f);
	virtual ~GameObject();

	template<typename T>
	T* addComponent();

	template<typename T>
	T* getComponent();

	template<typename T>
	std::vector<T*> getComponents();

	Transform* transform();
	BaseScene* currentScene() const;

	virtual void run(float dt) {};
	virtual GameObject* clone() = 0;
	virtual void onCollision(const GameObject& gameObject) = 0;

	std::string getTag() const;

protected:
	template<typename T>
	T* convertComponent(Component* comp) const;

	void copyComponentsTo(GameObject& object) const;
	void setTag(const std::string& tag);

private: 
	std::unordered_map<unsigned, std::vector<std::unique_ptr<Component>>> m_components;
	BaseScene* m_scene;
	std::string m_tag;
};

template<typename T>
T* GameObject::addComponent()
{
	unsigned index = COMPONENT_VALUE(T);

	auto component = std::make_unique<T>(this);
	auto componentAddr = component.get();

	m_components[index].push_back(std::move(component));

	return componentAddr;
}

template<typename T>
T* GameObject::getComponent()
{
	unsigned index = COMPONENT_VALUE(T);

	if (m_components.at(index).empty())
		return nullptr;

	return convertComponent<T>(m_components[index].at(0).get());
}

template<typename T>
std::vector<T*> GameObject::getComponents()
{
	unsigned index = COMPONENT_VALUE(T);

	std::vector<T*> comps;
	comps.reserve((m_components.at(index).size()));

	for (auto &ptr : m_components[index]) {
		comps.push_back(convertComponent<T>(ptr.get()));
	}

	return comps;
}

template<typename T>
inline T * GameObject::convertComponent(Component * comp) const
{
	return static_cast<T*>(comp);
}
