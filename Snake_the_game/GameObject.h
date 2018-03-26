#pragma once
#include <vector>
#include <unordered_map>
#include <memory>

#include "Transform.h"
#include "Renderer.h"
#include "Module.h"

#include <iostream>

class GameObject
{
public:
	GameObject();
	~GameObject();

	template<typename T>
	T* addComponent();

	template<typename T>
	T* getComponent();

	template<typename T>
	std::vector<T*> getComponents();

	Transform& transform() const;

	virtual GameObject* clone();
protected:
	template<typename T>
	T* convertComponent(Component* comp) const;

private: 
	std::unordered_map<unsigned, std::vector<std::unique_ptr<Component>>> m_components;
	Transform* m_transform;

};

template<typename T>
T* GameObject::addComponent()
{
	unsigned index = COMPONENT_VALUE(T);

	if (index >= COMPONENT_MAX)
		throw std::out_of_range("Out of component list");

	auto component = std::unique_ptr<T>(new T(this));
	auto componentAddr = component.get();

	m_components[index].push_back(std::move(component));

	return componentAddr;
}

template<typename T>
T* GameObject::getComponent()
{
	unsigned index = COMPONENT_VALUE(T);

	if (index >= m_components.size())
		throw std::out_of_range("Out of component list");

	if (m_components[index].empty())
		return nullptr;

	return convertComponent<T>(m_components[index].at(0).get());
}

template<typename T>
std::vector<T*> GameObject::getComponents()
{
	unsigned index = COMPONENT_VALUE(T);

	if (index >= m_components.size())
		throw std::out_of_range("Out of component list");

	std::vector<T*> comps;
	comps.reserve((m_components[index].size()));

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
