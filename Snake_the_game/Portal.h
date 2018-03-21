#pragma once

#include "StaticObject.h"
#include "DynamicObjects.h"
class Portal : public StaticObject {
public:
	Portal();
	Portal(const Point& p);

	//sets this exit point pointer to other portal
	//sets other's portal exit point pointer to this portal
	void connectWith(Portal& other);

	bool hasExit() const;


public: //Drawable implementation
	virtual void draw(sf::RenderWindow& w) const override;
public: //Reactor implementation
	virtual bool affect(Snake&) override;
	virtual bool affect(CircularSaw&) override;
	virtual bool affect(MovingFood& f) override;

private:
	Portal* m_exitPortal;
};

