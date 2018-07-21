#include "PhysicsManager.h"
#include "Collider.h"

#include <iostream>

PhysicsManager::PhysicsManager()
{
}

PhysicsManager::~PhysicsManager()
{
}

void PhysicsManager::addCollider(Collider * collider)
{
	m_colliders.push_back(collider);
}

void PhysicsManager::removeCollider(Collider * collider)
{
	auto it = std::find(m_colliders.begin(), m_colliders.end(), collider);
	m_colliders.erase(it);
}

void PhysicsManager::update()
{
	//UPDATE
	for (auto& collider : m_colliders) {
		collider->update();
	}

	//COLLISION DETECTION
	for (size_t i = 0; i < m_colliders.size(); i++) {

		if (!m_colliders[i]->getForm()) continue;

		for (size_t j = i + 1; j < m_colliders.size(); j++) {

			if (!m_colliders[j]->getForm()) continue;

			//IF m_colliders FORMS INTERSECT
			if (m_colliders[i]->getForm()->isIntersect(*m_colliders[j]->getForm())) {

				m_colliders[i]->onCollision(*m_colliders[j]);
				m_colliders[j]->onCollision(*m_colliders[i]);

			}
		}
	}

}

std::vector<Collider*> PhysicsManager::getCollidersAtPoint(sf::Vector2f point, PhysicLayer maskLayer)
{
	return getCollidersAtPoint(point.x, point.y, maskLayer);
}

std::vector<Collider*> PhysicsManager::getCollidersAtPoint(double x, double y, PhysicLayer maskLayer)
{
	std::vector<Collider*> colliders;

	for (auto& collider : m_colliders) {
		if (checkLayer(collider->getLayer(), maskLayer) && !collider->getForm()->isContain(x, y)) {
			colliders.push_back(collider);
		}
	}
	return colliders;
}

bool PhysicsManager::isPointFree(sf::Vector2f point, PhysicLayer maskLayer)
{
	return isPointFree(point.x, point.y, maskLayer);
}

bool PhysicsManager::isPointFree(double x, double y, PhysicLayer maskLayer)
{
	for (auto& collider : m_colliders) {
		if (checkLayer(collider->getLayer(), maskLayer) && !collider->getForm()->isContain(x, y)) {
			return true;
		}
	}
	return false;
}

bool PhysicsManager::checkLayer(PhysicLayer a, PhysicLayer b)
{
	return (a & b) == b || (a & b) == a;
}
