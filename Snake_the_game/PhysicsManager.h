#pragma once
#include <vector>

class Collider;

class PhysicsManager {
public:
	PhysicsManager();
	~PhysicsManager();

	PhysicsManager(const PhysicsManager&) = delete;
	void operator=(const PhysicsManager&) = delete;

	void addCollider(Collider* collider);
	void removeCollider(Collider* collider);

	void update();

private:
	std::vector<Collider*> colliders;

};