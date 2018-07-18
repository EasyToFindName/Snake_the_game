#include "math.h"


float sf::math::degToRad(float deg)
{
	return deg * sf::math::PI / 180.0f;
}

float sf::math::radToDeg(float rad)
{
	return rad * 180.0f / sf::math::PI;
}

float sf::math::clamp(float min, float max, float value)
{
	if (value > max)	value = max;
	if (value < min) value = min;
	return value;
}

float sf::math::clamp01(float value)
{
	return clamp(0.0f, 1.0f, value);
}

float sf::math::lerpAngle(float a, float b, float t)
{
	float shortAngle = ((((int)(b - a) % 360) + 540) % 360) - 180;
	return a + shortAngle * t;
}

float sf::math::dot(const sf::Vector2f & a, const sf::Vector2f & b)
{
	return a.x * b.x + a.y * b.y;
}

float sf::math::magnitude(const sf::Vector2f & a)
{
	return std::sqrt(squareMagnitude(a));
}

float sf::math::squareMagnitude(const sf::Vector2f & a)
{
	return a.x * a.x + a.y * a.y;
}

float sf::math::angleBetween(const sf::Vector2f & a, const sf::Vector2f & b)
{
	return radToDeg(std::atan2(a.x * b.x - a.y * b.y, dot(a, b)));
}

float sf::math::dirBetween(const sf::Vector2f& a, const sf::Vector2f& b)
{
	return radToDeg(std::atan2(b.y - a.y, b.x - a.x));
}
