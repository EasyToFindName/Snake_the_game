#pragma once

#include "StaticObject.h"
class CircularSaw;

class Food : public StaticObject {
public:
	Food(const Point& p = Point::NO_POINT);
public: //Drawable implementation
	virtual void draw(sf::RenderWindow& window) const override;
public: //Reactor implementation
	virtual bool affect(Snake&) override;
	virtual bool affect(CircularSaw&) override;
};

