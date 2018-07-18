#pragma once
#include "GameObject.h"
#include "SnakeTail.h"


class SnakeHead : public GameObject
{
public:
	explicit SnakeHead(BaseScene* mod, const sf::Vector2f& position = { 0.0f, 0.0f }, float angle = 0.0f);
	~SnakeHead();

	void processKey(const sf::Keyboard::Key& key);

	virtual void run(float dt) override;
	virtual void onCollision(const GameObject& gameObject) override;
	virtual GameObject* clone() override;
	
	void move(float speed);
	void addTail(int count);

private:
	sf::Vector2i m_size;
	sf::Vector2f m_startPos;
	float m_speed, m_rotateSpeed, m_smoothFactor;

	sf::View m_camera;

	std::vector<SnakeTail*> m_tails;
};

