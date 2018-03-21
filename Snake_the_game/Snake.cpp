#include "Snake.h"
#include "CircularSaw.h"
#include "Food.h"
#include "Map.h"

#include "Draw_config.h"

Snake::Snake(const Point& startPoint, const Direction::Dir startDir, int size, const sf::Time& t)
			 :m_dir(startDir),
			  m_isAlive(true),
			  DynamicObject(t, startPoint)			 
{
	for (int i = 0; i < size; ++i) {
		m_body.push_back(startPoint + m_dir.to_point().reversed() * i);
	}

	m_tail = startPoint + m_dir.to_point().reversed() * size;
}

bool Snake::changeDir(const Direction& d) {
	//change only if new direction is not opposite to current
	if ((m_dir.to_point() + d.to_point()) != Point(0, 0)) {
		m_dir = d;
		return true;
	}
	return false;
}

bool Snake::eat() {
	if (m_tail != Point::NO_POINT) {
		m_body.push_back(m_tail);
		m_tail = Point::NO_POINT;
		return true;
	}
	return false;
}

void Snake::die() {
	m_isAlive = false;
}

bool Snake::isAlive() const {
	return m_isAlive;
}

Point Snake::nextHeadPos() const {
	return m_body.front() + m_dir.to_point();
}

Point Snake::head() const {
	return m_body.front();
}

bool Snake::checkSelfCollision() const {
	auto head = nextHeadPos();
	
	for (auto iter = ++m_body.begin(); iter != m_body.end(); ++iter) {
		if (*iter == head)
			return true;
	}

	return false;
}

void Snake::dissect(SnakeBody::const_iterator& position) {
	SnakeBody remains;

	if (position == m_body.begin()) {
		die();
	}
	//dissection goes here
	remains.splice(remains.begin(), m_body, position, m_body.end());
	
	//removing block at dissection point
	if (!remains.empty()) {
		remains.pop_front();
	}

	m_remains = remains;
}

bool Snake::affect(Snake& s) {
	if(&s != this) {
		for(auto it = s.body().begin(); it != s.body().end(); ++it) {
			if(*it == this->nextHeadPos()) {
				s.dissect(it);
				return true;
			}
		}
	}

	return false;
}

bool Snake::affect(CircularSaw& saw) {
	return saw.affect(*this);
}

bool Snake::affect(MovingFood & f) {
	return f.affect(*this);
}

bool Snake::move() {
	if (checkSelfCollision() == false) {
		m_body.push_front(m_body.front() + m_dir.to_point());
		m_tail = m_body.back();
		m_body.pop_back();
		pos = head();
		

		return true;
	}
	die();
	return false;
}

const std::list<Point>& Snake::body() const {
	return m_body;
}

void Snake::draw(sf::RenderWindow& window) const {
	sf::RectangleShape baseRect(sf::Vector2f(DrawConfig::SCALE, DrawConfig::SCALE));
	baseRect.setFillColor(DrawConfig::SNAKE_COLOR);

	for (const auto &i : m_body) {
		baseRect.setPosition(sf::Vector2f(DrawConfig::to_viewport_coord(i.x()),
										  DrawConfig::to_viewport_coord(i.y()))
							);

		window.draw(baseRect);
	}
}

void Snake::setHeadX(int x) {
	m_body.front().x(x);
}

void Snake::setHeadY(int y) {
	m_body.front().y(y);
}

bool Snake::isChopped() const {
	return !m_remains.empty();
}

Snake::SnakeBody Snake::dropRemains() {
	SnakeBody temp;
	std::swap(temp, m_remains);
	return temp;
}

bool Snake::keyPressed(const sf::Keyboard::Key& key) {
	switch (key) {
		case sf::Keyboard::W:
		case sf::Keyboard::Up:
			if(changeDir(Direction::UP)) {
				makeTimerExpired();
				return true;
			}
		break;

		case sf::Keyboard::S:
		case sf::Keyboard::Down:
			if(changeDir(Direction::DOWN)) {
				makeTimerExpired();
				return true;
			}
		break;
		
		case sf::Keyboard::D:
		case sf::Keyboard::Right:
			if(changeDir(Direction::RIGHT)) {
				makeTimerExpired();
				return true;
			}
		break;

		case sf::Keyboard::A:
		case sf::Keyboard::Left:
			if(changeDir(Direction::LEFT)) {
				makeTimerExpired();
				return true;
			}
		break;

		case sf::Keyboard::Space:
			m_isAlive = true;
			for(int i = 0; i < 5 && m_body.size() < 5; ++i) {
				m_body.push_back(head() + m_dir.to_point().reversed() * i);
			}
			return true;
		break;
		default:
			return false;
	}
}

void Snake::postProcessing(Map& m) {
	
	if(isChopped()) {
		auto remains = dropRemains();

		for(auto& block : remains) {
			m.addTempObj(std::unique_ptr<Food>(new Food(block)));
		}
	}
}

bool Snake::reactOn(Reactor& r) {
	return r.affect(*this);
}

