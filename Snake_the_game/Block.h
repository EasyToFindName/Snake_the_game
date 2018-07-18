#pragma once

#include "GameObject.h"

class Block : public GameObject {
public:
	explicit Block(BaseScene* mod, const sf::Vector2f& position = { 0.0f, 0.0f }, float angle = 0.0f);
	~Block();

	virtual void onCollision(const GameObject& gameObject) override;
	virtual GameObject* clone() override;

private:
	sf::Vector2i m_size;
};