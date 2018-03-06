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

	return *this;
}

MapBuilder& MapBuilder::addWall(const Wall& w) {
	m_walls.push_back(std::unique_ptr<Wall>(new Wall(w)));
	return *this;
}

MapBuilder& MapBuilder::addSaw(const CircularSaw& s) {
	m_saws.push_back(std::unique_ptr<CircularSaw>(new CircularSaw(s)));
	return *this;
}

MapBuilder& MapBuilder::addPortal(const Portal& enter, const Portal& exit) {
	std::unique_ptr<Portal> p1(new Portal(enter));
	std::unique_ptr<Portal> p2(new Portal(exit));

	p1->connectWith(*p2);

	m_portals.push_back(std::move(p1));
	m_portals.push_back(std::move(p2));
	return *this;
}

MapBuilder& MapBuilder::addSnake(const Snake& s) {
	m_snakes.push_back(std::unique_ptr<Snake>(new Snake(s)));
	return *this;
}

Map MapBuilder::construct() {
	Map ret(m_window, m_width, m_height);

	//creating borders
	for (int x = 0; x < m_width; ++x) {
		addWall((Point(x, 0)));
		addWall(Point(x, m_height - 1));
	}
	
	for (int y = 0; y < m_height; ++y) {
		addWall(Point(0, y));
		addWall(Point(m_width - 1, y));
	}

	for(int i = 0; i < m_width; ++i) {
		for(int j = 0; j < m_height; ++j) {
			Point p = Point(i, j);
			
			bool flag = true;
			for(auto& wall : m_walls) {
				if(wall->pos == p) {
					flag = false;
					break;
				}
			}

			if(flag) {
				ret.m_freeCells.push_back(p);
			}
		}
	}

	//constructing map
	for(auto& i : m_walls) {
		ret.m_staticObjects.push_back(std::move(i));
	}

	for(auto& i : m_permaFood) {
		i->pos = ret.generateStaticPos();
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