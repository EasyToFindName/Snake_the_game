#pragma once

#include <SFML/System.hpp>

class Timer {
public:
	Timer(const sf::Time& period);
	
	//adds dt to timePassed
	void tick(const sf::Time& dt);
	
	//timePassed = 0
	void reset();

	//returns true if timePassed > period
	bool hasExpired() const;

	//timePassed = period;
	void makeExpired();
private:
	sf::Time m_period;
	sf::Time m_timePassed;
};