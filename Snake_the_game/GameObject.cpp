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
