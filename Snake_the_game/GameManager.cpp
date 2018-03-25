#include "GameManager.h"

GameManager GameManager::m_instance;

GameManager& GameManager::getInstance()
{
	return m_instance;
}

void GameManager::processInput(const sf::Keyboard::Key & key) {
	Module* activeModule = topModule();
	if (activeModule) {
		activeModule->processInput(key);
	}
}

void GameManager::run(const sf::Time & dt) {
	Module* activeModule = topModule();
	if (activeModule) {
		activeModule->run(dt);
	}
}

void GameManager::draw(sf::RenderTarget & target, sf::RenderStates states) {
	for (auto& mod : m_moduleStack) {
		mod->renderManager.draw(target, states);
	}
}

void GameManager::pushModule(std::unique_ptr<Module>&& mod) {
	m_moduleStack.push_back(std::move(mod));
}

void GameManager::popModule() {
	if (!m_moduleStack.empty()) {
		m_moduleStack.pop_back();
	}
}

void GameManager::switchModule(std::unique_ptr<Module>&& mod) {
	m_moduleStack.clear();
	m_moduleStack.push_back(std::move(mod));
}

Module * GameManager::topModule() {
	if(m_moduleStack.empty())
		return nullptr;

	return m_moduleStack.back().get();
}


GameManager::GameManager() {

}

GameManager::~GameManager()
{
}
