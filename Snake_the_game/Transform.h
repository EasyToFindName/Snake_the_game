#pragma once
#include <SFML\Graphics.hpp>
#include "Component.h"

COMPONENT_DERIVED_FROM_CLASS(Transform, sf::Transformable)
public:
	Transform(GameObject* gameObject);
	virtual ~Transform();

END_COMPONENT(Transform)