#pragma once
#include <SFML\Graphics.hpp>

namespace sf {
	class math {
	public:
		/*clamp value between [min] and [max] */
		static float clamp(float min, float max, float value);
		/*clamp value between 0.0f and 1.0f */
		static float clamp01(float value);

		/*linear interpolation betwen a and b by interpolation factor t in [0.0f, 1.0f]*/
		static sf::Vector2f lerp(const sf::Vector2f& a, const sf::Vector2f& b, float t);
		/*linear interpolation betwen a and b by interpolation factor t in [0.0f, 1.0f]*/
		static sf::Vector3f lerp(const sf::Vector3f& a, const sf::Vector3f& b, float t);

		/*angle linear interpolation betwen a and b by interpolation factor t in [0.0f, 1.0f]*/
		static float lerpAngle(float a, float b, float t);
	};
}