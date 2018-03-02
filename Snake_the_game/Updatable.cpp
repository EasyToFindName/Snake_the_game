#include "Updatable.h"

Updatable::Updatable(const sf::Time & period) : m_period(period), m_subscribedOn(nullptr) {
		
}

void Updatable::subscribeOn(Timer& t) {
	unsubscribe();
	m_subscribedOn = &t;
	t.attach(this);
}

void Updatable::unsubscribe() {
	if(m_subscribedOn != nullptr)
		m_subscribedOn->detach(this);
	
	m_subscribedOn = nullptr;
}

void Updatable::shiftTime(const sf::Time& delta) {
	m_period += delta;
}

sf::Time Updatable::getTime() const {
	return m_period;
}

void Updatable::resetTimer() {
	m_period = sf::Time::Zero;
}

