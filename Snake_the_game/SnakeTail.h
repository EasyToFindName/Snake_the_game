#pragma once
#include "GameObject.h"

class SnakeTail : public GameObject {
public:
	SnakeTail(Module* mod);
	~SnakeTail();

	virtual void onCollision(const GameObject& gameObject) override;
	virtual GameObject* clone() override;

	void setTarget(Transform* targte);

	void move(float speedDt, float rotateDt);

private:
	sf::Vector2i m_size;
	Transform* m_target;
};
