#include "CircularSaw.h"
#include "Draw_config.h"
#include "Snake.h"

#include <iostream>


CircularSaw::CircularSaw(const Point& from, const Point&to, const sf::Time& speed)
	: DynamicObject(speed, from),
	  m_from(from),
	  m_to(to),
	  m_direction(Direction::from(m_from, m_to))
{
	
}

Point CircularSaw::nextPos() const {
	Point p = m_direction.to_point();

	if (pos == m_to)
		p = p.reversed();

	return pos + p;
}

bool CircularSaw::move() {
	if(pos == m_to) {
		changeDirection();
	}

	m_path.insert(pos);
	pos += m_direction.to_point();

	return true;
}

void CircularSaw::draw(sf::RenderWindow& window) const {

	sf::RectangleShape rect(sf::Vector2f(DrawConfig::SCALE, DrawConfig::SCALE));
	rect.setFillColor(DrawConfig::SAW_PATH_COLOR);

	
	for(auto& temp : m_path) {
		rect.setPosition(sf::Vector2f(DrawConfig::to_viewport_coord(temp.x()),
									  DrawConfig::to_viewport_coord(temp.y())));

		window.draw(rect);
	}

	rect.setFillColor(DrawConfig::SAW_COLOR);
	rect.setPosition(sf::Vector2f(DrawConfig::to_viewport_coord(pos.x()),
								  DrawConfig::to_viewport_coord(pos.y()))
					);

	window.draw(rect);
}

bool CircularSaw::affect(Snake& s) {
	if(s.head() == pos || s.head() == nextPos()) {
		s.die();
		return true;
	}

	for(auto it = s.body().begin(); it != s.body().end(); ++it) {
		if(pos == *it) {
			s.dissect(it);
			return true;
		}
	}

	return false;
}

void CircularSaw::changeDirection() {
	std::swap(m_from, m_to);
	m_direction = Direction::from(m_from, m_to);
}

bool CircularSaw::affect(CircularSaw& s) {
	if(&s != this) {
		if(s.pos == this->nextPos() || s.pos == this->pos) {
			this->changeDirection();
			s.changeDirection();
		}
	}

	return false;
}

bool CircularSaw::affect(MovingFood & f) {
	return f.affect(*this);
}

bool CircularSaw::reactOn(Reactor& r) {
	return r.affect(*this);
}