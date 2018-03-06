#pragma once

#include "StaticObject.h"
#include "Map.h"

class CircularSaw;

class Food : public StaticObject {
public:
	Food(const Point& p = Point::NO_POINT);

	virtual void postProcessing(Map& m) override;
public: //Drawable implementation
	virtual void draw(sf::RenderWindow& window) const override;
public: //Reactor implementation
	virtual bool affect(Snake&) override;
	virtual bool affect(CircularSaw&) override;
};

