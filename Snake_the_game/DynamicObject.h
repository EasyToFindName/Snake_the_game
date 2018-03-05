#pragma once

#include "Timer.h"
#include "StaticObject.h"
class DynamicObject: 
	public StaticObject,
	public Movable,
	public Reactable,
	private Timer
{
public:
	DynamicObject(const Timer& period, const Point& p = Point::NO_POINT);

	void resetTimer();
	bool isTimerExpired();
	void makeTimerExpired();
	void updateTimer(const sf::Time& dt);
};

