#pragma once

#include "BaseScene.h"
#include <memory>


class GameManager {
public:

	GameManager(const GameManager&) = delete;
	void operator=(const GameManager&) = delete;
	static GameManager& getInstance();

	void processInput(const sf::Keyboard::Key& key);
	void run(const sf::Time& dt);
	void updatePhysics();
	void draw(sf::RenderTarget& target, sf::RenderStates states);

	void pushModule(std::unique_ptr<BaseScene>&& mod);
	void popModule();
	void switchModule(std::unique_ptr<BaseScene>&& mod);
	BaseScene* topModule();

private:
	static GameManager m_instance;
	std::vector<std::unique_ptr<BaseScene>> m_moduleStack;
	
	GameManager();
	~GameManager();


};

#define _GameManager GameManager::getInstance()