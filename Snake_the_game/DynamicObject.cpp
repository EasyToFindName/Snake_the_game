#include "DynamicObject.h"


DynamicObject::DynamicObject(const Timer& period, const Point& p) : m_timer(period), StaticObject(p) {

}

void DynamicObject::updateTimer(const sf::Time& dt) {
	m_timer.tick(dt);
}

void DynamicObject::resetTimer() {
	m_timer.reset();
}

void DynamicObject::makeTimerExpired() {
	m_timer.makeExpired();
}

bool DynamicObject::isTimerExpired() {
	return m_timer.hasExpired();
}