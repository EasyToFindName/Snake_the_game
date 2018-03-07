#pragma once

class GameObject;

class Component {
public:
	Component(GameObject* gameObject);

	Component(const Component&) = delete;
	void operator=(const Component&) = delete;

	virtual ~Component() = default;


	virtual unsigned getType() = 0;

protected:
	GameObject* m_gameObject;
};

#include "MetaComponent.h"