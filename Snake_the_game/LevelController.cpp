#include "LevelController.h"
#include "LevelObjects.h"
#include "DynamicObject.h"
#include "StaticObject.h"

LevelController::LevelController(Map& m) : m_map(m) 
{
	
}

void LevelController::run(const sf::Time& elapsed) {
	for(auto current = m_map.iterateDynamics().begin(); current != m_map.iterateDynamics.end(); ++current) {
		(*current)->updateTimer(elapsed);

		if((*current)->isTimerExpired()) {
			for(auto& staticObj : m_map.iterateStatics()) {
				(*current)->reactOn(*staticObj);
			}

			for(auto& tempObj : m_map.iterateTemporaries()) {
				(*current)->reactOn(*tempObj);
			}

			for(auto other = current + 1; other != m_map.iterateDynamics.end(); ++other) {
				(*current)->move();
			}
		}
	}
}

void LevelController::catchInput(const sf::Keyboard::Key& key) {
	Snake* player = **m_map.iterateSnakes.begin();
	player->keyPressed(key);
}

void LevelController::draw() {
	m_map.draw();
}


