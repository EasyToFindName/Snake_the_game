#pragma once
#include <SFML\Graphics.hpp>

namespace sf {
	class math {
	public:
		static constexpr float PI = 3.14159265359;

		static float degToRad(float deg);
		static float radToDeg(float rad);

		/*clamp value between [min] and [max] */
		static float clamp(float min, float max, float value);

		/*clamp value between 0.0f and 1.0f */
		static float clamp01(float value);

		/*linear interpolation betwen a and b by interpolation factor t in [0.0f, 1.0f]*/
		template<typename T>
		static T lerp(const T& a, const T& b, float t);

		/*angle linear interpolation betwen a and b in deg by interpolation factor t in [0.0f, 1.0f]*/
		static float lerpAngle(float a, float b, float t);

		/*angle of direction from point a to b in deg*/
		static float dirBetween(const sf::Vector2f& a, const sf::Vector2f& b);

		/*dot production of vectors*/
		static float dot(const sf::Vector2f& a, const sf::Vector2f& b);

		/*vector magnitude*/
		static float magnitude(const sf::Vector2f& a);

		/*square vector magnitude*/
		static float squareMagnitude(const sf::Vector2f& a);

		/*angle between 2 vectors in deg*/
		static float angleBetween(const sf::Vector2f& a, const sf::Vector2f& b);
	};

	template<typename T>
	inline T math::lerp(const T & a, const T & b, float t)
	{
		t = clamp01(t);
		return a * (1.0f - t) + b * t;
	}
}