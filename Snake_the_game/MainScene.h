#pragma once

#include "BaseScene.h"
#include "GameObject.h"

#include "SnakeHead.h"

class MainScene : public BaseScene {
public:
	MainScene(sf::RenderWindow& window);
	virtual ~MainScene();
	virtual void processInput(const sf::Keyboard::Key& key) override;
	virtual void run(const sf::Time& dt) override;

	
private:
	SnakeHead* m_snakeHead;
};

