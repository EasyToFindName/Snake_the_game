#pragma once
#include "GameObject.h"
#include "RandomGenerator.h"

class Apple : public GameObject
{
public:
	Apple(BaseScene* mod);
	~Apple();

	virtual void onCollision(const GameObject& gameObject) override;
	virtual GameObject* clone() override;

private:
	void changePosition();

private:
	sf::Vector2i m_size;
	RandomGenerator m_rand;
};