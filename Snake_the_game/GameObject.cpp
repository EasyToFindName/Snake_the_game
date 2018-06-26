#include "GameObject.h"

GameObject::GameObject(Module* mod)
{
	m_module = mod;
	addComponent<Transform>();
	setTag("Nan");
}

GameObject::~GameObject()
{
}

Transform* GameObject::transform()
{
	return getComponent<Transform>();
}

Module * GameObject::currentModule() const
{
	return m_module;
}

std::string GameObject::getTag() const
{
	return m_tag;
}

void GameObject::copyComponentsTo(GameObject & object) const
{
	object.m_components.clear();

	for (auto& comps : m_components) {
		for (auto& component : comps.second) {
			object.m_components.at(comps.first).emplace_back(std::unique_ptr<Component>(component->clone(&object)));
		}
	}
}

void GameObject::setTag(const std::string & tag)
{
	m_tag = tag;
}
