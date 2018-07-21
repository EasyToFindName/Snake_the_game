#pragma once
#include <SFML\Graphics.hpp>
class PhysicsQuad;

class PhysicsForm {
public:
	PhysicsForm() = default;
	virtual ~PhysicsForm() = default;

	virtual PhysicsForm* clone() = 0;
	virtual void update(const sf::Vector2f& newPos) = 0;

	virtual bool isContain(sf::Vector2f point) const = 0;
	virtual bool isContain(double x, double y) const = 0;

	virtual bool isIntersect(const PhysicsForm& form) const = 0;
	virtual bool isIntersect(const PhysicsQuad& form) const = 0;

};