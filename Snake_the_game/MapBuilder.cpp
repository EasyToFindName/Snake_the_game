#include "MapBuilder.h"

MapBuilder::MapBuilder(sf::RenderWindow & w, unsigned width, unsigned height)
	:m_window(w),
	 m_width(width),
	 m_height(height)
{

}


MapBuilder::~MapBuilder() {}

MapBuilder& MapBuilder::addPermaFood(int amount) {
	for(int i = 0; i < amount; ++i) {
		m_permaFood.push_back(std::unique_ptr<Food>(new Food()));
	}

	return *this;
}

MapBuilder& MapBuilder::addDisposableFood(const Food& f) {
	m_dispoFood.push_back(std::unique_ptr<Food>(new Food(f)));
}

MapBuilder& MapBuilder::addWall(const Wall& w) {
	m_walls.push_back(std::unique_ptr<Wall>(new Wall(w)));
}

MapBuilder& MapBuilder::addSaw(const CircularSaw& s) {
	m_saws.push_back(std::unique_ptr<CircularSaw>(new CircularSaw(s)));
}

MapBuilder& MapBuilder::addPortal(const Portal& enter, const Portal& exit) {
	std::unique_ptr<Portal> p1(new Portal(enter));
	std::unique_ptr<Portal> p2(new Portal(exit));

	p1->connectWith(*p2);

	m_portals.push_back(std::move(p1));
	m_portals.push_back(std::move(p2));
}

MapBuilder& MapBuilder::addSnake(const Snake& s) {
	m_snakes.push_back(std::unique_ptr<Snake>(new Snake(s)));
}

Map MapBuilder::construct() {
	Map ret(m_window, m_width, m_height);

	for(auto& i : m_walls) {
		ret.m_staticObjects.push_back(std::move(i));
	}

	for(auto& i : m_permaFood) {
		ret.m_staticObjects.push_back(std::move(i));
	}

	for(auto& i : m_portals) {
		ret.m_staticObjects.push_back(std::move(i));
	}

	for(auto& i : m_dispoFood) {
		ret.m_temporaryObjects.push_back(std::move(i));
	}

	for(auto& i : m_saws) {
		ret.m_dynamicObjects.push_back(std::move(i));
	}

	for(auto& i : m_snakes) {
		ret.m_snakes.push_back(i.get());
		ret.m_dynamicObjects.push_back(std::move(i));
	}

	return ret;
}