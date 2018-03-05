#include "Timer.h"

Timer::Timer(const sf::Time & period) : m_period(period), m_timePassed(sf::Time::Zero) {
	
}

void Timer::tick(const sf::Time& dt) {
	m_timePassed += dt;
}

void Timer::reset() {
	m_timePassed = sf::Time::Zero;
}

bool Timer::hasExpired() const {
	return m_timePassed >= m_period;
}

void Timer::makeExpired() {
	m_timePassed = m_period;
}
