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
	colliders.push_back(collider);
}

void PhysicsManager::removeCollider(Collider * collider)
{
	auto it = std::find(colliders.begin(), colliders.end(), collider);
	colliders.erase(it);
}

void PhysicsManager::update()
{
	//COLLISION DETECTION
	for (size_t i = 0; i < colliders.size(); i++) {

		if (!colliders[i]->getForm()) continue;

		for (size_t j = i; j < colliders.size(); j++) {

			if (!colliders[j]->getForm()) continue;

			//IF COLLIDERS FORMS INTERSECT
			if (colliders[i]->getForm()->isIntersect(*colliders[j]->getForm())) {
				std::cout << "Collision!" << std::endl;
			}
		}
	}

}
