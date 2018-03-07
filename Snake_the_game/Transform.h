#pragma once
#include <SFML\Graphics.hpp>
#include "Component.h"

class Transform : public Component, public sf::Transformable {
public:
	Transform(GameObject* gameObject);
	virtual ~Transform();

	static COMPONENT getID();
};