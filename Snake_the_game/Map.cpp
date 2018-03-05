#include "Map.h"
#include <iostream>
#include "Draw_config.h"

const sf::Time Map::GAME_UPDATE_RATE = sf::milliseconds(_GAME_UPDATE_RATE);

Map::Map(sf::RenderWindow& window, unsigned width, unsigned height,
	std::vector<std::unique_ptr<StaticObject>>&& mapObjects,
	std::vector<std::unique_ptr<DynamicObject>>&& dynObjects)
	:m_elapsedTime(sf::Time::Zero),
	 m_width(width),
	 m_height(height),
	 m_staticObjects(std::move(mapObjects)),
	 m_dynamicObjects(std::move(dynObjects)),
	 m_window(window)

{
	load();
}

void Map::load() {
	m_snake.reset(new Snake(Point(8, 2), Direction::RIGHT, 3, sf::milliseconds(300)));
	m_food.reset(new Food);
	m_food->pos = generateFoodPos();
}

void Map::update(const sf::Time& elapsed) {
	
	m_snake->updateTimer(elapsed);

	if(!m_snake->isAlive()) {
		load();
		return;
	}

	if (m_snake->isTimerExpired()) {
		for (auto& object : m_staticObjects) {
			m_snake->reactOn(*object);
		}

		if (m_snake->reactOn(*m_food)) {
			m_food->pos = generateFoodPos();
		}

		if (m_snake->isAlive()) {
			m_snake->move();
		}

		m_snake->resetTimer();
		draw();
	}

	for (auto& object : m_dynamicObjects) {
		object->updateTimer(elapsed);
		if (object->isTimerExpired()) {
			object->move();
			m_snake->reactOn(*object);

			if (m_snake->isChopped()) {
				auto objects = m_snake->dropRemains();
				for (auto& obj : objects) {
					m_staticObjects.push_back(std::unique_ptr<Food>(new Food(obj)));
				}
			}

			object->resetTimer();
			draw();
		}
	}

}

void Map::catchInput(const sf::Keyboard::Key& k) {
	if (m_snake->isAlive()) {
		m_snake->keyPressed(k);
	}
}

bool Map::reflectSnake() {
	if (m_snake->nextHeadPos().x() < 0
	|| m_snake->nextHeadPos().x() >= m_width
	|| m_snake->nextHeadPos().y() < 0
	|| m_snake->nextHeadPos().y() >= m_height) {
		m_snake->die();
		return false;
	}

	return true;
}

Point Map::generateFoodPos() {
	bool noCollisions;
	Point foodPos;
	
	do {
		noCollisions = true;
		foodPos = m_rand.generatePoint(Point(0, 0), Point(m_width, m_height));
	
		for (auto& snakePart : m_snake->body()) {
			if (snakePart == foodPos) {
				noCollisions = false;
				break;
			}
		}

		for (auto& object : m_staticObjects) {
			if (object->pos == foodPos) {
				noCollisions = false;
				break;
			}
		}

	} while (noCollisions == false);

	return foodPos;
}

void Map::draw() const {
	if (!m_snake->isAlive()) {
		sf::RectangleShape rect(sf::Vector2f(DrawConfig::to_viewport_coord(m_width),
										DrawConfig::to_viewport_coord(m_height))
		);

		rect.setFillColor(sf::Color(255, 0, 0, 180));
		m_window.draw(rect);
	}

	m_food->draw(m_window);

	for (auto& object : m_staticObjects) {
		object->draw(m_window);
	}
	
	for (auto& object : m_dynamicObjects) {
		object->draw(m_window);
	}
	
	m_snake->draw(m_window);
}

