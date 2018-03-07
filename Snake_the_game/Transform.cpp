#include "Transform.h"

Transform::Transform(GameObject * gameObject) : Component(gameObject)
{

}

Transform::~Transform()
{
}
/*
void Transform::setPosition(const sf::Vector2f & position)
{
	m_position = position;

	m_transform = sf::Transform(
		1, 0, (int)position.x,
		0, 1, (int)position.y,
		0, 0, 1);
}

void Transform::setPosition(float x, float y)
{
	setPosition(sf::Vector2f(x, y));
}

void Transform::translate(const sf::Vector2f & position)
{
	setPosition(m_position + position);
}

void Transform::translate(float x, float y)
{
	translate(sf::Vector2f(x, y));
}

sf::Vector2f Transform::position() const
{
	return m_position;
}

void Transform::setRotation(float angle)
{
	m_angle = angle;
}

void Transform::rotate(float angle)
{
	m_angle += angle;
	m_transform.rotate(angle);
}

float Transform::angle() const
{
	return m_angle;
}

sf::Transform Transform::getMatrix() const
{
	return m_transform;
}*/

COMPONENT Transform::getID()
{
	return COMPONENT::TRANSFORM;
}
