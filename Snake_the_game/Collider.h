#pragma once
#include "Component.h"
#include <SFML/Graphics.hpp>

COMPONENT(Collider)
public:
	Collider(GameObject*);
	void setColliderBox(const sf::Rect<float>& box);
	void calcCollision();


	virtual ~Collider() = default;
private:
	sf::Rect<float> m_colliderBox;
END_COMPONENT
