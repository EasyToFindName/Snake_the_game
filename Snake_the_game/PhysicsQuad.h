#pragma once
#include <SFML\Graphics.hpp>

#include "PhysicsForm.h"

class PhysicsQuad : public PhysicsForm {
public:
	PhysicsQuad(double x, double y, double w, double h);
	PhysicsQuad(sf::FloatRect rect);
	virtual ~PhysicsQuad();

	virtual PhysicsForm* clone() override;
	const sf::FloatRect& getRect() const;
	const sf::FloatRect& getLocalRect() const;

	virtual void update(const sf::Vector2f& newPos) override;

	virtual bool isIntersect(const PhysicsForm& form) const override;
	virtual bool isIntersect(const PhysicsQuad& form) const override;

private:
	sf::FloatRect m_rect;
	sf::FloatRect m_globalRect;
};