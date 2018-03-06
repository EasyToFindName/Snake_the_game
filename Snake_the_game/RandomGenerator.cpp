#include "RandomGenerator.h"

RandomGenerator::RandomGenerator() : m_randomEngine(m_randomDevice()) {

}

Point RandomGenerator::generatePoint(Point&& lower_bound, Point&& upper_bound) {
	std::uniform_int_distribution<unsigned int> x_axis(lower_bound.x(), upper_bound.x() - 1);
	std::uniform_int_distribution<unsigned int> y_axis(lower_bound.y(), upper_bound.y() - 1);

	return Point(x_axis(m_randomEngine), y_axis(m_randomEngine));
}

int RandomGenerator::generateInt(int upperBound) {
	return generateInt(0, upperBound);
}

int RandomGenerator::generateInt(int lowerBound, int upperBound) {
	std::uniform_int_distribution<int> dist(lowerBound, upperBound);
	return dist(m_randomEngine);
}