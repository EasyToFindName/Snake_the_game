#pragma once

#include "Timer.h"
#include "StaticObject.h"
class DynamicObject: 
	public StaticObject,
	public Movable,
	public Timer
{
public:
	DynamicObject(const Timer& period, const Point& p = Point::NO_POINT);
};

