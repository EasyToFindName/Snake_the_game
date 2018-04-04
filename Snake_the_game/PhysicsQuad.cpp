#include "PhysicsQuad.h"

PhysicsQuad::PhysicsQuad(double x, double y, double w, double h)
{
	m_rect = sf::FloatRect(x, y, w, h);
}

PhysicsQuad::PhysicsQuad(sf::FloatRect rect)
{
	m_rect = rect;
}

PhysicsQuad::~PhysicsQuad()
{
}

PhysicsForm * PhysicsQuad::clone()
{
	PhysicsQuad* form = new PhysicsQuad(m_rect);
	return form;
}

const sf::FloatRect & PhysicsQuad::getRect() const
{
	return m_rect;
}

bool PhysicsQuad::isIntersect(const PhysicsQuad & form) const
{
	return form.m_rect.intersects(m_rect);  // TO DO
}

bool PhysicsQuad::isIntersect(const PhysicsForm & form) const
{
	return form.isIntersect(*this);
}
