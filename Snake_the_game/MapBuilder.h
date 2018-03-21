#pragma once

#include "Map.h"
#include "LevelObjects.h"
#include <map>
#include <memory>

//should add validations during construction
class MapBuilder {
public:
	MapBuilder(sf::RenderWindow& w, unsigned width, unsigned height);
	~MapBuilder();

	MapBuilder& addMovingFood(const MovingFood& f);
	MapBuilder& addPermaFood(int amount = 1);
	MapBuilder& addDisposableFood(const Food& f);
	MapBuilder& addWall(const Wall& w);
	MapBuilder& addSaw(const CircularSaw& s);
	MapBuilder& addPortal(const Portal& enter, const Portal& exit);
	MapBuilder& addSnake(const Snake& s);

	Map construct();
private:
	std::vector<std::unique_ptr<Portal>> m_portals;
	std::vector<std::unique_ptr<Food>> m_permaFood;
	std::vector<std::unique_ptr<Food>> m_dispoFood;
	std::vector<std::unique_ptr<Wall>> m_walls;
	std::vector<std::unique_ptr<Snake>> m_snakes;
	std::vector<std::unique_ptr<CircularSaw>> m_saws;
	std::vector<std::unique_ptr<MovingFood>> m_movingFood;

	sf::RenderWindow& m_window;

	unsigned m_width;
	unsigned m_height;
};

