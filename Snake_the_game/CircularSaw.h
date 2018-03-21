#pragma once

#include "Interfaces.h"
#include "DynamicObject.h"
#include "DynamicObjects.h"
#include "Direction.h"
#include <set>

class CircularSaw : public DynamicObject {
public:
	CircularSaw(const Point& from, const Point& to, const sf::Time& speed = sf::milliseconds(150));
	//changes direction to opposite
	void changeDirection();
	Point nextPos() const;
public: //Movable implementation
	virtual bool move() override;
public: //Drawable implementation
	virtual void draw(sf::RenderWindow&) const override;
public: //Reactor impolementation
	virtual bool affect(Snake& s) override;
	virtual bool affect(CircularSaw&) override;	
	virtual bool affect(MovingFood& f) override;
public: //Reactable implementation
	virtual bool reactOn(Reactor& r) override;
private:
	Point m_from;
	Point m_to;
	Direction m_direction;
	std::set<Point> m_path;
};

