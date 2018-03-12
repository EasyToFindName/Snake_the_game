#pragma once
#include <vector>
#include <memory>

#include "Transform.h"

class GameObject
{
public:
	GameObject();
	~GameObject();

	template<typename T>
	T& addComponent();

	template<typename T>
	T& getComponent();

	Transform& transform() const;

private: 
	std::vector<std::vector<std::unique_ptr<Component>>> m_components;
	Transform* m_transform;
};

template<typename T>
T& GameObject::addComponent()
{
	unsigned index = T::getId();

	if (index >= ComponentType::count())
		throw std::out_of_range("Out of component list");

	auto component = std::unique_ptr<T>(new T(this));
	auto componentAddr = component.get();

	m_components[index].push_back(std::move(component));

	return *componentAddr;
}

template<typename T>
T& GameObject::getComponent()
{
	unsigned index = T::getId();

	if (index >= ComponentType::count())
		throw std::out_of_range("Out of component list");

	if (m_components[index].empty())
		throw std::out_of_range("Out of component list");

	return std::dynamic_cast<T>(*m_components[index].at(0));
}
