#include "math.h"

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

sf::Vector2f sf::math::lerp(const sf::Vector2f & a, const sf::Vector2f & b, float t)
{
	t = clamp01(t);
	return a * (1.0f - t) + b * t;
}

sf::Vector3f sf::math::lerp(const sf::Vector3f & a, const sf::Vector3f & b, float t)
{
	t = clamp01(t);
	return a * (1.0f - t) + b * t;
}

float sf::math::lerpAngle(float a, float b, float t)
{
	float shortAngle = ((((int)(b - a) % 360) + 540) % 360) - 180;
	return a + shortAngle * t;
}
