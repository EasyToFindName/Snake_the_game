#include "DynamicObject.h"


DynamicObject::DynamicObject(const Timer& period, const Point& p) : Timer(period), StaticObject(p) {

}

void DynamicObject::updateTimer(const sf::Time& dt) {
	Timer::tick(dt);
}

void DynamicObject::resetTimer() {
	Timer::reset();
}

void DynamicObject::makeTimerExpired() {
	Timer::makeExpired();
}

bool DynamicObject::isTimerExpired() {
	return Timer::hasExpired();
}