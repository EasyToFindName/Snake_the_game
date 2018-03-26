#pragma once
#include <SFML\Graphics.hpp>
#include "Component.h"

COMPONENT_DERIVED_FROM_CLASS(Transform, sf::Transformable)
public:
	Transform(GameObject* gameObject);
	virtual ~Transform();
	virtual Component* clone(GameObject* gameObject) override;

END_COMPONENT(Transform)