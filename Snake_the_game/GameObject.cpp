#include "GameObject.h"

GameObject::GameObject(BaseScene* mod)
{
	m_scene = mod;
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

BaseScene * GameObject::currentScene() const
{
	return m_scene;
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
