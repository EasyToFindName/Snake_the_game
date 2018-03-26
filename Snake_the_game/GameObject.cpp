#include "GameObject.h"

GameObject::GameObject() //: m_components(COMPONENT_MAX)
{
	m_transform = addComponent<Transform>();
	m_transform->setPosition(10, 15);
}

GameObject::~GameObject()
{
}

Transform& GameObject::transform() const
{
	return *m_transform;
}

GameObject * GameObject::clone()
{
	auto object = new GameObject();
	object->m_components.clear();

	for (auto& comps : m_components){
		for (auto& component : comps.second) {
			object->m_components.at(comps.first).emplace_back(std::unique_ptr<Component>(component->clone(object)));
		}
	}

	return object;
}
