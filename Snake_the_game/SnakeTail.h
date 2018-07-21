#pragma once
#include "GameObject.h"

class SnakeTail : public GameObject {
public:
	explicit SnakeTail(BaseScene* mod, const sf::Vector2f& position = { 0.0f, 0.0f }, float angle = 0.0f);
	~SnakeTail();

	virtual void onCollision(const GameObject& gameObject) override;
	virtual GameObject* clone() override;

	void setTarget(Transform* targte);

	void move(float speedDt, float rotateDt);

private:
	sf::Vector2i m_size;
	Transform* m_target;
};
