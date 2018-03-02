#pragma once

#include "Game.h"
#include <SFML\System.hpp>
class Module {
public:
	Module(Game& game);
	virtual void run(const sf::Time& dt) = 0;
protected:
	void switchModule(std::unique_ptr<Module>& module);
private:
	Game& m_game;
};






