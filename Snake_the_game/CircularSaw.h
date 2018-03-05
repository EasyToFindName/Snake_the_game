#pragma once

#include "Interfaces.h"
#include "DynamicObject.h"
#include "Direction.h"

class CircularSaw : public DynamicObject {
public:
	CircularSaw(const Point& from, const Point& to, const sf::Time& speed = sf::milliseconds(150));
	//changes direction to opposite
	void changeDirection();
public: //Movable implementation
	virtual bool move() override;
public: //Drawable implementation
	virtual void draw(sf::RenderWindow&) const override;
public: //Reactor impolementation
	virtual bool affect(Snake& s) override;
	virtual bool affect(CircularSaw&) override;
public: //Reactable implementation
	virtual bool reactOn(Reactor& r) override;
private:
	Point m_from;
	Point m_to;
	Direction m_direction;
};

