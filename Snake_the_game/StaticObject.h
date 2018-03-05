#pragma once
#include "Interfaces.h"
#include "Point.h"

//abstract class of an object placed on a game grid
class Map;
class StaticObject:
	public Drawable,
	public Reactor
{
public:
	StaticObject();
	StaticObject(const Point& p);

	
	//this should be called after "game turn" if
	//there is a need to update a map somehow
	//(regenerate food position, make food from dissected part of the snake etc)
	virtual void postProcessing(Map& m) {}

	Point pos;

	const unsigned DRAW_PRIORITY;
};

