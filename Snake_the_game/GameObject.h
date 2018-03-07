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
	std::shared_ptr<T> addComponent() throw();

	template<typename T>
	std::shared_ptr<T> getComponent() throw();

	std::shared_ptr<Transform> transform() const;

private:
	std::vector<std::vector<std::shared_ptr<Component>>> m_components;
	std::shared_ptr<Transform> m_transform;
};

template<typename T>
std::shared_ptr<T> GameObject::addComponent() throw()
{
	unsigned index = T::getId();

	if (index >= ComponentType::count())
		throw std::out_of_range("Out of component list");

	auto component = std::make_shared<T>(this);

	m_components[index].push_back(component);

	return component;
}

template<typename T>
std::shared_ptr<T> GameObject::getComponent() throw()
{
	unsigned index = T::getId();

	if (index >= ComponentType::count())
		throw std::out_of_range("Out of component list");

	if (m_components[index].empty())
		throw std::out_of_range("Out of component list");

	return std::dynamic_pointer_cast<T>(m_components[index].at(0));
}
