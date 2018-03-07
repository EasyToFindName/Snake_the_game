#include "Component.h"

Component::Component(GameObject* gameObject) {
	m_gameObject = gameObject;
}

COMPONENT Component::getID()
{
	return COMPONENT::END;
}
