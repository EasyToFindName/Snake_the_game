#pragma once
#include <SFML\Graphics.hpp>
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

	std::vector<Collider*> getCollidersAtPoint(sf::Vector2f point, unsigned long maskLayer = 0);
	std::vector<Collider*> getCollidersAtPoint(double x, double y, unsigned long maskLayer = 0);

	bool isPointFree(sf::Vector2f point, unsigned long maskLayer = 0);
	bool isPointFree(double x, double y, unsigned long maskLayer = 0);

	static bool checkLayer(unsigned long a, unsigned long b);

private:
	std::vector<Collider*> m_colliders;

};