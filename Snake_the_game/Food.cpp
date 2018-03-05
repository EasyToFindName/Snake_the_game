#include "Food.h"
#include "Draw_config.h"

#include "CircularSaw.h"
#include "Snake.h"

Food::Food(const Point& p) : StaticObject(p) {

}

void Food::draw(sf::RenderWindow& window) const {
	sf::RectangleShape rect(sf::Vector2f(DrawConfig::SCALE, DrawConfig::SCALE));
	rect.setFillColor(DrawConfig::FOOD_COLOR);
	rect.setPosition(sf::Vector2f(DrawConfig::to_viewport_coord(pos.x()),
								  DrawConfig::to_viewport_coord(pos.y()))
					);

	window.draw(rect);
}

bool Food::affect(Snake& s) {
	if (s.nextHeadPos() == pos) {
		s.eat();
		pos = Point::NO_POINT;
		return true;
	}

	return false;
}

bool Food::affect(CircularSaw& saw) {
	if(saw.pos == this->pos) {
		pos = Point::NO_POINT;
		saw.changeDirection();
		return true;
	}
	return false;
}