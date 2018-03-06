#include "Map.h"
#include <iostream>
#include "Draw_config.h"

Map::Map(sf::RenderWindow& w, unsigned width, unsigned height)
	:m_window(w),
	 m_width(width),
	 m_height(height) 
{
	
}

void Map::draw() const {
	for(auto& i : m_dynamicObjects) {
		i->draw(m_window);
	}

	for(auto& i : m_staticObjects) {
		i->draw(m_window);
	}
}

Point Map::generateStaticPos() const {
	return m_rand.generatePoint(Point(0, 0), Point(m_width, m_height));
}

const std::vector<std::unique_ptr<StaticObject>>& Map::iterateStatics() {
	return m_staticObjects;
}

const std::vector<std::unique_ptr<DynamicObject>>& Map::iterateDynamics() {
	return m_dynamicObjects;
}

const std::vector<std::unique_ptr<StaticObject>>& Map::iterateTemporaries() {
	return m_temporaryObjects;
}

const std::vector<Snake*>& Map::iterateSnakes() {
	return m_snakes;
}

Map::Map(sf::RenderWindow& window, unsigned width, unsigned height,
	std::vector<std::unique_ptr<StaticObject>>&& mapObjects,
	std::vector<std::unique_ptr<DynamicObject>>&& dynObjects)
	:m_window(window),
	 m_width(width),
	 m_height(height),
	 m_staticObjects(std::move(mapObjects)),
	 m_dynamicObjects(std::move(dynObjects))
{

}

Map::Map(Map&& m) 
	:m_window(m.m_window),
	 m_width(m.m_width),
	 m_height(m.m_height)
{
	std::swap(this->m_staticObjects, m.m_staticObjects);
	std::swap(this->m_dynamicObjects, m.m_dynamicObjects);
	std::swap(this->m_temporaryObjects, m.m_temporaryObjects);
	std::swap(this->m_snakes, m.m_snakes);
}

