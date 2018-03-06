#include "LevelController.h"
#include "LevelObjects.h"
#include "DynamicObject.h"
#include "StaticObject.h"


LevelController::LevelController(Map& m) : m_map(m) 
{
	if(m_map.iterateSnakes().empty()) {
		throw std::logic_error("No snakes are presented on a map");
	}

	m_player = *m_map.iterateSnakes().begin();
}

void LevelController::run(const sf::Time& elapsed) {
	if(!m_player->isAlive()) {
		return;
	}

	for(auto& current : m_map.iterateDynamics()) {
		current->updateTimer(elapsed);

		if(current->isTimerExpired()) {
			current->move();
			current->resetTimer();

			for(auto& staticObj : m_map.iterateStatics()) {
				current->reactOn(*staticObj);
			}

			for(auto& tempObj : m_map.iterateTemporaries()) {
				current->reactOn(*tempObj);
			}	
			
			for(auto& other : m_map.iterateDynamics()) {
				current->reactOn(*other);
			}
		}
	}
}

void LevelController::catchInput(const sf::Keyboard::Key& key) {
	m_player->keyPressed(key);
}

void LevelController::draw() {
	m_map.draw();
}


