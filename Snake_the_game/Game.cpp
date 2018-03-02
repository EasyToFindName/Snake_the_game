#include "Game.h"

Game::Game() {}

void Game::switchModule(std::unique_ptr<Module>& m) {
	m_selectedModule = std::move(m);
}