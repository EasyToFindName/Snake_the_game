#include "GameManager.h"

GameManager GameManager::m_instance;

GameManager& GameManager::getInstance()
{
	return m_instance;
}

RenderManager * GameManager::renderManager() const
{
	return m_renderManager;
}

GameManager::GameManager() {
	m_renderManager = new RenderManager();
}

GameManager::~GameManager()
{
}
