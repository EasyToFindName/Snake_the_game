#include "PhysicsQuad.h"

PhysicsQuad::PhysicsQuad(double x, double y, double w, double h)
{
	m_rect = sf::FloatRect(x, y, w, h);
	m_globalRect = m_rect;
}

PhysicsQuad::PhysicsQuad(sf::FloatRect rect)
{
	m_rect = rect;
	m_globalRect = m_rect;
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
	return m_globalRect;
}

const sf::FloatRect & PhysicsQuad::getLocalRect() const
{
	return m_rect;
}

void PhysicsQuad::update(const sf::Vector2f& newPos)
{
	m_globalRect.left = newPos.x + m_rect.left;
	m_globalRect.top = newPos.y + m_rect.top;
}

bool PhysicsQuad::isIntersect(const PhysicsQuad & form) const
{
	auto a = this->getRect();
	auto b = form.getRect();
	return form.getRect().intersects(getRect());  // TO DO
}

bool PhysicsQuad::isIntersect(const PhysicsForm & form) const
{
	return form.isIntersect(*this);
}
