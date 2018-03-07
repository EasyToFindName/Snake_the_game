#pragma once

#include "RenderManager.h"

class GameManager {
public:

	GameManager(const GameManager&) = delete;
	void operator=(const GameManager&) = delete;
	static GameManager& getInstance();

	RenderManager* renderManager() const;

private:
	static GameManager m_instance;

	GameManager();
	~GameManager();


	RenderManager* m_renderManager;
};