#pragma once
#include <SFML\Graphics.hpp>
#include <vector>

class Collider;
using PhysicLayer = unsigned long;

class PhysicsManager {
public:
	PhysicsManager();
	~PhysicsManager();

	PhysicsManager(const PhysicsManager&) = delete;
	void operator=(const PhysicsManager&) = delete;

	void addCollider(Collider* collider);
	void removeCollider(Collider* collider);

	void update();

	std::vector<Collider*> getCollidersAtPoint(sf::Vector2f point, PhysicLayer maskLayer = 0);
	std::vector<Collider*> getCollidersAtPoint(double x, double y, PhysicLayer maskLayer = 0);

	bool isPointFree(sf::Vector2f point, PhysicLayer maskLayer = 0);
	bool isPointFree(double x, double y, PhysicLayer maskLayer = 0);

	/*check if "overlayer" contain layer*/
	static bool checkLayer(PhysicLayer a, PhysicLayer b);

private:
	std::vector<Collider*> m_colliders;

};