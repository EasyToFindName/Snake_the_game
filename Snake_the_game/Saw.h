#pragma once
#include <vector>

#include "GameObject.h"

class Saw : public GameObject {
public:
	explicit Saw(BaseScene* mod, const sf::Vector2f& position = { 0.0f, 0.0f }, float angle = 0.0f);
	~Saw();

	virtual void run(float dt) override;
	virtual void onCollision(const GameObject& gameObject) override;
	virtual GameObject* clone() override;

private:
	sf::Vector2i m_size;
	std::vector<sf::Vector2f> positions;
};