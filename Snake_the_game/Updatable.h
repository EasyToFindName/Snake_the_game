#pragma once
#include <SFML/System.hpp>

#include "Timer.h"

class Updatable {
public:
	Updatable(const sf::Time& period);
	virtual void update() = 0;

	void subscribeOn(Timer& t);
	void unsubscribe();
	void resetTimer();
	void shiftTime(const sf::Time& delta);

	sf::Time getTime() const;
private:
	sf::Time m_period;
	Timer* m_subscribedOn;
};

