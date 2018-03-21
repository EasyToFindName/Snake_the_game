#include "MovingFood.h"
#include "Draw_config.h"
#include "DynamicObjects.h"

MovingFood::MovingFood(const Point& startPos, const sf::Time& timer) : DynamicObject(timer, startPos), m_dir(Direction::LEFT) {

}

MovingFood::MovingFood(const MovingFood& other) : DynamicObject(other.m_timer, other.pos), m_dir(other.m_dir) {

}

bool MovingFood::move() {
	m_dir = genRandomDir();
	pos += m_dir.to_point();
	return true;
}

void MovingFood::draw(sf::RenderWindow& window) const {
	sf::RectangleShape rect(sf::Vector2f(DrawConfig::SCALE, DrawConfig::SCALE));
	rect.setFillColor(DrawConfig::FOOD_COLOR);
	rect.setPosition(sf::Vector2f(DrawConfig::to_viewport_coord(pos.x()),
		DrawConfig::to_viewport_coord(pos.y()))
	);

	window.draw(rect);
}

bool MovingFood::affect(Snake& s) {
	if (s.head() == pos) {
		s.eat();
		pos = Point::NO_POINT;
		return true;
	}
	return false;
}

bool MovingFood::affect(CircularSaw& s) {
	if (s.pos == pos) {
		pos = Point::NO_POINT;
		s.changeDirection();
		return true;
	}
	return false;
}

bool MovingFood::affect(MovingFood & f) {
	return false;
}

bool MovingFood::reactOn(Reactor& r) {
	return r.affect(*this);
}

Direction MovingFood::genRandomDir() const {
	int r = m_rand.generateInt(4);

	if (r == 0) {
		return Direction::LEFT;
	}
	else if (r == 1) {
		return Direction::RIGHT;
	}
	else if (r == 2) {
		return Direction::UP;
	}
	else if (r == 3) {
		return Direction::DOWN;
	}
	else {
		return Direction::LEFT;
	}
}

Point MovingFood::nextPos() const {
	return m_dir.to_point() + pos;
}

void MovingFood::changeDirection() {
	m_dir = Direction::from(nextPos(), pos);
}

void MovingFood::postProcessing(Map& m) {
	if(pos == Point::NO_POINT)
		pos = m.generateStaticPos();
}

MovingFood::~MovingFood() {}
