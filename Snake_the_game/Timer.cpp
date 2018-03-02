#include "Timer.h"

Timer::Timer() : m_timePassed(sf::Time::Zero) {

}

void Timer::tick(const sf::Time& deltaTime) {
	m_timePassed += deltaTime;
	notify();
}

void Timer::attach(Updatable* obj) {
	m_subscribers.insert(obj);
}

void Timer::detach(Updatable* obj) {
	m_subscribers.erase(obj);
}

void Timer::notify() {
	for (auto& obj : m_subscribers) {
		if(obj->getTime() < m_timePassed) {
			obj->update();
			obj->shiftTime(m_timePassed);
		}
	}
}

