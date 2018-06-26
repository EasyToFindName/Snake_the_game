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
	GameObject(Module* mod);
	virtual ~GameObject();

	template<typename T>
	T* addComponent();

	template<typename T>
	T* getComponent();

	template<typename T>
	std::vector<T*> getComponents();

	Transform* transform();
	Module* currentModule() const;

	virtual void run(float dt) {};
	virtual GameObject* clone() = 0;
	virtual void onCollision(const GameObject& gameObject) = 0;
protected:
	template<typename T>
	T* convertComponent(Component* comp) const;

	void copyComponentsTo(GameObject& object) const;

private: 
	std::unordered_map<unsigned, std::vector<std::unique_ptr<Component>>> m_components;
	Module* m_module;
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
