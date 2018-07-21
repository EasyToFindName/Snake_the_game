#pragma once
#include "GameObject.h"
#include "RandomGenerator.h"

class Apple : public GameObject
{
public:
	explicit Apple(BaseScene* mod, const sf::Vector2f& position = { 0.0f, 0.0f }, float angle = 0.0f);
	~Apple();

	virtual void onCollision(const GameObject& gameObject) override;
	virtual GameObject* clone() override;

private:
	void changePosition();

private:
	sf::Vector2i m_size;
	RandomGenerator m_rand;
};