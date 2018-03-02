#include "Module.h"


Module::Module(Game& g) : m_game(g) {

}

void Module::switchModule(std::unique_ptr<Module>& module) {
	m_game.switchModule(module);
}

