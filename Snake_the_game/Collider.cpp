#include "Collider.h"
#include "GameObject.h"


Collider::Collider(GameObject* g) : Component(g) {}

void Collider::calcCollision() {
	auto transform = m_gameObject->transform();
	
}

void Collider::setColliderBox(const sf::Rect<float>& box) {
	m_colliderBox = box;
}

