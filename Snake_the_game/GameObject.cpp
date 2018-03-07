#include "GameObject.h"

GameObject::GameObject() : m_components(ComponentType::count())
{
	try {
		m_transform = addComponent<Transform>();
		m_transform->setPosition(10, 15);
	}
	catch (std::exception& exp) {

	}
}


GameObject::~GameObject()
{
}

std::shared_ptr<Transform> GameObject::transform() const
{
	return m_transform;
}
