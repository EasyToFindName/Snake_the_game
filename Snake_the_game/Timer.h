#pragma once

#include "Updatable.h"
#include <SFML/System.hpp>
#include <set>

class Updatable;
class Timer {
public:
	Timer();
	void tick(const sf::Time& deltaTime);

	void attach(Updatable*);
	void detach(Updatable*);
	void notify();
private:
	sf::Time m_timePassed;
	std::set<Updatable*> m_subscribers;
};

