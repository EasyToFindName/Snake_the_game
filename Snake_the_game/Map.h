#pragma once
#include "Point.h"
#include "RandomGenerator.h"
#include "StaticObject.h"
#include "DynamicObject.h"

#include <SFML\Window.hpp>
#include <vector>
#include <memory>

class Map {
	friend class MapBuilder;
	//constructor for map builder
	Map(sf::RenderWindow& w, unsigned width, unsigned height);
public:
	Map(sf::RenderWindow& window, unsigned width, unsigned height,
		std::vector<std::unique_ptr<StaticObject>>&& mapObjects,
		std::vector<std::unique_ptr<DynamicObject>>&& dynObjects);

	Map(Map&& m);

	//static objects should be drawn by reversed interaction priority
	//portal > food > wall
	void draw() const;

	Point generateStaticPos() const;

	const std::vector<std::unique_ptr<StaticObject>>& iterateStatics();
	const std::vector<std::unique_ptr<DynamicObject>>& iterateDynamics();
	const std::vector<std::unique_ptr<StaticObject>>& iterateTemporaries();
	const std::vector<Snake*>& iterateSnakes();
private:
	sf::RenderWindow& m_window;

	unsigned m_width;
	unsigned m_height;

	//static objects should be placed by interaction priority
	//wall > food > portal etc
	std::vector<Snake*> m_snakes;
	std::vector<std::unique_ptr<StaticObject>> m_staticObjects;
	std::vector<std::unique_ptr<DynamicObject>> m_dynamicObjects;
	
	std::vector<std::unique_ptr<StaticObject>> m_temporaryObjects;

	mutable RandomGenerator m_rand;
};

